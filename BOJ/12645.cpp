#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod = 1e9+7;
const int inf = 0x3c3c3c3c;
const long long infl = 0x3c3c3c3c3c3c3c3c;

int N,M;
vector<int> G[1003], Gr[1003];
int in[1003];
int sccId[1003];
int sccCnt;
int visited[1003];
vector<int> s;
void dfs1(int here){
	if(visited[here]) return;
	visited[here] = 1;
	for(int there : G[here]) dfs1(there);
	s.push_back(here);
}
void dfs2(int here){
	if(sccId[here] != -1) return;
	sccId[here] = sccCnt;
	for(int there : Gr[here]) dfs2(there);
}
int main() {
	while(cin >> N >> M){
		for(int i = 0 ; i < 1003; i++) G[i].clear(), Gr[i].clear();
		memset(in,0,sizeof(in));
		memset(sccId,-1,sizeof(sccId));
		memset(visited,0,sizeof(visited));
		s.clear();
		sccCnt = 0;

		for(int i = 0 ; i < M ; i++){
			int a, b;
			cin >> a >> b;
			G[a].push_back(b);
			Gr[b].push_back(a);
		}
		for(int i = 0 ; i <= N; i++) dfs1(i);
		for(int i = s.size()-1; i >= 0 ; i--) if(sccId[s[i]] == -1) dfs2(s[i]), sccCnt++;
		for(int u = 0 ; u <= N; u++){
			for(int v : G[u]) if(sccId[u] != sccId[v]) in[sccId[v]]++;
		}
		in[sccId[0]]++;
		int ans = 0;
		for(int i = 0 ; i < sccCnt; i++) if(!in[i]) ans++;
		cout << ans << endl;
	}
	return 0;
}