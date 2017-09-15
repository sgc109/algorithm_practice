#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod = 1e9+7;
const int inf = 0x3c3c3c3c;
const long long infl = 0x3c3c3c3c3c3c3c3c;

int T,N,M;
vector<int> G[203];
int color[203];
bool dfs(int u, int col){
	if(color[u] != -1) return color[u] == col;
	color[u] = col;
	bool ret = true;
	for(int v : G[u]) ret = ret && dfs(v, 1 - col);
	return ret;
}
int main() {
	cin >> T;
	for(int t = 1 ; t <= T; t++){
		memset(color,-1,sizeof(color));
		for(int i = 0 ; i < 203; i++) G[i].clear();
		cin >> N >> M;
		for(int i = 0 ; i < M; i++){
			int a,b;
			cin >> a >> b;
			G[a].push_back(b);
			G[b].push_back(a);
		}
		bool ans = true;
		for(int i = 1 ; i <= N; i++) if(color[i] == -1) ans = ans && dfs(i, 0);
		cout << "Case #" << t << "\n" << (ans ? 1 : 0) << "\n";
	}
	return 0;
}
