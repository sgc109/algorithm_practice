#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <queue>
#include <utility>
#include <stack>
#include <cstring>
#include <cstdlib>
#include <string>
#include <set>
#include <cmath>
// #include <unordered_set>
// #include <map>
#define REP(i,a,b) for(int i = a; i < b;++i) 
#define FOR(i,n) REP(i,0,n)
#define mp make_pair
#define pb push_back
#define inp1(a) scanf("%d",&a)
#define inp2(a,b) scanf("%d%d",&a,&b)
#define inp3(a,b,c) scanf("%d%d%d",&a,&b,&c)
#define inp4(a,b,c,d) scanf("%d%d%d%d",&a,&b,&c,&d)
// #define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)

using namespace std;

typedef long long ll;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<vector<int> > vvi;
typedef pair<int,int> pii;
typedef pair<int,pair<int,int> > piii;
typedef queue<int> QU;

const int MOD = 1000000007;
const int INF = 0x3c3c3c3c;
const long long INFL = 0x3c3c3c3c3c3c3c3c;
const int MAX_V = 10105;

struct Edge{
	int to, rev, cap,flow;
};
int n;
vector<Edge> adj[MAX_V];
int iter[MAX_V];
int level[MAX_V];
int DISH(int x){return 2+x;}
int TIME(int x){return 2+n+x;}

void bfs(int source){
	memset(level,-1,sizeof(level));
	memset(iter,0,sizeof(iter));
	QU q;
	q.push(source);
	level[source]=0;
	while(!q.empty() && level[1] == -1){
		int here = q.front();
		q.pop();
		for(auto edge : adj[here]){
			// printf("from:%d, to:%d, cap:%d\n",here,edge.to,edge.cap-edge.flow);
			if(edge.cap-edge.flow>0 && level[edge.to] == -1){
				level[edge.to]=level[here]+1;
				q.push(edge.to);
			}
		}
	}
}

int dfs(int here, int f){
	if(here==1) return f;
	for(int& i = iter[here]; i < adj[here].size(); ++i){
		Edge& uv = adj[here][i];
		if(uv.cap-uv.flow>0 && level[uv.to]>level[here]) {
			int minFlow = dfs(uv.to,min(f,uv.cap-uv.flow));
			if(minFlow) {
				uv.flow+=minFlow;
				adj[uv.to][uv.rev].flow-=minFlow;
				return minFlow;
			}
		}
	}
	return 0;
}

bool dinic(int k){
	int totalFlow=0;
	for(;;){
		bfs(0);
		if(level[1]==-1) break;
		int minFlow;
		while(minFlow = dfs(0,INF)){
			totalFlow+=minFlow;
		}
		// printf("totalFlow:%d\n",totalFlow);
	}
	if(totalFlow<k*n) return false;
	return true;
}

void init(){
	FOR(i,MAX_V){
		for(auto& edge : adj[i]){
			edge.flow=0;
		}
	}
}
void addEdge(int u, int v, int cap){
	adj[u].pb(Edge{v,(int)adj[v].size(),cap,0});
	adj[v].pb(Edge{u,(int)adj[u].size()-1,0,0});
}
int main() {
	inp1(n);
	FOR(i,n){
		int a,b;
		inp2(a,b);
		REP(j,a,b){
			addEdge(DISH(i),TIME(j),1);
		}
		addEdge(0,DISH(i),INF);
	}
	FOR(i,10000){
		addEdge(TIME(i),1,1);
	}
	int lo=0,hi=10001;
	while(lo<hi){
		// printf("lo:%d, hi:%d\n",lo,hi);
		int mid=(lo+hi)>>1;
		FOR(i,n){
			adj[0][i].cap=mid;
		}
		if(!dinic(mid)) hi=mid;
		else lo=mid+1;		
		init();
	}
	printf("%d\n",(hi-1)*n);
	return 0;
}