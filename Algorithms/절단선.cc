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
const int MAX_V = 1002;

int n,m;
int findOrder[MAX_V];
int cntOrder;
vi adj[MAX_V];
vector<pii> ans;
int parent[MAX_V];

int dfs(int here) {
	int ret = findOrder[here] = cntOrder++;

	for(auto &there : adj[here]) {
		if(findOrder[there] == -1) {
			parent[there] = here;
			int highest = dfs(there);
			if(findOrder[here] < highest) {
				int a = here > there ? there : here;
				int b = here > there ? here : there;
				ans.pb(mp(a,b));
			}
			ret = min(ret, highest);
		}
		else {
			if(there != parent[here]) ret = min(ret, findOrder[there]);
		}
	}
	return ret;
}

int main() {
	while(true) {
		memset(findOrder,-1,sizeof(findOrder));
		memset(parent,-1,sizeof(parent));
		ans.clear();
		cntOrder=0;
		FOR(i,MAX_V) {
			adj[i].clear();
		}

		inp2(n,m);
		if(n==0&&m==0) break;
		FOR(i,m) {
			int a,b;
			inp2(a,b);
			adj[a].pb(b);
			adj[b].pb(a);
		}

		parent[0] = 0;
		dfs(0);

		sort(ans.begin(),ans.end());
		printf("%d",ans.size());
		FOR(i,ans.size()) printf(" %d %d",ans[i].first,ans[i].second);
		printf("\n");
		
	}
	return 0;
}