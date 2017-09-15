#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9+7;
const int INF = 0x3c3c3c3c;
const long long INFL = 0x3c3c3c3c3c3c3c3c;

int G[1003][1003];
int degree[1003];
int V,E,T;
int cnt;
void dfs(int here){
	int last = -1;
	for(int there = 1 ; there <= V; there++) {
		if(!G[here][there]) continue;
		if(degree[there]%2) {
			last = there;
			continue;
		}
		G[here][there] = 0, G[there][here] = 0;
		degree[here]--, degree[there]--;
		cnt++;
		dfs(there);
		return;
	}
	if(last != -1) {
		G[here][last] = 0, G[last][here] = 0;
		degree[here]--, degree[last]--;
		cnt++;
		dfs(last);
	}
}
int main() {
	// freopen("output.txt","w",stdout);
	for(int t = 1; ; t++){
		memset(degree,0,sizeof(degree));
		memset(G,0,sizeof(G));
		scanf("%d%d%d",&V,&E,&T);
		if(!V&&!E&&!T) break;
		for(int i = 0 ; i < E; i++){
			int a, b;
			scanf("%d%d",&a,&b);
			G[a][b] = G[b][a] = 1;
			degree[a]++, degree[b]++;
		}
		cnt = 0;
		while(1){
			int cntOdd = 0;
			int sumDegree = 0;
			for(int i = 1 ; i <= V; i++) cntOdd+=(degree[i]%2), sumDegree+=degree[i];
			if(!sumDegree) break;

			if(!cntOdd){
				for(int i = 1 ; i <= V; i++) {
					if(!degree[i]) continue;
					cnt++;
					dfs(i);
					break;
				}
			}
			else {
				for(int i = 1 ; i <= V; i++) {
					if(degree[i]%2==0) continue;
					cnt++;
					dfs(i);
					break;
				}
			}
		}
		if(cnt) cnt--;
		printf("Case %d: %d\n",t,cnt*T);

	}
	return 0;
}
