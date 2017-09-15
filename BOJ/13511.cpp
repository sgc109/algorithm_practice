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

ll dist[100003];
vector<pair<int,ll> > G[100003];
int par[100003][18];
int dep[100003];
void dfs(int cur, int dad){
	for(int i = 0 ; par[cur][i] != -1; i++) par[cur][i + 1] = par[par[cur][i]][i];
	for(auto p : G[cur]){
		int nxt = p.first;
		int cst = p.second;
		if(nxt == dad) continue;
		par[nxt][0] = cur;
		dep[nxt] = dep[cur] + 1;
		dist[nxt] = dist[cur] + cst;
		dfs(nxt, cur);
	}
}
int lca(int a, int b){
	if(dep[a] < dep[b]) swap(a, b);
	for(int i = 17; i >= 0; i--){
		if(dep[a] - dep[b] >= 1 << i) a = par[a][i];
	}
	if(a == b) return a;
	for(int i = 17; i >= 0; i--){
		if(par[a][i] != par[b][i]) {
			a = par[a][i], b = par[b][i];
		}
	}
	return par[a][0];
}
int N, M, o, u, v, k, a, b, c;
int main() {
	fastio();
	int root = 0;
	memset(par,-1,sizeof(par));
	cin >> N;
	for(int i = 0 ; i < N - 1; i++){
		cin >> a >> b >> c;
		a--, b--;
		G[a].pb({b, c});
		G[b].pb({a, c});
	}
	dep[root] = 0;
	dfs(root, -1);	
	cin >> M;
	for(int i = 0 ; i < M; i++){
		cin >> o >> u >> v;
		u--, v--;
		if(o == 1){
			cout << dist[u] + dist[v] - 2 * dist[lca(u, v)] << '\n';
		}
		else {
			cin >> k;
			k--;
			int l = lca(u, v);
			if(l == u || l == v){
				if(dep[u] < dep[v]) {
					k = dep[v] - dep[u] - k;
					swap(u, v);
				}
			}
			else {
				int diff = dep[u] - dep[lca(u, v)];
				if(diff < k){
					k = dep[v] - dep[lca(u, v)] - (k - diff);
					swap(u, v);
				}
			}
			for(int i = 17; i >= 0; i--){
				if(k >> i & 1) u = par[u][i];
			}
			cout << u + 1 << '\n';
		}
	}
	return 0;
}