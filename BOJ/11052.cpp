#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <queue>
#include <utility>
#include <stack>
#include <string.h>
#include <stdlib.h>
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
const int MAX_V = 1001;

int dp[MAX_V];
int cost[MAX_V];
int n;

int main() {
	scanf("%d",&n);
	FOR(i,n) {
		cost[i] = 0;
	}
	REP(i,1,n+1){
		scanf("%d",cost+i);
	}
	dp[1] = cost[1];
	REP(i,2,n+1) {
		dp[i] = cost[i];
		REP(j,1,i) {
			dp[i] = max(dp[i], dp[i-j] + cost[j]);
		}
		// printf("i : %d, minn : %d\n",i,minn);
	}
	printf("%d",dp[n]);
	return 0;
}