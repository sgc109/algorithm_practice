#include <iostream>
#include <cstdio>
#include <queue>
#include <utility>
#include <vector>
#include <cstring>
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
const int MOD = 1000000007;
const int INF = 0x3c3c3c3c;
const long long INFL = 0x3c3c3c3c3c3c3c3c;
const int MAX_N = 102;

int N, a, b;
vi G[100003];
int dp[100003][5];
int dfs(int here, int dad, int dadC) {
	int ret = INF;
	int& cache = dp[here][dadC];
	if (cache != -1) return cache;
	REP(i, 1, 4) {
		if (i == dadC) continue;
		int sum=i;
		for (int there : G[here]) {
			if (there == dad) continue;
			sum += dfs(there, here, i);
		}
		ret=min(ret,sum);
	}
	return cache = ret;
}
int main() {
	memset(dp, -1, sizeof(dp));
	inp1(N);
	FOR(i, N - 1) {
		inp2(a, b);
		G[a].pb(b);
		G[b].pb(a);
	}
	dfs(1, 0, 0);
	printf("%d", dp[1][0]);
	return 0;
}
