#include <iostream>
#include <stdio.h>
#include <vector>
#include <queue>
#include <algorithm>
#define REP(i,a,b) for(int i = a; i < b; ++i)
#define FOR(i,n) REP(i,0,n)
#define pb push_back
#define mp make_pair

using namespace std;

typedef pair<int,int> ii;

const int MAX_V = 500;
const int INF = 0x3a3a3a3a;

int N,M,W;
vector<int> upper;
vector<vector<ii> > adj;

bool bellman(int start) {
	upper[start] = 0;
	FOR(k,N) {
		bool updated = false;
		FOR(here,N) {
			FOR(i,adj[here].size()) {
				int there = adj[here][i].first;
				int dist = adj[here][i].second;
				if(upper[there] > upper[here] + dist) {
					upper[there] = upper[here] + dist;
					updated = true;
				}
			}
		}
		if(!updated) return false;
	}
	return true;
}

int main() {
	int T;
	scanf("%d",&T);
	while(T--) {
		scanf("%d%d%d",&N,&M,&W);
		adj = vector<vector<ii> >(N, vector<ii>());
		upper = vector<int>(N, INF);
		FOR(i,M) {
			int a,b,c;
			scanf("%d%d%d",&a,&b,&c);
			--a;--b;
			adj[a].pb(mp(b,c));
			adj[b].pb(mp(a,c));
		}
		FOR(i,W) {
			int a,b,c;
			scanf("%d%d%d",&a,&b,&c);
			--a;--b;
			adj[a].pb(mp(b,-c));
		}
		bool isThereCycle = bellman(0);
		if(isThereCycle) printf("YES\n");
		else printf("NO\n");
	}

	return 0;
}