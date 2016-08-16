#include <stdio.h>
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <utility>
#define REP(i,a,b) for(int i = a; i < b; ++i)
#define FOR(i,n) REP(i,0,n)
#define mp make_pair
#define pb push_back

using namespace std;

typedef pair<int, int> ii;

const int MAX_V = 100;
const int INF = 0x3a3a3a3a;

int nodeCost[MAX_V];
vector<int> upper;
vector<vector<ii> > adj;
bool reachable[MAX_V][MAX_V];

int N,M,S,F;

void floyd() {
	FOR(k,N) {
		FOR(i,N) {
			FOR(j,N) {
				reachable[i][j] = reachable[i][j] || (reachable[i][k] && reachable[k][j]);
			}
		}
	}
}

bool bellman(int start) {
	upper[start] = -nodeCost[start];
	FOR(k,N-1) {
		bool updated = false;
		FOR(here,N) {
			FOR(i,adj[here].size()) {
				int there = adj[here][i].first;
				int dist = adj[here][i].second;
				if(upper[there] > upper[here] + dist - nodeCost[there]) {
					upper[there] = upper[here] + dist - nodeCost[there];
					updated = true;
				}
			}
		}
		if(!updated) return false;
	}
	
	// bool updated = false;
	FOR(here,N) {
		FOR(i,adj[here].size()) {
			int there = adj[here][i].first;
			int dist = adj[here][i].second;
			if(upper[there] > upper[here] + dist - nodeCost[there]) {
				upper[there] = upper[here] + dist - nodeCost[there];
				if(reachable[S][here] && reachable[here][F]) return true;
			}
		}
	}
	return false;
}

int main() {
	scanf("%d%d%d%d",&N,&S,&F,&M);
	adj = vector<vector<ii> >(N, vector<ii>());
	upper = vector<int>(N,INF);
	FOR(i,N) {
		FOR(j,N) {
			if(i==j) reachable[i][j] = true;
			else reachable[i][j] = false;
		}
	}
	FOR(i,M) {
		int a,b,c;
		scanf("%d%d%d",&a,&b,&c);
		adj[a].pb(mp(b,c));
		reachable[a][b] = true;
	}
	FOR(i,N) {
		scanf("%d",nodeCost+i);
	}
	floyd();
	bool isThereCycle = bellman(S);
	if(!reachable[S][F]) printf("gg");
	else if(isThereCycle) printf("Gee");
	else printf("%d",-upper[F]);

	return 0;
}