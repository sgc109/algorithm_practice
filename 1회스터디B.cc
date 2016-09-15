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
const int MAX_V = 100002;

int n,m;

int change[MAX_V];
priority_queue<pair<int,pair<int,int> > > pq;
vector<pii> adj[MAX_V];


int dijkstra(int start) {
	change[start] = 0;
	pq.push(mp(0,mp(start,0)));
	while(!pq.empty() && dist[n] == -1) {
		int here = pq.top().second.first;
		int changed = -pq.top().first;
		int lastLine = pq.top().second.second;
		for(auto &p : adj[here]) {
			int next = p.first;
			int nextLine = p.second;
			int trans = (lastLine != nextLine);
			if(change[next] > )
		}
	}
}

int main() {
	memset(change,0x3a,sizeof(change));

	inp2(n,m);
	FOR(i,m) {
		int a,b,c;
		inp3(a,b,c);
		adj[a].pb(mp(b,c));
		adj[b].pb(mp(a,c));
	}

	// dijkstra(1);
	return 0;
}