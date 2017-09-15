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

int cap[130][130],cost[130][130],parent[130],dist[130],inQ[130],score[128][128];
int N,s,t;
char pane[20][20];
vector<int> G[130];
bool inRange(int i, int j){return 0<=i&&i<N&&0<=j&&j<N;}
void connect(int a, int b, int c, int d){
	G[a].push_back(b);
	G[b].push_back(a);
	cap[a][b]=c;
	cost[a][b]=-d;
	cost[b][a]=d;
}
int G1(int x){return 2+x;}
int G2(int x){return 2+(N*N+1)/2+x;}

int mcmf(){
	int retCost=0;
	while(1){
		memset(parent,-1,sizeof(parent));
		memset(dist,0x3c,sizeof(dist));
		memset(inQ,0,sizeof(inQ));
		parent[s]=s,dist[s]=0,inQ[s]=1;
		queue<int> q;
		q.push(s);
		while(!q.empty()){
			int here = q.front();
			q.pop();
			inQ[here]=0;
			for(int there : G[here]){
				if(cap[here][there]==0) continue;
				if(dist[there] > dist[here] + cost[here][there]){
					dist[there] = dist[here] + cost[here][there],parent[there]=here;
					if(!inQ[there]) inQ[there]=1,q.push(there);
				}
			}
		}
		if(parent[t]==-1) break;
		int sumCost=0;
		for(int p=t;parent[p]!=p;p=parent[p]) cap[parent[p]][p]--,cap[p][parent[p]]++,sumCost+=cost[parent[p]][p];
		if(sumCost>=0) break;
		retCost+=sumCost;
	}
	return -retCost;
}
int main() {
	s=0,t=1;
	int arr[] = { 100,70,40,0,70,50,30,0,40,30,20,0,0,0,0,0 };
	char alpha[5] = "ABCF";
	int cnt = 0;
	FOR(i, 4) FOR(j, 4) score[alpha[i]][alpha[j]] = arr[cnt++];
	inp1(N);
	FOR(i, N) scanf("%s", pane[i]);
	FOR(i,N){
		FOR(j,N){
			int pos=i*N+j;
			if(j+1<N) {
				int scr = score[pane[i][j]][pane[i][j+1]];
				if((i+j)%2) connect(G1((pos+1)/2),G2(pos/2),1,scr);
				else connect(G1(pos/2),G2((pos+1)/2),1,scr);
			}
			if(i+1<N) {
				int scr = score[pane[i][j]][pane[i+1][j]];
				int pos2=(i+1)*N+j;
				if((i+j)%2) connect(G1(pos2/2),G2(pos/2),1,scr);
				else connect(G1(pos/2),G2(pos2/2),1,scr);
			}
		}
	}
	FOR(i,(N*N+1)/2) connect(s,G1(i),1,0),connect(G2(i),t,1,0);

	int ans = mcmf();
	printf("%d",ans);
	return 0;
}
