#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod = 1e9+7;
const int inf = 0x3c3c3c3c;
const long long infl = 0x3c3c3c3c3c3c3c3c;

int N,M,S,P;
vector<int> adj[500003], radj[500003], G[500003];
ll arr[500003], cash[500003];
int check[500003], isATM[500003];
ll dp[500003];
map<pair<int,int>, int> mp;
vector<int> stck;
int visited[500003];
int sccId[500003];
int sccCnt;
void dfs1(int here){
	if(visited[here]) return;
	visited[here] = 1;
	for(int there : adj[here]) dfs1(there);
	stck.push_back(here);
}
void dfs2(int here){
	sccId[here] = sccCnt;
	for(int there : radj[here]){
		if(sccId[there] != -1) continue;
		dfs2(there);
	}
}
int main() {
	memset(dp,0xcc,sizeof(dp));
	memset(sccId,-1,sizeof(sccId));
	cin >> N >> M;
	for(int i = 0 ; i < M; i++){
		int a,b;
		cin >> a >> b;
		adj[a].push_back(b);
		radj[b].push_back(a);
	}
	for(int i = 1 ; i <= N; i++) cin >> arr[i];
	cin >> S >> P;
	for(int i = 0 ; i < P; i++) {
		int a;
		cin >> a;
		check[a] = 1;
	}
	for(int i = 1 ; i <= N; i++) dfs1(i);
	while(!stck.empty()){
		int here = stck.back();
		stck.pop_back();
		if(sccId[here] != -1) continue; 
		dfs2(here);
		sccCnt++;
	}
	for(int i = 1; i <= N; i++){
		cash[sccId[i]] += arr[i];
		isATM[sccId[i]] = check[i];
	}
	for(int i = 1 ; i <= N; i++){
		for(int j : adj[i]){
			int u = sccId[i];
			int v = sccId[j];
			if(u == v || mp[{u,v}]) continue;
			mp[{u,v}] = 1;
			G[u].push_back(v);
		}
	}
	ll ans = 0;
	dp[sccId[S]] = 0;
	for(int i = 0 ; i < sccCnt; i++){
		dp[i] += cash[i];
		if(isATM[i]) ans = max(ans, dp[i]);
		for(int j : G[i]) dp[j] = max(dp[j], dp[i]);
	}
	cout << ans;

	return 0;
}