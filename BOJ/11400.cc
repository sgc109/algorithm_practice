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

const int INF = 0x3a3a3a3a;
const long long INFL = 0x3a3a3a3a3a3a3a3a;
const int MAX_N = 1000000;
int V,E;
vector<vector<int> > adj;
vector<pair<int, int> > cutEdges;
vector<int> discovered;
int from[MAX_N];

int cnt = 0;
int dfs(int here) {
	discovered[here]=cnt++;

	int ret = discovered[here];

	FOR(i,adj[here].size()) {
		int there = adj[here][i];

		if(discovered[there] == -1) {
			from[there] = here;
			int highest = dfs(there);
			ret = min(ret, highest);

			if(highest > discovered[here]) {
				int a = here;
				int b = there;
				if(a > b) swap(a,b);
				cutEdges.pb(mp(a,b));
			}
		}
		else {
			if(there != from[here]) ret = min(ret, discovered[there]);
		}
	}

	return ret;
}

int main() {
	inp2(V,E);
	adj = vector<vector<int> >(V, vector<int>());
	discovered = vector<int>(V, -1);
	FOR(i,E) {
		int a,b;
		inp2(a,b);
		--a;--b;
		adj[a].pb(b);
		adj[b].pb(a);
	}

	FOR(i,V) {
		if(discovered[i] == -1) dfs(i);
	}

	printf("%d\n",cutEdges.size());
	sort(cutEdges.begin(),cutEdges.end());
	FOR(i,cutEdges.size()) {
		printf("%d %d\n",cutEdges[i].first+1, cutEdges[i].second+1);
	}
	return 0;
}