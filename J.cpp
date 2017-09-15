#include <bits/stdc++.h>
#define pb push_back
#define sz(v) ((int)(v).size())
#define all(v) (v).begin(), (v).end()
#define fastio() ios::sync_with_stdio(0),cin.tie(0)
using namespace std;
typedef long long ll;
const int mod = 1e9+7;
const int inf = 0x3c3c3c3c;
const ll infl = 0x3c3c3c3c3c3c3c3c;

int T, N, a, b, c;
vector<pair<int,ll> > G[500003];
ll dist[500003];
ll gas[500003];
int upd[500003];
int ans[500003];
void dfs(int cur, int dad, vector<int>& pars, ll rest){
	pars.pb(cur);
	int lo = 0, hi = sz(pars);
	while(lo < hi){
		int mid = lo + hi >> 1;
		if(rest <= dist[cur] - dist[pars[mid]]) hi = mid;
		else lo = mid + 1;
	}
	if(lo == sz(pars) || dist[lo] != rest) lo--;
	upd[pars[lo]]++, upd[cur]--, printf("cur : %d, upd : %d\n", cur, pars[lo]);
	for(auto p : G[cur]){
		int nxt = p.first;
		if(nxt == dad) continue;
		ll d = p.second;
		dist[nxt] = dist[cur] + d;
		dfs(nxt, cur, pars, rest + gas[cur]);1
	}
	pars.pop_back();
}
void solve(int cur, int dad, int acc){
	acc += upd[cur];
	// printf("cur : %d, acc : %d\n", cur, acc);
	for(auto p : G[cur]){
		int nxt = p.first;
		if(nxt == dad) continue;
		solve(nxt, cur, acc);
	}
}
int main() {
	// fastio();
	cin >> T;
	while(T--){
		for(int i = 0 ; i < 500003; i++) G[i].clear();
		cin >> N;
		for(int i = 0 ; i < N; i++) cin >> gas[i];
		for(int i = 0 ; i < N - 1; i++) {
			cin >> a >> b >> c;
			a--, b--;
			G[a].pb({b, c});
			G[b].pb({a, c});
		}
		vector<int> pars;
		dfs(0, -1, pars, 0);
		solve(0, -1, 0);
	}

	return 0;
}