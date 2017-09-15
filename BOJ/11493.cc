// #include <bits/stdc++.h>
#include <vector>
#include <cstdio>
#include <iostream>
#include <cstring>
#include <queue>
#include <set>
#include <map>
#include <cmath>
#include <algorithm>
#include <utility>
#define REP(i,a,b) for(int i=a;i<=b;++i)
#define FOR(i,n) for(int i=0;i<n;++i)
#define pb push_back
#define all(v) (v).begin(),(v).end()
#define sz(v) ((int)(v).size())
#define inp1(a) scanf("%d",&a)
#define inp2(a,b) scanf("%d%d",&a,&b)
#define inp3(a,b,c) scanf("%d%d%d",&a,&b,&c)
#define inp4(a,b,c,d) scanf("%d%d%d%d",&a,&b,&c,&d)
#define inp5(a,b,c,d,e) scanf("%d%d%d%d%d",&a,&b,&c,&d,&e)
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef pair<int,int> pii;
typedef vector<pii> vii;
typedef vector<pll> vll;
typedef vector<vector<int> > vvi;
typedef pair<int,pair<int,int> > piii;
typedef vector<piii> viii;
const double EPSILON = 1e-9;
const double PI = acos(0.0)*2;
const int MOD = 1000000007;
const int INF = 0x3c3c3c3c;
const long long INFL = 0x3c3c3c3c3c3c3c3c;
const int MAX_N = 102;

int N,M,T,S,E,a,b,c,d;
vector<int> G[1003];
int coin[503], box[503];
int cost[1003][1003], dist[1003], minD[1003], cap[1003][1003], parent[1003], inQ[1003], dp[1003][1003];
bool spfa(){
	memset(dist,0x3c,sizeof(dist));
	memset(inQ,0,sizeof(inQ));
	queue<int> q;
	q.push(S);
	dist[S]=0, inQ[S]=1;
	while(!q.empty()){
		int here = q.front();
		q.pop();
		inQ[here]=0;
		for(int there : G[here]){
			if(cap[here][there]<=0 || dist[there]<=dist[here]+cost[here][there]) continue;
			dist[there] = dist[here] + cost[here][there];
			parent[there]=here;
			if(!inQ[there]) q.push(there),inQ[there]=1;
		}
	}
	return dist[E]!=INF;
}
int mcmf(){
	int ret=0;
	while(1){
		if(!spfa()) break;
		int costSum=0;
		for(int p=E;p!=S;p=parent[p]) costSum+=cost[parent[p]][p], cap[parent[p]][p]--, cap[p][parent[p]]++;
		ret+=costSum;
	}
	return ret;
}
int COIN(int x){return x;}
int BOX(int x){return 500+x;}
void connect(int a, int b, int c){G[a].push_back(b), G[b].push_back(a), cap[a][b]=1, cost[a][b]=c, cost[b][a]=-c;}
int main() {
	S=1000,E=1001;
	for(scanf("%d",&T);T--;){
		for(int i = 0; i < 1003; i++) G[i].clear();
		memset(dp,0x3c,sizeof(dp));
		memset(minD,0x3c,sizeof(minD));
		memset(cap,0,sizeof(cap));
		scanf("%d%d",&N,&M);
		for(int i = 0; i < M; i++) scanf("%d%d",&a,&b),a--,b--,dp[a][b]=dp[b][a]=1;
		for(int i = 0; i < N; i++) dp[i][i]=0;
		for(int i = 0; i < N; i++) scanf("%d",box+i);
		for(int i = 0; i < N; i++) scanf("%d",coin+i);
		for(int k = 0; k < N; k++) for(int i = 0; i < N; i++) for(int j = 0; j < N; j++) dp[i][j]=min(dp[i][j],dp[i][k]+dp[k][j]);
		for(int i = 0; i < N; i++){
			if(coin[i]) continue;
			for(int j = 0; j < N; j++){
				if(box[j]||dp[i][j]==INF) continue;
				connect(COIN(i),BOX(j),dp[i][j]);
			}
		}
		for(int i = 0; i < N; i++) connect(S,COIN(i),0);
		for(int i = 0; i < N; i++) connect(BOX(i),E,0);
		int minCost = mcmf();
		printf("%d\n",minCost);
	}
	return 0;
}
