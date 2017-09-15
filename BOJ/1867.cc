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
const int MAX_N = 500;

int map[MAX_N][MAX_N];
int n,k;
vi adj[MAX_N];
int aMatch[MAX_N],bMatch[MAX_N];
int visited[MAX_N];

bool dfs(int a) {
	if(visited[a]) return false;
	visited[a] = 1;

	FOR(i,adj[a].size()) {
		int b = adj[a][i];
		if(bMatch[b] == -1 || dfs(bMatch[b])) {
			bMatch[b] = a;
			aMatch[a] = b;
			return true;
		}
	}
	return false;
}

int bipartite() {
	memset(aMatch,-1,sizeof(aMatch));
	memset(bMatch,-1,sizeof(bMatch));
	int ret = 0;
	FOR(a,n) {
		memset(visited,0,sizeof(visited));
		if(dfs(a)) ++ret;		
	}
	return ret;
}
int main() {
	inp2(n,k);
	FOR(i,k) {
		int a,b;
		inp2(a,b);
		--a;--b;
		map[a][b] = 1;
	}
	FOR(i,n) {
		FOR(j,n) {
			if(map[i][j]) {
				adj[i].pb(j);
			}
		}
	}

	int matched = bipartite();
	printf("%d",matched);

	return 0;
}