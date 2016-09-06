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
#define inp1(a) scanf("%d",&a)
#define inp2(a,b) scanf("%d%d",&a,&b)
#define inp3(a,b,c) scanf("%d%d%d",&a,&b,&c)
#define inp4(a,b,c,d) scanf("%d%d%d%d",&a,&b,&c,&d)

using namespace std;

typedef pair<long long, long long> pll;

const int INF = 0x3a3a3a3a;
const long long INFL = 0x3a3a3a3a3a3a3a3a;
const int MAX_N = 1000000;

long long rule[19][19];
long long food[19];

int n,m,k;

long long dp[19][270000];

int countFood(int state) {
	int cnt = 0;
	FOR(i,n) {
		if(state & (1 << i)) ++cnt;
	}

	return cnt;
}

long long solve(int prev, int state) {
	int cnt = countFood(state);
	if(cnt == m) return 0;

	long long ret = -INFL;
	FOR(i,n) {
		if(!(state & (1 << i))) {
			long long& DP = dp[i][state|(1<<i)];
			if(DP == -1) DP = solve(i,state|(1<<i));
			ret = max(ret, food[i] + rule[prev][i] + DP);
		}
	}

	return ret;
}

int main() {
	inp3(n,m,k);
	memset(rule,0,sizeof(rule));
	memset(dp,-1,sizeof(dp));
	FOR(i,n) scanf("%I64d",food+i);
	FOR(i,k) {
		int x,y,c;
		inp3(x,y,c);
		--x;--y;
		rule[x][y] = c;
	}

	printf("%I64d",solve(18,0));
	return 0;
}