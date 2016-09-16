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
const int MAX_N = 500;
const int MAX_V = 1002;

int n,k;
vi adj[MAX_V];
int cap[MAX_V][MAX_V],flow[MAX_V][MAX_V];
int parent[MAX_V];

bool dfs(int here) {
	if(here==1) return true;

	FOR(i,adj[here].size()) {
		int there = adj[here][i];
		if(cap[here][there]-flow[here][there]>0 && parent[there] == -1) {
			parent[there] = here;
			if(dfs(there)) return true;
		}
	}
	return false;
}
int fordFulkerson() {
	int ret = 0;
	while(true) {
		memset(parent,-1,sizeof(parent));
		parent[0]=0;
		if(!dfs(0)) break;

		int minFlow=INF;
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

int A(int x){return 2+x;}
int B(int x){return 2+n+x;}
int main() {
	inp2(n,k);
	FOR(i,k){
		int a,b;
		inp2(a,b);
		--a;--b;
		cap[A(a)][B(b)] = 1;
		adj[A(a)].pb(B(b));
		adj[B(b)].pb(A(a));
	}
	FOR(i,n) {
		cap[0][A(i)] = 1;
		adj[0].pb(A(i));
		adj[A(i)].pb(0);

		cap[B(i)][1] = 1;
		adj[B(i)].pb(1);
		adj[1].pb(B(i));
	}

	printf("%d",fordFulkerson());

	return 0;
}