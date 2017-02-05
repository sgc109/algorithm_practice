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
#define all(v) (v).begin(),(v).end()
#define inp1(a) scanf("%d",&a)
#define inp2(a,b) scanf("%d%d",&a,&b)
#define inp3(a,b,c) scanf("%d%d%d",&a,&b,&c)
#define inp4(a,b,c,d) scanf("%d%d%d%d",&a,&b,&c,&d)

using namespace std;

typedef long long ll;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<vector<int> > vvi;
typedef pair<int,int> pii;
typedef pair<int,pair<int,int> > piii;
typedef queue<int> QU;

const int MOD = 1000000007;
const int INF = 0x3c3c3c3c;
const long long INFL = 0x3c3c3c3c3c3c3c3c;
const int MAX_N = 102;

int N,Q;
vi adj[222228];
int depth[222228];
int parent[20][222228];
void dfs(int here, int dad){
	for(int i = 0; depth[here] >= 1<<(i+1); i++){
		parent[i+1][here] = parent[i][parent[i][here]];
	}
	for(int& there : adj[here]){
		if(there == dad) continue;
		depth[there] = depth[here]+1;
		parent[0][there] = here;
		dfs(there,here);
	}
}
int lca(int a, int b){
	if(a==b) return a;
	if(depth[a] < depth[b]) swap(a,b);
	for(int i = 0, diff = depth[a]-depth[b];diff!=0;i++,diff>>=1){
		if(diff&1) a = parent[i][a];
	}
	if(a==b) return a;
	for(int i = 19; i >=0; i--){
		if(parent[i][a]!=parent[i][b]) a = parent[i][a], b = parent[i][b];
	}
	if(a==b) return a;
	return parent[0][a];
}
int main() {
	inp1(N);
	FOR(i,N-1) {
		int a,b;
		inp2(a,b);
		a--;b--;
		adj[a].pb(b);
		adj[b].pb(a);
	}
	dfs(0,-1);
	inp1(Q);
	FOR(i,Q){
		int a,b;
		inp2(a,b);
		a--;b--;
		printf("%d\n",lca(a,b)+1);
	}
	return 0;
}