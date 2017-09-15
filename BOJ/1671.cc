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
const int MAX_N = 1001;
const int MAX_V = 2003;
int n;
int stat[MAX_N][3];
int cap[MAX_V][MAX_V],flow[MAX_V][MAX_V];
vi adj[MAX_V];

int A(int x) {return 2+x;}
int B(int x) {return 2+n+x;}

int parent[MAX_V];

bool dfs(int here) {
	if(here == 1) return true;

	FOR(i,adj[here].size()) {
		int there = adj[here][i];
		if(cap[here][there]-flow[here][there]>0 && parent[there] == -1) {
			parent[there] = here;
			if(dfs(there)) return true;
		}
	}
	return false;
}
int edmonds() {
	int ret = 0;
	while(true) {
		memset(parent,-1,sizeof(parent));

		parent[0]=0;
		if(!dfs(0)) break;

		int start=-1,finish=-1;
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

int main() {
	inp1(n);
	FOR(i,n) {
		inp3(stat[i][0],stat[i][1],stat[i][2]);
	}

	FOR(i,n){
		FOR(j,n) {
			if(i==j) continue;
			if(stat[i][0] == stat[j][0] && stat[i][1] == stat[j][1] && stat[i][2] == stat[j][2]) {
				if(cap[A(j)][B(i)] == 0) {
					cap[A(i)][B(j)] = 1;
					adj[A(i)].pb(B(j));
					adj[B(j)].pb(A(i));
				}
			}
			else if(stat[i][0] >= stat[j][0] && stat[i][1] >= stat[j][1] && stat[i][2] >= stat[j][2]) {
				cap[A(i)][B(j)] = 1;
				adj[A(i)].pb(B(j));
				adj[B(j)].pb(A(i));
			}
		}
		cap[0][A(i)] = 2;
		adj[0].pb(A(i));
		adj[A(i)].pb(0);

		cap[B(i)][1] = 1;
		adj[B(i)].pb(1);
		adj[1].pb(B(i));
	}

	int matched = edmonds();

	printf("%d",n-matched);
	return 0;
}