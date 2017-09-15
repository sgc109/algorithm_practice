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
const int MAX_V = 2+MAX_N+MAX_M;


int cap[MAX_V][MAX_V],flow[MAX_V][MAX_V];
vvi adj;
int n,m;


vi parent;
int dfs(int here, int finish) {
	if(here == finish) return -1;
	int ret=0;
	FOR(i,adj[here].size()) {
		int there = adj[here][i];
		if(cap[here][there]-flow[here][there]>0 && parent[there] == -1) {
			parent[there] = here;
			ret = dfs(there, finish);
			if(ret==-1) return ret;
		}
	}
	return ret;
}
int edmonds(int start, int finish) {
	int ret = 0;
	
	while(true){
		
		parent = vi(MAX_V,-1);
		parent[start] = start;
		if(dfs(start, finish) != -1) break;

		int minFlow = INF;
		for(int p = finish; p != parent[p]; p = parent[p]) {
			minFlow = min(minFlow, cap[parent[p]][p]-flow[parent[p]][p]);
		}
		for(int p = finish; p != parent[p]; p = parent[p]) {
			flow[parent[p]][p] += minFlow;
			flow[p][parent[p]] -= minFlow;
		}
		ret += minFlow;
	}
	return ret;

}
int main() {
	inp2(n,m);
	adj = vvi(MAX_V,vi());
	FOR(i,n){
		int c;
		inp1(c);
		FOR(j,c){
			int a;
			inp1(a);
			--a;
			cap[2+i][2+MAX_N+a] = 1;
			adj[2+i].pb(2+MAX_N+a);
			adj[2+MAX_N+a].pb(2+i);
		}
		cap[0][2+i] = 2;
		adj[0].pb(2+i);
		adj[2+i].pb(0);
	}
	FOR(i,m) {
		cap[2+MAX_N+i][1] = 1;
		adj[2+MAX_N+i].pb(1);
		adj[1].pb(2+MAX_N+i);
	}

	int ans = edmonds(0,1);
	printf("%d",ans);
	return 0;
}