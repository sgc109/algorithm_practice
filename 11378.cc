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
#include <map>
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

const int INF = 0x3a3a3a3a;
const long long INFL = 0x3a3a3a3a3a3a3a3a;
const int MAX_N = 1000, MAX_M = 1000;
const int MAX_V = 3+MAX_N+MAX_M;

int N,M,K;
int cap[MAX_V][MAX_V],flow[MAX_V][MAX_V];
vvi adj;
int parent[MAX_V];

bool dfs(int here) {
	if(here == 1) return true;
	bool findPath = false;
	FOR(i,adj[here].size()) {
		int there = adj[here][i];
		if(cap[here][there]-flow[here][there]>0 && parent[there] == -1) {
			parent[there] = here;
			findPath = dfs(there);
			if(findPath) return findPath;
		}
	}
	return findPath;
}

int edmonds() {
	int ret = 0;
	while(true) {
		memset(parent,-1,sizeof(parent));
		parent[0] = 0;
		bool findPath = dfs(0);
		if(!findPath) break;

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

int WORKER(int x){
	return 3+x;
}

int WORK(int x){
	return 3+N+x;
}

int main() {
	inp3(N,M,K);
	adj = vvi(MAX_V,vi());
	FOR(i,N) {
		int c;
		inp1(c);
		FOR(j,c) {
			int a;
			inp1(a);
			--a;
			cap[WORKER(i)][WORK(a)] = 1;
			adj[WORKER(i)].pb(WORK(a));
			adj[WORK(a)].pb(WORKER(i));
		}
		cap[0][WORKER(i)] = 1;
		adj[0].pb(WORKER(i));
		adj[WORKER(i)].pb(0);

		cap[2][WORKER(i)] = K;
		adj[2].pb(WORKER(i));
		adj[WORKER(i)].pb(2);
	}
	FOR(i,M) {
		cap[WORK(i)][1] = 1;
		adj[WORK(i)].pb(1);
		adj[1].pb(WORK(i));
	}
	cap[0][2] = K;
	adj[0].pb(2);
	adj[2].pb(0);

	int ans = edmonds();
	printf("%d",ans);

	return 0;
}