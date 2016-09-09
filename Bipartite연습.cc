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
typedef pair<int,int> pii;

const int INF = 0x3a3a3a3a;
const long long INFL = 0x3a3a3a3a3a3a3a3a;
const int MAX_N = 1000000;

int n,m;
vi adj[1000];
int aMatch[1000],bMatch[1000];
int visited[1000];

bool dfs(int here) {
	if(visited[here]) return false;
	visited[here] = 1;
	FOR(i,adj[here].size()) {
		int there = adj[here][i];
		if(bMatch[there] == -1 || dfs(bMatch[there])) {
			bMatch[there] = here;
			aMatch[here] = there;
			return true;
		}
	}

	return false;
}

int bipartite() {
	int size=0;
	FOR(i,n) {
		memset(visited,0,sizeof(visited));
		if(dfs(i)) ++size;
	}

	return size;
}
int main() {
	memset(aMatch,-1,sizeof(aMatch));
	memset(bMatch,-1,sizeof(bMatch));
	inp2(n,m);
	FOR(i,n){
		int c;
		inp1(c);
		FOR(j,c){
			int a;
			inp1(a);
			--a;
			adj[i].pb(a);
		}
	}

	int ans = bipartite();
	printf("%d",ans);

	return 0;
}