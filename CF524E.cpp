#include <bits/stdc++.h>
#define pb push_back
#define sz(v) ((int)(v).size())
#define all(v) (v).begin(), (v).end()
#define fastio() ios_base::sync_with_stdio(false),cin.tie(NULL)
using namespace std;
typedef long long ll;
const int mod = 1e9+7;
const int inf = 0x3c3c3c3c;
const long long infl = 0x3c3c3c3c3c3c3c3c;

struct point{
	int x, y;
};
struct rect{
	point p1, p2;
};
point rooks[200003];
rect rects[200003];
int t[400003];
int N, M, K, Q, size;
vector<pair<int, int> > v;
int ans[200003];
void update(int pos, int v){
	for(t[pos += size] = v; pos > 1; pos /= 2){
		t[pos / 2] = min(t[pos], t[pos ^ 1]);
	}
}
int query(int l, int r){
	int ret = inf;
	for(l += size, r += size; l <= r; l /= 2, r /= 2){
		if(l & 1) ret = min(ret, t[l++]);
		if(~r & 1) ret = min(ret, t[r--]);
	}
	return ret;
}
int main() {
	fastio();
	for(size = 1; size <= 100000; size *= 2);
	cin >> N >> M >> K >> Q;
	for(int i = 1 ; i <= K; i++){
		int x, y;
		cin >> x >> y;
		rooks[i] = {x, y};
	}
	for(int i = 1; i <= Q; i++){
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		rects[i] = {point{x1, y1}, point{x2, y2}};
	}
	for(int k = 0 ; k < 2; k++){
		memset(t,0,sizeof(t));
		v.clear();
		for(int i = 1; i <= K; i++){
			v.pb({rooks[i].x, -i});
		}
		for(int i = 1; i <= Q; i++){
			v.pb({rects[i].p2.x, i});
		}
		sort(all(v));
		for(auto p : v){
			int id = p.second;
			int isRook = id < 0;
			id = abs(id);
			if(isRook){
				update(rooks[id].y, rooks[id].x);
			}
			else {
				int ret = query(rects[id].p1.y, rects[id].p2.y);
				if(rects[id].p1.x <= ret) ans[id] = 1;
			}
		}
		for(int i = 1; i <= K; i++) {
			swap(rooks[i].x, rooks[i].y);
		}
		for(int i = 1; i <= Q; i++){
			swap(rects[i].p1.x, rects[i].p1.y);
			swap(rects[i].p2.x, rects[i].p2.y);
		}
	}

	for(int i = 1; i <= Q; i++){
		cout << (ans[i] ? "YES" : "NO") << '\n';
	}
	return 0;
}