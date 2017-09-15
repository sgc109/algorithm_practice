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
typedef vector<piii> viii;
const double EPSILON = 1e-9;
const double PI = acos(0.0)*2;
const int MOD = 1000000007;
const int INF = 0x3c3c3c3c;
const long long INFL = 0x3c3c3c3c3c3c3c3c;
const int MAX_N = 102;

int K,N,e;
int ans;
int dp[2100000];
int E[2100000];
int dfs(int here, int dad){
	int& cache = dp[here];
	if(cache!=-1) return cache;
	if(here>=((N+1)/2)) return cache=0;
	int ret=max(dfs(here*2,here)+E[here*2-2],dfs(here*2+1,here)+E[here*2-1]);
	ans+=ret-(E[here*2-2]+dp[here*2]);
	ans+=ret-(E[here*2-1]+dp[here*2+1]);
	return cache=ret;
}
int main() {
	memset(dp,-1,sizeof(dp));
	inp1(K);
	N=(1<<(K+1))-1;
	FOR(i,N-1){
		inp1(E[i]);
		ans+=E[i];
	}
	dfs(1,0);
	printf("%d",ans);
	return 0;
}
