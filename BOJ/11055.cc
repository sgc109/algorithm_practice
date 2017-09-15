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

int dp[1002][1002];
int a[1001];

int solve(int prev, int pos) {
	if(pos == n) return 0;
	int ret = 0;

	REP(i,pos,n) {
		if(a[i] > prev) {
			// printf("%d ",a[i]);
			if(dp[a[i]][i+1] == -1) dp[a[i]][i+1] = solve(a[i],i+1);
			if(ret < a[i] + dp[a[i]][i+1]) {
				ret = a[i] + dp[a[i]][i+1];
				// printf("%d ",ret);
			}
			// ret = max(ret, a[i] + dp[a[i]][i+1]);
		}
	}

	return ret;
}

int main() {
	memset(dp,-1,sizeof(dp));
	scanf("%d",&n);
	FOR(i,n) {
		scanf("%d",a+i);
	}
	printf("%d",solve(0,0));
	return 0;
}