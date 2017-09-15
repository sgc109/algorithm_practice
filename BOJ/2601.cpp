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

struct rect{
	int x1, y1, x2, y2;
};
rect rects[100003];
int lazy[4000003];
int tree[4000003];
int N, L, cnt;
void update(int s, int e, int nl, int nr, int nd, int val){
	if(s <= nl && nr <= e) lazy[nd] += val;
	if(lazy[nd]){
		tree[nd] += lazy[nd];
		if(nl != nr) lazy[2 * nd] += lazy[nd], lazy[2 * nd + 1] += lazy[nd]; 
		lazy[nd] = 0;
	}
	if(nr < s || e < nl) return;
	if(s <= nl && nr <= e) return;
	int nm = (nl + nr) / 2;
	update(s, e, nl, nm, 2 * nd, val);
	update(s, e, nm + 1, nr, 2 * nd + 1, val);
	tree[nd] = max(tree[2 * nd], tree[2 * nd + 1]);
}
int main() {
	fastio();
	cin >> N >> N >> N >> N;
	cin >> L >> N;
	for(int i = 0 ; i < N; i++){
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		if(x1 > x2) swap(x1, x2);
		if(y1 > y2) swap(y1, y2);
		if(y2 - y1 > L || x2 - x1 > L) continue;
		rects[cnt++] = rect{x2, y2, x1 + L, y1 + L};
	}
	N = cnt;
	vector<pair<int,int> > v;
	for(int i = 0 ; i < N; i++){
		v.emplace_back(rects[i].x1, -(i + 1));
		v.emplace_back(rects[i].x2, i + 1);
	}
	sort(all(v));
	int ans = 0;
	for(auto p : v){
		int cur = p.first;
		int id = p.second;
		int isEnd = id > 0;
		id = abs(id);
		auto r = rects[id - 1];
		if(isEnd) update(r.y1, r.y2, 0, 1e6, 1, -1);
		else {
			update(r.y1, r.y2, 0, 1e6, 1, 1);
			ans = max(ans, tree[1]);
		}
	}
	cout << ans;
	return 0;
}