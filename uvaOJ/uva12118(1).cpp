#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9+7;
const int INF = 0x3c3c3c3c;
const long long INFL = 0x3c3c3c3c3c3c3c3c;

int G[1003][1003];
int degree[1003];
int V,E,T;
int cntOdd;
int visited[1003];
void dfs(int here){
	visited[here] = 1;
	cntOdd += (degree[here]%2);
	
	for(int there = 1; there <= V; there++){
		if(!G[here][there] || visited[there]) continue;
		dfs(there);
	}
}
int main() {
	for(int t = 1; ; t++){
		scanf("%d%d%d",&V,&E,&T);
		if(!V&&!E&&!T) break;

		memset(degree,0,sizeof(degree));
		memset(G,0,sizeof(G));
		memset(visited,0,sizeof(visited));

		for(int i = 0 ; i < E; i++){
			int a, b;
			scanf("%d%d",&a,&b);
			G[a][b] = G[b][a] = 1;
			degree[a]++, degree[b]++;
		}

		int ans = 0;
		for(int i = 1; i <= V; i++){
			if(visited[i] || !degree[i]) continue;
			ans++;
			cntOdd = 0;
			dfs(i);
			if(cntOdd>=2) ans += (cntOdd-2)/2;
		}
		if(ans) ans--;
		ans+=E;
		printf("Case %d: %d\n",t,ans*T);

	}
	return 0;
}
