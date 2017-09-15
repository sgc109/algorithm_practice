#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod = 1e9+7;
const int inf = 0x3c3c3c3c;
const long long infl = 0x3c3c3c3c3c3c3c3c;

int T,N,M,Q,K;
vector<int> G[10003];
int visited[10003];
int cache[10003];
int rearNode;
int rearD;
int dfs(int here, int dad, int dist){
	visited[here] = 1;
	if(rearD < dist) rearD = dist, rearNode = here;
	int ret = 1;
	for(int there : G[here]) {
		if(there == dad) continue;
		ret += dfs(there, here, dist+1);
	}
	return ret;
}
int main() {
	cin >> T;
	for(int t = 1; t <= T ; t++){
		memset(visited,0,sizeof(visited));
		memset(cache,0x3c,sizeof(cache));
		for(int i = 0 ; i < 10003; i++) G[i].clear();
		cin >> N >> M;
		for(int i = 0 ; i < M; i++){
			int a,b;
			cin >> a >> b;
			G[a].push_back(b);
			G[b].push_back(a);
		}
		for(int i = 1 ; i <= N; i++) {
			if(visited[i]) continue;
			rearD = -1;
			int nodeCnt = dfs(i, -1, 0);
			rearD = -1;
			dfs(rearNode, -1, 0);
			for(int j = 1 ; j <= rearD+1; j++) cache[j] = min(cache[j], j-1);
			for(int j = rearD + 2 ; j <= nodeCnt; j++) cache[j] = min(cache[j], rearD + 2*(j - rearD - 1));
		}

		cout << "Case " << t << ":" << endl;

		cin >> Q;
		for(int i = 0 ; i < Q; i++){
			cin >> K;
			if(cache[K] == inf) cout << "impossible" << endl;
			else cout << cache[K] << endl;
		}
	}
	return 0;
}