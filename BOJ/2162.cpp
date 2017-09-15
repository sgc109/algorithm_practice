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
	int cross(point rhs){
		return x * rhs.y - y * rhs.x;
	}
	point operator-(const point& rhs) const{
		return point{x - rhs.x, y - rhs.y};
	}
	bool operator<(const point& rhs) const{
		if(x != rhs.x) return x < rhs.x;
		return y < rhs.y;
	}
};
struct line{
	point p1, p2;
};
int N;
int par[3003];
line lines[3003];
int size[3003];
int find(int u){
	return par[u] == u ? u : par[u] = find(par[u]);
}
void merge(int a, int b){
	a = find(a), b = find(b);
	if(a == b) return;
	size[b] += size[a];
	par[a] = b;
}
int ccw(point& a, point& b, point& c){
	int tmp = (a - c).cross(b - c);
	if(!tmp) return 0;
	tmp /= abs(tmp);
	return tmp;
}
int isOver(line l1, line l2){
	int ab = ccw(l1.p1, l1.p2, l2.p1) * ccw(l1.p1, l1.p2, l2.p2);
	int cd = ccw(l2.p1, l2.p2, l1.p1) * ccw(l2.p1, l2.p2, l1.p2);
	if(ab == 0 && cd == 0) {
		return !(l1.p2 < l2.p1 || l2.p2 < l1.p1);
	}
	return ab <= 0 && cd <= 0;
}
int isOver(line l1, line l2){
	if(!ccw(l2.p1, l1.p2, l1.p1) && !ccw(l1.p2, l2.p2, l1.p1)){ // 일직선상
		if(l2.p1 < l1.p1) swap(l1, l2);
		if(l1.p2 < l2.p1) return false;
		return true; 
	}
	int cond1 = ccw(l2.p1, l1.p2, l1.p1) * ccw(l1.p2, l2.p2, l1.p1) >= 0;
	int cond2 = ccw(l1.p1, l2.p1, l2.p2) * ccw(l2.p1, l1.p2, l2.p2) >= 0;
	return cond1 && cond2;
}
int main() {
	fastio();
	cin >> N;
	for(int i = 0 ; i < N; i++) par[i] = i, size[i] = 1;
	for(int i = 0 ; i < N; i++){
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		lines[i] = line{point{x1, y1}, point{x2, y2}};
		if(lines[i].p2 < lines[i].p1) swap(lines[i].p1, lines[i].p2);
	}
	for(int i = 0 ; i < N; i++){
		for(int j = i + 1; j < N; j++){
			if(isOver(lines[i], lines[j])) {
				merge(i, j);
			}
		}
	}
	int ans1 = 0, ans2 = 0;
	for(int i = 0 ; i < N; i++) {
		if(par[i] == i) {
			ans1++;
			ans2 = max(ans2, size[i]);
		}
	}
	cout << ans1 << '\n' << ans2;
	return 0;
}