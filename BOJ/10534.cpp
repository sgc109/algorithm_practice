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
	ll x, y, w, h;
};
rect rects[50003];
int par[50003];
ll sum[50003];
int find(int u){
	return par[u] == u ? u : par[u] = find(par[u]);
}
void merge(int a, int b){
	a = find(a), b = find(b);
	if(a == b) return;
	par[a] = b;
	sum[b] += sum[a];
}
int N;
vector<pair<ll, int> > v;
set<pair<ll, int> > stUp, stDwn;
int main() {
	fastio();
	cin >> N;
	for(int i = 1 ; i <= N; i++){
		ll x, y, w, h;
		cin >> x >> y >> w >> h;
		rects[i] = {x, y, w, h};
	}
	for(int i = 1 ; i <= N; i++) par[i] = i, sum[i] = rects[i].w * rects[i].h;
	for(int k = 0 ; k < 2; k++){
		for(int i = 1 ; i <= N; i++){
			auto r = rects[i];
			v.pb({r.x, -i});
			v.pb({r.x + r.w, i});
		}
		sort(all(v));
		for(auto p : v){
			int id = p.second;
			int isEnd = id > 0;
			id = abs(id);
			auto r = rects[id];
			if(!isEnd){
				stUp.insert({r.y + r.h, id});
				stDwn.insert({r.y, id});
			}
			else {
				auto itDwn = stDwn.lower_bound({r.y + r.h, 0});
				if(itDwn != stDwn.end() && (*itDwn).first == r.y + r.h) merge(id, (*itDwn).second);
				auto itUp = stUp.lower_bound({r.y, 0});
				if(itUp != stUp.end() && (*itUp).first == r.y) merge(id, (*itUp).second);

				itDwn = stDwn.lower_bound({r.y, 0});
				if(itDwn != stDwn.end() && (*itDwn).first == r.y) merge(id, (*itDwn).second);
				itUp = stUp.lower_bound({r.y + r.h, 0});
				if(itUp != stUp.end() && (*itUp).first == r.y + r.h) merge(id, (*itUp).second);

				stUp.erase({r.y + r.h, id});
				stDwn.erase({r.y, id});	
			}
		}
		v.clear();
		for(int i = 1 ; i <= N; i++) swap(rects[i].x, rects[i].y), swap(rects[i].h, rects[i].w);
	}
	ll ans = 0;
	for(int i = 1 ; i <= N; i++) if(par[i] == i) ans = max(ans, sum[i]);
	
	cout << ans;
	return 0;
}