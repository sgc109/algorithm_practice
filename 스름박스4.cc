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

class FoxAverageSequence{
public:
	int dp[43][2][43][1603];
	int n;
	vector<int> A;
	int go(int a, int b, int c, int d){
		if(a==n) return 1;
		int& cache = dp[a][b][c][d];
		if(cache!=-1) return cache;
		if(A[a]!=-1) {
			if(d<A[a]*a||(b&&c>A[a])) return cache=0;
			return cache=go(a+1,c>A[a],A[a],d+A[a]);
		}
		int ret=0;
		REP(i,0,40){
			if(d<i*a||(b&&c>i)) continue;
			ret=(ret+go(a+1,c>i,i,d+i))%MOD;
		}
		return cache=ret;
	}
	int theCount(vector<int> seq){
		A=seq;
		n=sz(seq);
		memset(dp,-1,sizeof(dp));
		return go(0,0,0,0);
	}

};