#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod = 1e9+7;
const int inf = 0x3c3c3c3c;
const long long infl = 0x3c3c3c3c3c3c3c3c;

int T,N,M;
vector<int> G[20003];
vector<int> Gr[20003];
vector<int> Gn[20003];
vector<int> stck;
set<int> st[20003];
int visited[20003];
int sccId[20003];
int in[20003], out[20003];

int sccCnt;
void dfs1(int u){
	if(visited[u]) return;
	visited[u] = 1;
	for(int v : G[u]) dfs1(v);
	stck.push_back(u);
}
void dfs2(int u){
	if(sccId[u] != -1) return;
	sccId[u] = sccCnt;
	for(int v : Gr[u]) dfs2(v);
}
int main() {
	cin >> T;
	while(T--){
		sccCnt = 0;
		memset(sccId,-1,sizeof(sccId));
		memset(visited,0,sizeof(visited));
		memset(in,0,sizeof(in));
		memset(out,0,sizeof(out));
		for(int i = 0 ; i < 20003; i++) G[i].clear(), Gr[i].clear(), Gn[i].clear(), st[i].clear();
		cin >> N >> M;
		for(int i = 0 ; i < M; i++){
			int u,v;
			cin >> u >> v;
			G[u].push_back(v);
			Gr[v].push_back(u);
		}
		for(int i = 1 ; i <= N; i++) dfs1(i);
		while(!stck.empty()) {
			int u = stck.back();
			stck.pop_back();
			if(sccId[u] != -1) continue;
			dfs2(u);
			sccCnt++;
		}
		if(sccCnt == 1) {
			cout << 0 << endl;
			continue;
		}
		for(int u = 1 ; u <= N; u++){
			for(int v : G[u]){
				if(sccId[u] != sccId[v]) st[sccId[u]].insert(sccId[v]);
			}
		}
		for(int i = 0 ; i < sccCnt; i++) Gn[i].assign(st[i].begin(), st[i].end());

		for(int u = 0 ; u < sccCnt; u++){
			for(int v : Gn[u]) {
				out[u]++, in[v]++;
			}
		}
		int insum = 0, outsum = 0;
		for(int u = 0 ; u < sccCnt; u++) {
			if(!in[u]) insum++;
			if(!out[u]) outsum++;
		}
		cout << max(insum, outsum) << endl;
	}

	return 0;
}
