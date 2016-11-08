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

const int MOD = 1000000007;
const int INF = 0x3c3c3c3c;
const long long INFL = 0x3c3c3c3c3c3c3c3c;
const int MAX_N = 100002;

int depth[MAX_N];
int parent[MAX_N][18];
vi adj[MAX_N];
int N,M;
void dfs(int here){
	for(int i=1; (1<<i)<=depth[here]; ++i){
		parent[here][i] = parent[parent[here][i-1]][i-1];
	}

	for(int there : adj[here]){
		if(depth[there]!=-1) continue;
		depth[there] = depth[here] + 1;
		parent[there][0] = here;
		dfs(there);
	}
}

int lca(int a, int b){
	if(a==b) return a;
	if(depth[a] < depth[b]) swap(a,b);
	for(int i = 17;i>=0;--i){
		if(depth[a]-depth[b] >= (1<<i)){
			a = parent[a][i];
		}
	}
	if(a==b) return a;

	for(int i = 17; i >= 0; --i){
		if(parent[a][i]!=parent[b][i]){
			a = parent[a][i];
			b = parent[b][i];
		}
	}
	if(a!=b) return parent[a][0];
	return a;
}
int main() {
	memset(depth,-1,sizeof(depth));
	memset(parent,-1,sizeof(parent));
	int start = 0;
	depth[start] = 0;

	inp1(N);
	FOR(i,N-1){
		int a,b;
		inp2(a,b);
		--a;--b;
		adj[a].pb(b);
		adj[b].pb(a);
	}
	dfs(start);
	inp1(M);
	while(M--){
		int a,b;
		inp2(a,b);
		--a;--b;
		printf("%d\n", lca(a,b)+1);
	}
	return 0;	
}