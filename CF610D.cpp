// #include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <cstring>
#include <algirhtm>
#include <set>
#include <utility>
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
	ll x1, y1, x2, y2;
};
int N;
ll tcnt[800003], tlen[800003];
ll L[800003], R[800003];
set<ll> stY;
vector<ll> vY;
void init(int nl, int nr, int node){
	L[node] = vY[nl], R[node] = vY[nr];
	if(nl == nr) return;
	int nm = (nl + nr) / 2;
	init(nl, nm, 2 * node);
	init(nm + 1, nr, 2 * node + 1);
}
void update(ll s, ll e, int nl, int nr, int node, int val){
	if(s <= L[node] && R[node] <= e){
		tcnt[node] += val;
		if(tcnt[node]) tlen[node] = R[node] - L[node] + 1;
		else tlen[node] = (nl == nr ? 0 : tlen[2 * node] + tlen[2 * node + 1]);
		return;	
	}
	if(e < L[node] || R[node] < s) return;
	int nm = (nl + nr) / 2;
	update(s, e, nl, nm, 2 * node, val);
	update(s, e, nm + 1, nr, 2 * node + 1, val);
	tlen[node] = tlen[2 * node] + tlen[2 * node + 1];
	if(tcnt[node]) tlen[node] = R[node] - L[node] + 1;
	// printf("L : %lld, R : %lld\n", L[node], R[node]);
	// printf("[%d, %d] node : %d, tlen : %lld, tcnt : %lld\n", nl, nr, node, tlen[node], tcnt[node]);
}
ll query(ll s, ll e, int nl, int nr, int node){
	if(s <= L[node] && R[node] <= e) return tlen[node];
	if(e < L[node] || R[node] < s) return 0;
	int nm = (nl + nr) / 2;
	ll resL = query(s, e, nl, nm, 2 * node);
	ll resR = query(s, e, nm + 1, nr, 2 * node + 1);
	return resL + resR;
}
rect rects[100003];
vector<pair<ll,int> > v;
int main() {
	fastio();
	cin >> N;
	for(int i = 1 ; i <= N; i++){
		ll x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		if(x1 > x2) swap(x1, x2);
		if(y1 > y2) swap(y1, y2);
		rects[i] = {x1, y1, x2, y2};
		stY.insert(y1);
		stY.insert(y2);
		v.pb({x1, -i});
		v.pb({x2 + 1, i});
	}
	vY.assign(all(stY));
	init(0, sz(vY) - 1, 1);
	sort(all(v));
	ll prv = -1;
	ll ans = 0;
	for(auto p : v){
		int id = p.second;
		int isEnd = id > 0;
		id = abs(id);
		ans += (p.first - prv) * tlen[1];
		printf("ans : %d\n", ans);
		if(isEnd){
			update(rects[id].y1, rects[id].y2, 0, sz(vY) - 1, 1, -1);
		}
		else {
			update(rects[id].y1, rects[id].y2, 0, sz(vY) - 1, 1, 1);
		}
		prv = p.first;
	}
	cout << ans;
	return 0;
}