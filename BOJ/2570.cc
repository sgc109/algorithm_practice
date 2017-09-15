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
const int MAX_N = 102;
const int MAX_V = 10000;

int obstacle[MAX_N][MAX_N];
pii map[MAX_N][MAX_N];
int n,m;
int cntDagak1,cntDagak2;

vi adj[MAX_V];

int aMatch[5000], bMatch[5000];
int visited[5000];
bool dfs(int a) {
	if(visited[a]) return false;
	visited[a] = 1;

	FOR(i,adj[a].size()) {
		int b = adj[a][i];
		if(aMatch[b] == -1 || dfs(aMatch[b])) {
			aMatch[b] = a;
			//bMatch[a] = b;
			return true;
		}
	}
	return false;
}

int bipartite() {
	int ret=0;
	memset(aMatch,-1,sizeof(aMatch));
	memset(bMatch,-1,sizeof(bMatch));
	FOR(a,cntDagak1) {
		memset(visited,0,sizeof(visited));
		if(dfs(a)) ++ret;
	}

	return ret;
}

bool inRange(int i, int j) {
	if(0 <= i && i < n && 0 <= j && j < n) return true;
	return false;
}

int main() {
	FOR(i,MAX_N) {
		FOR(j,MAX_N) {
			map[i][j] = mp(-1,-1);
		}
	}
	inp2(n,m);
	FOR(i,m) {
		int a,b;
		inp2(a,b);
		--a;--b;
		obstacle[a][b] = 1;
	}

	FOR(i,n) {
		FOR(j,n) {
			if(obstacle[i][j]) continue;
			if(map[i][j].first == -1) {
				for(int y=i,x=j; inRange(y,x) && !obstacle[y][x]; y-=1,x+=1) {
					map[y][x].first = cntDagak1;
					if(map[y][x].second != -1) adj[map[y][x].first].pb(map[y][x].second);
				}
				for(int y=i+1,x=j-1; inRange(y,x) && !obstacle[y][x]; y+=1,x-=1) {
					map[y][x].first = cntDagak1;
					if(map[y][x].second != -1) adj[map[y][x].first].pb(map[y][x].second);
				}
				++cntDagak1;
			}
			if(map[i][j].second == -1) {
				for(int y=i,x=j; inRange(y,x) && !obstacle[y][x]; y+=1,x+=1) {
					map[y][x].second = cntDagak2;
					if(map[y][x].first != -1) adj[map[y][x].first].pb(map[y][x].second);
				}
				for(int y=i-1,x=j-1; inRange(y,x) && !obstacle[y][x]; y-=1,x-=1) {
					map[y][x].second = cntDagak2;
					if(map[y][x].first != -1) adj[map[y][x].first].pb(map[y][x].second);
				}
				++cntDagak2;
			}
		}
	}

	int matched = bipartite();

	printf("%d",matched);
	return 0;
}