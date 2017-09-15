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
#include <deque>
#include <assert.h>
// #include <unordered_set>
// #include <map>
#define REP(i,a,b) for(int i = a; i <= b;++i)
#define FOR(i,n) REP(i,0,n-1)
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

const double EPSILON = 1e-9;
const double PI = acos(0.0)*2;
const int MOD = 1000000007;
const int INF = 0x3c3c3c3c;
const long long INFL = 0x3c3c3c3c3c3c3c3c;
const int MAX_N = 102;

ll dp[5003][5003];
int K[5003][5003];
ll pSum[5003];
int A[5003];
int n;
int T;
ll solve(int l, int r){
	if (l > r) return 0;
	if(l==r) {
		K[l][l]=l;
		return 0;
	}
	ll& cache = dp[l][r];
	if(cache!=-1) return cache;
	cache = INFL;
	ll ret = INFL;
	solve(l,r-1);
	solve(l+1,r);

	for(int k=K[l][r-1];k<=K[l+1][r];k++){
		ll newV = solve(l,k)+solve(k+1,r)+pSum[r]-pSum[l-1];
		if(ret>newV) ret=newV,K[l][r]=k;
	}
	return cache=ret;
}
int main() {
	for(inp1(T);T--;){
		memset(dp,-1,sizeof(dp));
		inp1(n);
		FOR(i,n) inp1(A[i+1]),pSum[i+1]=pSum[i]+A[i+1];
		printf("%lld\n",solve(1,n));
	}
	return 0;
}
