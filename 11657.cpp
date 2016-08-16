#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <string.h>
#include <queue>
#include <utility>
#include <map>

#define REP(i,a,b) for(int i = a; i < b; ++i)
#define FOR(i,n) REP(i,0,n)
#define mp(a,b) make_pair(a,b)
#define pb(x) push_back(x)

using namespace std;

typedef pair<int,int> ii;

const int INF = 0x3a3a3a3a;

vector<int> upper;
int N,M;
vector<vector<ii> > adj;

bool bellman(int start) {
	upper[start] = 0;
	FOR(k,N) {
		bool updated = false;
		FOR(here,N) {
			FOR(j,adj[here].size()) {
				int there = adj[here][j].first;
				int dist = adj[here][j].second;
				if(upper[there] > upper[here] + dist) {
					upper[there] = upper[here] + dist;
					updated = true;
				}
				
				// printf("here:%d, there:%d, dist:%d, upper[%d]:%d\n",here,there,dist,there,upper[there]);
			}
		}
		if(!updated) return true;
	}
	return false;
}

int main() {
	scanf("%d%d",&N,&M);
	adj = vector<vector<ii> >(N,vector<ii>());
	upper = vector<int>(N,INF);
	FOR(i,M) {
		int a,b,c;
		scanf("%d%d%d",&a,&b,&c);
		--a;--b;
		adj[a].pb(mp(b,c));
	}

	bool isCycle = !bellman(0);

	if(isCycle) {
		printf("-1");
		return 0;
	}
	REP(i,1,N) {
		if(upper[i] == INF) printf("-1\n");
		else printf("%d\n",upper[i]);
	}

	return 0;
}