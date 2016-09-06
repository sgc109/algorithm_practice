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
const int MAX_N = 1000000;

int n;

int dp[10][1002];

int solve(int prev, int i) {
	if(i == n) return 1;
	int ret = 0;
	REP(k,prev,10) {
		if(dp[k][i+1] == -1) dp[k][i+1] = solve(k,i+1);
		ret = (ret + dp[k][i+1]) % 10007;
	}

	return ret;
}

int main() {
	memset(dp,-1,sizeof(dp));
	scanf("%d",&n);
	printf("%d",solve(0,0));
	return 0;
}