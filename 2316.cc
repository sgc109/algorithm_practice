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
const int MAX_N = 400;
const int MAX_V = 1000;
vi adj[MAX_V];
int cap[MAX_V][MAX_V],flow[MAX_V][MAX_V];
int parent[MAX_V];
int n,m;

bool dfs(int here) {
	if(here == 1) return true;

	for(auto &there : adj[here]) {
		if(cap[here][there]-flow[here][there]>0 && parent[there] == -1) {
			parent[there] = here;
			if(dfs(there)) return true;
		}
	}
	return false;
}
int fordFulkerson() {
	int ret=0;
	while(true) {
		memset(parent,-1,sizeof(parent));
		parent[0] = 0;
		if(!dfs(0)) break;

		int minFlow = INF;
		for(int p = 1; p != parent[p]; p = parent[p]) {
			minFlow = min(minFlow, cap[parent[p]][p]-flow[parent[p]][p]);
		}
		for(int p = 1; p != parent[p]; p = parent[p]) {
			flow[parent[p]][p] += minFlow;
			flow[p][parent[p]] -= minFlow;
		}
		ret += minFlow;
	}
	return ret;
}

void connect(int a, int b) {
	if(a!=0&&a!=1&&b!=0&&b!=1) {
		cap[a][a+400] = 1;
		cap[b][b+400] = 1;
		cap[a+400][b] = INF;
		cap[b+400][a] = INF;
		adj[a].pb(a+400);
		adj[a+400].pb(a);
		adj[b].pb(b+400);
		adj[b+400].pb(b);
		adj[a+400].pb(b);
		adj[b].pb(a+400);
		adj[b+400].pb(a);
		adj[a].pb(b+400);
	}
	else if(b!=0&&b!=1) {
		cap[b][b+400] = 1;
		cap[a][b] = INF;
		cap[b+400][a] = INF;
		adj[b].pb(b+400);
		adj[b+400].pb(b);
		adj[a].pb(b);
		adj[b].pb(a);
		adj[b+400].pb(a);
		adj[a].pb(b+400);
	}
	else {
		cap[a][a+400] = 1;
		cap[a+400][b] = INF;
		cap[b][a] = INF;
		adj[a].pb(a+400);
		adj[a+400].pb(a);
		adj[a+400].pb(b);
		adj[b].pb(a+400);
		adj[b].pb(a);
		adj[a].pb(b);
	}
}

int main() {
	inp2(n,m);
	FOR(i,m){
		int a,b;
		inp2(a,b);
		--a;--b;
		connect(a,b);
	}

	int maxFlow = fordFulkerson();
	printf("%d",maxFlow);
	return 0;
}