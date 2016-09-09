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

const int INF = 0x3a3a3a3a;
const long long INFL = 0x3a3a3a3a3a3a3a3a;
const int MAX_N = 10000;
const int MAX_V = 52;

int notPrime[100000]={1,1,};
vi adj[MAX_V];
int cap[MAX_V][MAX_V], flow[MAX_V][MAX_V];
int n;
int a[MAX_V];

int visited[MAX_V];
int visitCnt;
int color[MAX_V];
bool dfs(int here) {
	bool colorable = true;
	FOR(i,adj[here].size()) {
		int there = adj[here][i];
		if(there == 0 || there == 1) continue;
		if(visited[there] == 0) {
			visited[there] = 1;
			color[there] = color[here]^1;
			if(color[there] == 0) {
				cap[color[there]][there]=1;
			}
			else if(color[there] == 1) {
				cap[there][color[there]]=1;
			}
			adj[color[there]].pb(there);
			adj[there].pb(color[there]);

			++visitCnt;
			if(!dfs(there)) return false;
		}
		else if(color[there] == color[here]) return colorable=false;
	}
	return colorable;
}

bool isColorable() {
	visitCnt=1;
	memset(color,-1,sizeof(color));
	visited[2] = 1;
	color[2] = 0;
	cap[0][2] = 1;
	adj[0].pb(2);
	adj[2].pb(0);

	if(!dfs(2)) return false;
}

int parent[MAX_V];
bool dfs2(int here) {
	// printf("%d ",here);
	if(here == 1) return true;
	FOR(i,adj[here].size()) {
		int there = adj[here][i];
		if(cap[here][there]-flow[here][there]>0 && parent[there] == -1) {
			parent[there] = here;
			if(dfs2(there)) return true;
		}
	}
	return false;
}

int edmonds() {
	int ret=0;
	while(true) {
		memset(parent,-1,sizeof(parent));
		parent[0] = 0;
		if(!dfs2(0)) break;
		int minFlow = INF;
		for(int p = 1; p != parent[p]; p = parent[p]) {
			minFlow = min(minFlow,cap[parent[p]][p]-flow[parent[p]][p]);
		}
		for(int p = 1; p != parent[p]; p = parent[p]) {
			flow[parent[p]][p] += minFlow;
			flow[p][parent[p]] -= minFlow;
		}
		// printf("%d ",minFlow);
		ret+=minFlow;
	}
	return ret;
}

int main() {
	for(int i = 2; i * i <= 100000; ++i) {
		if(notPrime[i] == 0) {
			for(int j = 2*i; j < 100000; j+=i) {
				notPrime[j] = 1;
			}
		}
	}
	inp1(n);
	FOR(i,n) inp1(a[i]);
	FOR(i,n) {
		REP(j,i+1,n) {
			if(!notPrime[a[i]+a[j]]) {
				//cap[2+i][2+j]=1;
				adj[2+i].pb(2+j);
				adj[2+j].pb(2+i);
			}
		}
	}

	if(!isColorable()) {
		printf("-1");
		return 0;
	}
	if(visitCnt!=n) {
		printf("-1");
		return 0;
	}

	FOR(i,n) {
		REP(j,i+1,n) {
			if(!notPrime[a[i]+a[j]]) {
				if(color[2+i]==0) cap[2+i][2+j]=1;
				else cap[2+j][2+i]=1;
			}
		}
	}

	vi ans;

	cap[0][2]=0;
	FOR(i,adj[2].size()) {
		if(adj[2][i]==0) continue;
		memset(flow,0,sizeof(flow));
		cap[adj[2][i]][1]=0;
		int matched = edmonds();
		// printf("%d ",matched);
		if((matched+1) == (n/2)) ans.pb(a[adj[2][i]-2]);

		cap[adj[2][i]][1]=1;
	}
	if(ans.size()==0) {
		printf("-1");
		return 0;
	}
	sort(ans.begin(),ans.end());
	FOR(i,ans.size()) {
		printf("%d ",ans[i]);
	}
	
	return 0;
}