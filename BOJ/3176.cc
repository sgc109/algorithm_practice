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
#include <set>
#include <cmath>
// #include <unordered_set>
// #include <map>
#define REP(i,a,b) for(int i = a; i < b;++i) 
#define FOR(i,n) REP(i,0,n)
#define REPR(i,b,a) for(int i = b; i >= a;--i)
#define FORR(i,n) REP(i,n,0)
#define mp make_pair
#define pb push_back
#define inp1(a) scanf("%d",&a)
#define inp2(a,b) scanf("%d%d",&a,&b)
#define inp3(a,b,c) scanf("%d%d%d",&a,&b,&c)
#define inp4(a,b,c,d) scanf("%d%d%d%d",&a,&b,&c,&d)
// #define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)

using namespace std;

typedef long long ll;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<vector<int> > vvi;
typedef pair<int,int> pii;
typedef pair<int,pair<int,int> > piii;
typedef queue<int> QU;

const int INF = 0x3c3c3c3c;
const long long INFL = 0x3c3c3c3c3c3c3c3c;
const int MAX_N = 100002;

int n,m;
int depth[MAX_N];
int parent[MAX_N][18];
int minW[MAX_N][18];
int maxW[MAX_N][18];
int minWeight,maxWeight;
vector<pii> adj[MAX_N];
int visited[MAX_N];
void dfs(int here){
	// printf("here:%d\n",here+1);	
	visited[here]=1;
	for(int i = 1; (1<<i) <= depth[here];++i){
		parent[here][i] = parent[parent[here][i-1]][i-1];
		minW[here][i] = min(minW[here][i-1],minW[parent[here][i-1]][i-1]);
		maxW[here][i] = max(maxW[here][i-1],maxW[parent[here][i-1]][i-1]);
	}
	for(pii& p : adj[here]){
		int there = p.first;
		int w = p.second;
		if(visited[there]) continue;
		depth[there] = depth[here]+1;
		parent[there][0] = here;
		maxW[there][0] = minW[there][0] = w;
		dfs(there);
	}
}
void init(){
	dfs(0);
}
int lca(int a, int b){
	minWeight=INF;maxWeight=-1;
	if(a==b) return a;
	if(depth[a] < depth[b]) swap(a,b);
	for(int i = 17; i >= 0; --i){
		if((1<<i) <= (depth[a]-depth[b])) {
			minWeight=min(minWeight,minW[a][i]);
			maxWeight=max(maxWeight,maxW[a][i]);
			a=parent[a][i];
		}
	}
	for(int i = 17; i >= 0; --i){
		if(parent[a][i]!=parent[b][i]) {
			minWeight=min(minWeight,minW[a][i]);
			minWeight=min(minWeight,minW[b][i]);
			maxWeight=max(maxWeight,maxW[a][i]);
			maxWeight=max(maxWeight,maxW[b][i]);
			a=parent[a][i];
			b=parent[b][i];
		}
	}
	if(a==b) return a;
	while(a!=b){
		minWeight=min(minWeight,minW[a][0]);
		minWeight=min(minWeight,minW[b][0]);
		maxWeight=max(maxWeight,maxW[a][0]);
		maxWeight=max(maxWeight,maxW[b][0]);
		a=parent[a][0];b=parent[b][0];
	}
	return a;
}

int main() {
	inp1(n);
	FOR(i,n-1){
		int a,b,c;
		inp3(a,b,c);
		--a;--b;
		adj[a].pb(mp(b,c));
		adj[b].pb(mp(a,c));
	}
	init();
	inp1(m);
	FOR(i,m){
		int a,b;
		inp2(a,b);
		--a;--b;
		lca(a,b);
		printf("%d %d\n",minWeight,maxWeight);
	}
	return 0;
}