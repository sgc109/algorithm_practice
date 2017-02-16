#include <iostream>
#include <algorithm>
#include <utility>
#include <cstring>
#include <cstdio>
#include <vector>
#include <cmath>
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
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef pair<int, int> pii;
typedef vector<pii> vii;
typedef vector<pll> vll;
typedef vector<vector<int> > vvi;
typedef pair<int, pair<int, int> > piii;
typedef vector<piii> viii;
const double EPSILON = 1e-9;
const double PI = acos(0.0) * 2;
const int MOD = 1000000007;
const int INF = 0x3c3c3c3c;
const long long INFL = 0x3c3c3c3c3c3c3c3c;
const int MAX_N = 102;

int N, a, b;
int man[10003];
vi G[10003];
int dp[10003][2];
void dfs(int here, int dad) {
	dp[here][1]=man[here];
	dp[here][0]=0;
	for(int there : G[here]){
		if(there==dad) continue;
		dfs(there,here);
		dp[here][0]+=max(dp[there][0],dp[there][1]);
		dp[here][1]+=dp[there][0];
	}
}
int main() {
	inp1(N);
	REP(i, 1, N) inp1(man[i]);
	FOR(i, N - 1) {
		inp2(a, b);
		G[a].pb(b);
		G[b].pb(a);
	}
	dfs(1, 0);
	printf("%d", max(dp[1][0],dp[1][1]));
	return 0;
}
