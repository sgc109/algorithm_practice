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
int cnt[222228];
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
void dfs2(int here, int dad){
	for(int& there : adj[here]){
		if(there == dad) continue;
		dfs2(there,here);
		cnt[here]+=cnt[there];
	}
}
int main() {
	int root;
	inp2(N,Q);
	FOR(i,N-1) {
		int a,b;
		inp2(a,b);
		a--;b--;
		adj[a].pb(b);
		adj[b].pb(a);
		if(i==0) root=a;
	}
	dfs(root,-1);
	FOR(i,Q){
		int a,b;
		inp2(a,b);
		a--;b--;
		cnt[a]++;cnt[b]++;
		cnt[lca(a,b)]-=2;
	}
	dfs2(root,-1);
	int maxCnt=-1;
	FOR(i,N) maxCnt = max(maxCnt,cnt[i]);
	pii minP = mp(INF,INF);
	FOR(i,N) {
		if(i==0) continue;
		if(cnt[i]==maxCnt) {
			int a = i;
			int b = parent[0][i];
			if(a < b) swap(a,b);
			if(minP > mp(b,a)) minP = mp(b,a);
		}
	}
	printf("%d %d %d",minP.first+1,minP.second+1,maxCnt);
	return 0;
}