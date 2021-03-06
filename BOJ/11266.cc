#include <iostream>
#include <cstdio>
#include <vector>
// #include <algorithm>
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

const int INF = 0x3a3a3a3a;
const long long INFL = 0x3a3a3a3a3a3a3a3a;
const int MAX_N = 10002;

int V,E;

vector<vector<int> > adj;
int isCutVertex[MAX_N];
int discovered[MAX_N];

int cnt = 0;
int dfs(int here, bool isRoot) {
	discovered[here] = cnt++;

	int child = 0;
	int ret = discovered[here];

	FOR(i,adj[here].size()) {
		int there = adj[here][i];

		if(discovered[there] == -1) {
			++child;
			int highest = dfs(there, false);
			if(highest >= discovered[here]) isCutVertex[here] = 1;
			ret = min(ret, highest);
		}
		else ret = min(ret, discovered[there]);
	}

	if(isRoot) isCutVertex[here] = (child >= 2);

	return ret;
}

int main() {
	inp2(V,E);
	memset(isCutVertex,0,sizeof(isCutVertex));
	memset(discovered,-1,sizeof(discovered));
	adj = vector<vector<int> >(V, vector<int>());
	FOR(i,E) {
		int a,b;
		inp2(a,b);
		--a;--b;
		adj[a].pb(b);
		adj[b].pb(a);
	}

	FOR(i,V) {
		if(discovered[i] == -1) dfs(i,true);
	}


	int ans = 0;
	FOR(i,V) if(isCutVertex[i]) ++ans;
	printf("%d\n",ans);
	FOR(i,V) if(isCutVertex[i]) printf("%d ",i+1);
	return 0;
}