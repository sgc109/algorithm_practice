#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9+7;
const int INF = 0x3c3c3c3c;
const long long INFL = 0x3c3c3c3c3c3c3c3c;

int dist[23][23];
int pane[23][23];
int N,M,T,K;
bool inRange(int i, int j){
	return 0 <= i && i < N && 0 <= j && j < M;
}
void dijkstra(){				// 지금까지 지나간 장애물이 K+1개가 되어서 끊겼는데 더 멀리돌아온놈이 장애물이 더 적어서 같은위치로 오면 얜 갈수있지만 이미 더 짧은 거리로 왔기 때문에 continue 되지않나?
	queue<pair<pair<int,int>, pair<int,int> > > pq;
	pq.push({{0,0},{0,0}});
	dist[0][0] = 0;
	while(!pq.empty()){
		auto p = pq.front();
		pq.pop();
		int hereI = p.second.first;
		int hereJ = p.second.second;
		int nowK = -p.first.second;
		int hereD = -p.first.first;
		if(dist[hereI][hereJ] < hereD) continue;

		for(int k = 0 ; k < 4; k++){
			int thereI = hereI + "2011"[k]-'1';
			int thereJ = hereJ + "1120"[k]-'1';
			int thereD = hereD + 1;
			if(!inRange(thereI, thereJ)) continue;
			if(pane[thereI][thereJ] == 1 && nowK == K) continue;
			
			int isK = pane[thereI][thereJ] == 1;
			if(dist[thereI][thereJ] <= thereD) continue;
			dist[thereI][thereJ] = thereD;
			pq.push({{-thereD, isK ? -(nowK+1) : 0}, {thereI, thereJ}});
		}
	}
}
int main() {
	scanf("%d",&T);
	while(T--){
		memset(dist,0x3c,sizeof(dist));
		scanf("%d%d%d",&N,&M,&K);
		for(int i = 0 ; i < N; i++) for(int j = 0 ; j < M; j++) scanf("%d",&pane[i][j]);
		dijkstra();
		int ans = dist[N-1][M-1];
		if(ans == INF) ans = -1;
		printf("%d\n",ans);
	}
	return 0;
}
