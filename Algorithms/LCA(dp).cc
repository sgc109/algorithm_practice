#include <bits/stdc++.h>
#define REP(i,a,b) for(int i=a;i<=b;++i)
#define FOR(i,n) for(int i=0;i<n;++i)
#define pb push_back
#define all(v) (v).begin(),(v).end()
#define sz(v) ((int)(v).size())
#define inp1(a) scanf("%d",&a)
#define inp2(a,b) scanf("%d%d",&a,&b)
#define inp3(a,b,c) scanf("%d%d%d",&a,&b,&c)
#define inp4(a,b,c,d) scanf("%d%d%d%d",&a,&b,&c,&d)
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef pair<int,int> pii;
typedef vector<pii> vii;
typedef vector<pll> vll;
typedef vector<vector<int> > vvi;
typedef pair<int,pair<int,int> > piii;
const double EPSILON = 1e-9;
const double PI = acos(0.0)*2;
const int MOD = 1000000007;
const int INF = 0x3c3c3c3c;
const long long INFL = 0x3c3c3c3c3c3c3c3c;
const int MAX_N = 102;

int p[100003][18],depth[100003];
vi G[100003];
int N,root;
int lca(int a, int b){
	if(a==b) return a;
	if(depth[a]>depth[b]) swap(a,b);
	int diff=depth[b]-depth[a];
	for(int i=0;diff;diff>>=1,i++){
		if(diff&1) b=p[b][i];
	}
	if(a==b) return a;
	for(int i=17;i>=0;i--){
		if(p[a][i]!=p[b][i]) a=p[a][i],b=p[b][i];
	}
	if(a==b) return a;
	return p[a][0];
}
void dfs(int here, int dad){
	for(int i=1;i<depth[here];i++) p[here][i]=p[p[here][i-1]][i-1];
	for(auto there:G[here]){
		if(there==dad) continue;
		p[there][0]=here;
		depth[there]=depth[here]+1;
		dfs(there,here);
	}
	return;
}
int main() {
	root=1;
	inp1(N);
	FOR(i,N-1){
		int u,v;
		inp2(u,v);
		G[u].pb(v);
		G[v].pb(u);
	}
	dfs(1,0);
	return 0;
}
