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
#include <unordered_set>
#include <set>
// #include <map>
#define REP(i,a,b) for(int i = a; i < b;++i) 
#define FOR(i,n) REP(i,0,n)
#define mp make_pair
#define pb push_back
#define inp1(a) scanf("%d",&a)
#define inp2(a,b) scanf("%d%d",&a,&b)
#define inp3(a,b,c) scanf("%d%d%d",&a,&b,&c)
#define inp4(a,b,c,d) scanf("%d%d%d%d",&a,&b,&c,&d)

using namespace std;

typedef pair<long long, long long> pll;
typedef vector<int> vi;
typedef vector<vector<int> > vvi;
typedef pair<int,int> pii;

const int INF = 0x3a3a3a3a;
const long long INFL = 0x3a3a3a3a3a3a3a3a;
const int MAX_V = 1004;

int cap[MAX_V][MAX_V], flow[MAX_V][MAX_V], cost[MAX_V][MAX_V];
vi adj[MAX_V];
int n,cntA,cntB;

int A(int x){
	return 2+x;
}
int B(int x){
	return 2+n+x;
}

int upper[MAX_V];
int parent[MAX_V];
int inQueue[MAX_V];

void spfa() {
	queue<int> q;
	q.push(0);
	inQueue[0] = 1;
	upper[0] = 0;
	parent[0] = 0;
	// printf("start!\n");
	while(!q.empty()) {
		int here = q.front();
		q.pop();
		inQueue[here] = 0;
		for(auto &there : adj[here]) {
			int dist = cost[here][there];
			if(cap[here][there]-flow[here][there] > 0 && upper[here] + dist < upper[there]) {
				upper[there] = upper[here] + dist;
				parent[there] = here;
				if(!inQueue[there]) {
					// printf("there:%d, upper[there]:%d\n",there,upper[there]);
					q.push(there);
					inQueue[there] = 1;
				}
			}
		}
	}
}

int ford(){
	int ret=0;
	while(true) {
		memset(upper,0x3a,sizeof(upper));
		memset(parent,-1,sizeof(parent));
		memset(inQueue,0,sizeof(inQueue));

		spfa();
		// printf("\n");
		if(parent[1] == -1) break;

		int minFlow=INF;
		int len = 0;
		for(int p = 1; p != parent[p]; p = parent[p]) {
			minFlow = min(minFlow, cap[parent[p]][p]-flow[parent[p]][p]);
			// printf("%d ",p);
		}
		// printf("minFlow:%d\n",minFlow);
		for(int p = 1; p != parent[p]; p = parent[p]) {
			flow[parent[p]][p] += minFlow;
			flow[p][parent[p]] -= minFlow;
			ret += cost[parent[p]][p]*minFlow;
			// printf("%d -> %d added %d\n",parent[p],p,cost[parent[p]][p]*minFlow);
		}
	}

	return ret;
}

void connect(int from, int to, int _cap, int _cost) {
	cap[from][to] = _cap;
	adj[from].pb(to);
	adj[to].pb(from);
	cost[from][to] = _cost;
	cost[to][from] = -_cost;
}

int main() {
	while(true) {
		inp3(n,cntA,cntB);
		if(n==0 && cntA==0 && cntB==0) break;
		FOR(i,MAX_V) adj[i].clear();
		memset(cap,0,sizeof(cap));
		memset(flow,0,sizeof(flow));
		memset(cost,0,sizeof(cost));
		FOR(i,n) {
			int a,b,c;
			inp3(a,b,c);

			connect(0,A(i),a,0);

			connect(A(i),B(0),INF,b);

			connect(A(i),B(1),INF,c);
		}

		connect(B(0),1,cntA,0);

		connect(B(1),1,cntB,0);

		int ans = ford();

		printf("%d\n",ans);

	}
	
	return 0;
}