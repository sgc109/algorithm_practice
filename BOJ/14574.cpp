#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod = 1e9+7;
const int inf = 0x3c3c3c3c;
const long long infl = 0x3c3c3c3c3c3c3c3c;

ll P[1003],C[1003];
int par[1003];
int N;
vector<int> G[1003];

int find(int u){
	return par[u] == u ? u : par[u] = find(par[u]);
}
int merge(int u, int v){
	u = find(u), v = find(v);
	if(u == v) return 0;
	par[u] = v;
	return v;
}

void dfs(int here, int dad){
	for(int there : G[here]){
		if(there == dad) continue;
		dfs(there,here);
	}
	if(dad != -1) cout << dad << ' ' << here << endl;
}

int main() {
	cin >> N;
	for(int i = 1 ; i <= N ; i++) par[i] = i;
	for(int i = 1; i <= N; i++) cin >> P[i] >> C[i];

	vector<pair<ll,pair<int,int> > > v;
	for(int i = 1 ; i < N; i++) {
		for(int j = i+1; j <= N; j++){
			v.push_back({-(C[i]+C[j])/abs(P[i]-P[j]),{i,j}});
		}
	}
	sort(v.begin(),v.end());
	ll ans = 0;
	for(int i = 0 ; i < v.size(); i++){
		int a = v[i].second.first;
		int b = v[i].second.second;

		if(!merge(a,b)) continue;
		G[a].push_back(b), G[b].push_back(a);
		ans += -v[i].first;
	}
	cout << ans << endl;
	dfs(1,-1);
	return 0;
}
