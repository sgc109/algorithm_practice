#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
#include<vector>
#define R 1001
#define MAX_R R*2
#define INF 1987654321
using namespace std;

int cost[MAX_R][MAX_R], flow[MAX_R][MAX_R];
int main(){
	int i;
	int v,e;

	while(scanf("%d%d",&v,&e)!=EOF){

		int source,sink;
		vector<int> adj[MAX_R];
		
		memset(flow,0,sizeof(flow));
		memset(cost,0,sizeof(cost));

		source=1;
		sink=v+v;
		getchar();
		for(i=0;i<e;i++){ // 이부분.
			int a,b,c;
			scanf("%d%d%d",&a,&b,&c);
			printf("%d -> %d\n",a,b+v);
			adj[a].push_back(b+v);
			adj[b+v].push_back(a);
			cost[a][b+v]=c;
			cost[b+v][a]=-c;
			flow[a][b+v]++;
		}

		int roop=2;
		int ans=0;
		int ans2=0;
		while(roop>0){
			int dist[MAX_R],prev[MAX_R];
			bool visit[MAX_R];

			memset(prev,-1,sizeof(prev));
			fill(dist,dist+MAX_R,INF);
			memset(visit,false,sizeof(visit));

			queue<int> q;
			visit[source]=true;
			q.push(source);
			dist[source]=0;

			while(!q.empty()){
				int x;
				x=q.front();
				q.pop();
				visit[x]=false;

				for(i=0;i<adj[x].size();i++){
					int next;
					next=adj[x][i];

					if(flow[x][next]==0) continue;
				
					if(dist[next]>dist[x]+cost[x][next]){
						dist[next]=dist[x]+cost[x][next];
						prev[next]=x;
						if(visit[next]==false){
							q.push(next);
							visit[next]=true;
						}
					}
				}
			}

			if(prev[sink]==-1) break;
			ans++;
			ans2+=dist[sink];
			for(i=sink;i!=source;i=prev[i]){
				flow[prev[i]][i]--;
				flow[i][prev[i]]++;
			}

			printf("%d\n",ans2);
			roop--;
		}
		
	}

	return 0;
}