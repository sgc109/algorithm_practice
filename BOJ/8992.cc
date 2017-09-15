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

struct Line{int x1,y1,x2,y2,w;};
int T,N,M,s,t,a,b,c,d,e;
Line lineX[203],lineY[203];
vi G[410];
int cap[410][410],parent[410],inQ[410];
ll cost[410][410],dist[410];
int CORDX(int x){return 2+x;}
int CORDY(int x){return 2+N+x;}
void connect(int a, int b, int c, ll d){
	G[a].pb(b);
	G[b].pb(a);
	cap[a][b]=c;
	cost[a][b]=-d;
	cost[b][a]=d;
}
bool isCross(Line& lx, Line& ly){return lx.x1<=ly.x1&&ly.x1<=lx.x2&&ly.y1<=lx.y1&&lx.y1<=ly.y2;}
pair<int,ll> mcmf(){
	int retFlow=0;
	ll retCost=0;
	while(1){
		memset(parent,-1,sizeof(parent));
		memset(inQ,0,sizeof(inQ));
		memset(dist,0x3c,sizeof(dist));
		parent[s]=s;
		dist[s]=0;
		inQ[s]=1;
		queue<int> q;
		q.push(s);
		while(!q.empty()){
			int here = q.front();
			q.pop();
			inQ[here]=0;
			for(int there : G[here]){
				if(cap[here][there]<=0) continue;
				if(dist[there]>dist[here]+cost[here][there]){
					dist[there]=dist[here]+cost[here][there];
					if(!inQ[there]) inQ[there]=1,q.push(there);
					parent[there]=here;
				}
			}
		}
		if(parent[t]==-1) break;
		ll accCost=0;
		for(int p=t;parent[p]!=p;p=parent[p]) accCost+=cost[parent[p]][p];
		for(int p=t;parent[p]!=p;p=parent[p]) cap[parent[p]][p]-=1, cap[p][parent[p]]+=1;
		retCost+=accCost,retFlow+=1;
	}
	return {retFlow,-retCost};
}
int main() {
	s=0,t=1;
	for(inp1(T);T--;){
		FOR(i,410) G[i].clear();
		memset(cap,0,sizeof(cap));
		memset(cost,0,sizeof(cost));
		inp2(N,M);
		FOR(i,N) inp5(a,b,c,d,e),(a>c?swap(a,c),0:0),lineX[i]=Line{a,b,c,d,e};
		FOR(i,M) inp5(a,b,c,d,e),(b>d?swap(b,d),0:0),lineY[i]=Line{a,b,c,d,e};
		FOR(i,N) FOR(j,M) if(isCross(lineX[i],lineY[j])) connect(CORDX(i),CORDY(j),1,(ll)lineX[i].w*lineY[j].w);
		FOR(i,N) connect(0,CORDX(i),1,0);
		FOR(i,M) connect(CORDY(i),1,1,0);
		pair<int,ll> ans = mcmf();
		printf("%d %lld\n",ans.first,ans.second);
	}
	return 0;
}
