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
#include <unordered_set>
#include <set>
#define REP(i,a,b) for(int i = a; i < b;++i) 
#define FOR(i,n) REP(i,0,n)
#define mp make_pair
#define pb push_back

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef pair<ll, ll> llll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<vector<int> > vvi;
typedef vector<ii> vii;
	
const int INF = 0x3a3a3a3a;
const long long INFL = 0x3a3a3a3a3a3a3a3a;
const int MAX_N = 1000000;

long long dp[102][102][102];
int n,m,k;

int color[102];
int cost[102][102];

long long solve(int prev, int pos, int changable) {
	long long ret = INFL;
	if(changable < 0) return INFL;
	if(pos == n) {
		if(changable == 0) return 0;
		else return INFL;
	}

	if(color[pos] != 0) {
		long long& DP = dp[color[pos]][pos+1][(prev != color[pos])?changable-1:changable];
		if(DP == -1) {
			DP = solve(color[pos],pos+1,(prev != color[pos])?changable-1:changable);
		}
		return DP;
	}

	REP(i,1,m+1) {
		long long& DP = dp[i][pos+1][(prev != i)?changable-1:changable];
		if(DP == -1) DP = solve(i,pos+1,(prev != i)?changable-1:changable);
		ret = min(ret , cost[pos][i-1] + DP);
	}

	return ret;
}

int main() {
	memset(dp,-1,sizeof(dp));
	scanf("%d%d%d",&n,&m,&k);
	FOR(i,n) {
		scanf("%d",color+i);
	}
	FOR(i,n) {
		FOR(j,m) {
			scanf("%d",&cost[i][j]);
		}
	}

	long long ans = solve(-1,0,k);
	if(ans == INFL) printf("-1");
	else printf("%I64d",ans);
	return 0;
}