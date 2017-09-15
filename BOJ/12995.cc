#include <cstdio>
#include <iostream>
#include <vector>
#include <cstring>
#include <queue>
#include <set>
#include <map>
#include <cmath>
#include <algorithm>
#include <utility>
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

vector<int> G[53];
vector<int> T[53];
int N, K, a, b;
ll dp[51][50][51];
ll solve(int here, int child, int cnt) {
	if (sz(T[here]) == child) return cnt == 1;
	ll& ret = dp[here][child][cnt];
	if (ret != -1) return ret;
	ret = 0;
	int there = T[here][child];
	ret += solve(here, child + 1, cnt);
	REP(i,1,cnt-1) {
		(ret += solve(there, 0, i)*solve(here, child + 1, cnt - i))%=MOD;
	}
	return ret;
}
void dfs(int here, int dad) {
	for (auto there : G[here]) {
		if (there == dad) continue;
		T[here].pb(there);
		dfs(there, here);
	}
}
int main() {
	memset(dp, -1, sizeof(dp));
	inp2(N, K);
	FOR(i, N - 1) {
		inp2(a, b);
		G[a].pb(b);
		G[b].pb(a);
	}
	ll ret = 0;
	dfs(1, 0);
	REP(i, 1, N) (ret += solve(i, 0, K))%=MOD;
	printf("%lld", ret);
	return 0;
}
