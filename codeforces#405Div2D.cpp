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
#define inp5(a,b,c,d,e) scanf("%d%d%d%d%d",&a,&b,&c,&d,&e)
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
typedef vector<piii> viii;
const double EPSILON = 1e-9;
const double PI = acos(-1);
const int MOD = 1e9+7;
const int INF = 0x3c3c3c3c;
const long long INFL = 0x3c3c3c3c3c3c3c3c;
const int MAX_N = 102;

int N,M,a,b;
vi G[200003];
ll size[200003];
ll dp[200003][5];
ll ans;
void dfs(int here, int dad){
	size[here] = 0;
	dp[here][0]++;
	for(int there : G[here]){
		if(there == dad) continue;
		dfs(there, here);
		FOR(i,M){
			FOR(j,M){
				int k = i+j+1;
				ans += (M-((k%M)?(k%M):M)) * dp[here][i] * dp[there][j];
			}
		}
		FOR(i,M) dp[here][(i+1)%M] += dp[there][i];
		ans += size[there]*(N-size[there]);
		size[here] += size[there];
	}
	size[here]++;
}
int main() {
	inp2(N,M);
	FOR(i,N-1){
		inp2(a,b);
		a--,b--;
		G[a].pb(b);
		G[b].pb(a);
	}
	dfs(0,-1);
	printf("%lld",ans/M);
	return 0;
}
