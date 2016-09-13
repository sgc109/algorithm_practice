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
const int MAX_N = 100;
const int MAX_V = 5000;

int n,m;
int visited[MAX_V];
int aMatch[MAX_V],bMatch[MAX_V];
vi adj[MAX_V];
int map[MAX_N][MAX_N];
pii groupMap[MAX_N][MAX_N];
int cntGaro,cntSero;

bool dfs(int a) {
	if(visited[a]) return false;
	visited[a] = 1;

	for(auto &b : adj[a]) {
		if(bMatch[b] == -1 || dfs(bMatch[b])) {
			bMatch[b] = a;
			aMatch[a] = b;
			return true;
		}
	}
	return false;
}
int bipartite() {
	int ret = 0;
	FOR(i,cntGaro) {
		memset(visited,0,sizeof(visited));
		if(dfs(i)) ++ret;
	}
	return ret;
}

bool inRange(int i, int j) {
	if(0<=i&&i<n&&0<=j&&j<m) return true;
	return false;
}
int main() {
	inp2(n,m);
	FOR(i,n) {
		FOR(j,m) {
			inp1(map[i][j]);
			groupMap[i][j] = mp(-1,-1);
		}
	}
	memset(aMatch,-1,sizeof(aMatch));
	memset(bMatch,-1,sizeof(bMatch));
	FOR(i,n) {
		FOR(j,m) {
			if(map[i][j] == 2 || map[i][j] == 1) continue;
			if(groupMap[i][j].first == -1) {
				int y=i,x=j;
				for(;inRange(y,x)&&map[y][x]!=2;--x) {}
				++x;
				for(;inRange(y,x)&&map[y][x]!=2;++x) {
					if(map[y][x]==1) continue;
					groupMap[y][x].first = cntGaro;
					if(groupMap[y][x].second != -1) {
						adj[groupMap[y][x].first].pb(groupMap[y][x].second);
					}
				}
				++cntGaro;
			}
			if(groupMap[i][j].second == -1) {
				int y=i,x=j;
				for(;inRange(y,x)&&map[y][x]!=2;--y) {}
				++y;
				for(;inRange(y,x)&&map[y][x]!=2;++y) {
					if(map[y][x]==1) continue;
					groupMap[y][x].second = cntSero;
					if(groupMap[y][x].first != -1) {
						adj[groupMap[y][x].first].pb(groupMap[y][x].second);
					}
				}
				++cntSero;
			}
		}
	}

	int matched = bipartite();
	printf("%d",matched);
	return 0;
}