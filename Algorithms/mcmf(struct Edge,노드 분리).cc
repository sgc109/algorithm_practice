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

struct Edge{int u,v,cap,cost,rev;};
int V,E,s,t,a,b,c,u,v;
vector<Edge> G[2003];
int dist[2003],pa[2003],pr[2003],inQ[2003];
int IN(int x){return x;}
int OUT(int x){return 1000+x;}
void connect(int a, int b, int c, int d){
	G[OUT(a)].push_back(Edge{OUT(a),IN(b),c,d,sz(G[IN(b)])});
	G[IN(b)].push_back(Edge{IN(b),OUT(a),0,-d,sz(G[OUT(a)])-1});
}
int main() {
	while(scanf("%d%d",&V,&E)!=-1){
		for(int i = 0; i < 2003; i++) G[i].clear();
		s=1,t=V;
		for(int i = 0; i < E; i++){
			scanf("%d%d%d",&a,&b,&c);
			connect(a,b,1,c);
		}
		for(int i = 1; i <= V; i++) G[IN(i)].push_back(Edge{IN(i),OUT(i),(i==1||i==V?INF:1),0,sz(G[OUT(i)])}),G[OUT(i)].push_back(Edge{OUT(i),IN(i),0,0,sz(G[IN(i)])-1});

		int ans=0;
		for(int k = 0; k < 2; k++){
			memset(dist,0x3c,sizeof(dist));
			memset(pa,-1,sizeof(pa));
			memset(pr,-1,sizeof(pr));
			memset(inQ,0,sizeof(inQ));
			queue<int> q;
			q.push(IN(s));
			dist[IN(s)]=0;
			inQ[IN(s)]=1;
			pa[IN(s)]=IN(s);
			while(!q.empty()){
				int here = q.front();
				q.pop();
				inQ[here]=0;
				int p=0;
				for(auto e : G[here]){
					if(e.cap>0 && dist[e.v]>dist[here]+e.cost){
						dist[e.v]=dist[here]+e.cost;
						pa[e.v] = here;
						pr[e.v] = p;
						if(!inQ[e.v]) inQ[e.v]=1,q.push(e.v);
					}
					p++;
				}
			}
			int minFlow=INF, sumCost=0;
			for(int p = OUT(t); p!=pa[p]; p=pa[p]){
				auto e1 = G[pa[p]][pr[p]];
				minFlow=min(minFlow,e1.cap);
				sumCost+=e1.cost;
			}
			for(int p = OUT(t); p!=pa[p]; p=pa[p]){
				auto e1 = G[pa[p]][pr[p]];
				G[pa[p]][pr[p]].cap-=minFlow, G[e1.v][e1.rev].cap+=minFlow;
			}
			ans+=minFlow*sumCost;
		}
		printf("%d\n",ans);
	}	
	return 0;
}
