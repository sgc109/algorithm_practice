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
const int MAX_N = 502;

int dp[MAX_N][MAX_N];

int n;

int map[MAX_N][MAX_N];

int dx[4] = {0,1,-1,0};
int dy[4] = {1,0,0,-1};

bool inRange(int i, int j) {
	if(0 <= i && i < n && 0 <= j && j < n) return true;
	return false;
}

int solve(int posI, int posJ) {
	// printf("posI: %d, posJ: %d\n",posI,posJ);

	int ret = 1;
	int curCost = map[posI][posJ];
	FOR(i,4) {
		int newI = posI + dy[i];
		int newJ = posJ + dx[i];
		if(inRange(newI,newJ) && curCost < map[newI][newJ]) {
			if(dp[newI][newJ] == -1) dp[newI][newJ] = solve(newI,newJ);
			ret = max(ret, 1+dp[newI][newJ]);
		}
	}
	return ret;
}

int main() {
	inp1(n);
	memset(dp,-1,sizeof(dp));
	FOR(i,n)FOR(j,n)inp1(map[i][j]);
	int ans = 0;
	FOR(i,n) {
		FOR(j,n) {
			if(dp[i][j] == -1) dp[i][j] = solve(i,j);
			ans = max(ans, dp[i][j]);
		}
	}

	printf("%d",ans);
	return 0;
}