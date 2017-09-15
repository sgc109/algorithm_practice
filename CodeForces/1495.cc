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
// #include <unordered_set>
// #include <map>
#define REP(i,a,b) for(int i = a; i < b;++i) 
#define FOR(i,n) REP(i,0,n)
#define mp make_pair
#define pb push_back
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

const int MOD = 1000000007;
const int INF = 0x3c3c3c3c;
const long long INFL = 0x3c3c3c3c3c3c3c3c;
const int MAX_N = 102;

int n,s,m;
int arr[MAX_N];
int dp[102][1002];
int main() {
	inp3(n,s,m);
	FOR(i,n) inp1(arr[i]);
	dp[0][s]=1;
	FOR(i,n){
		FOR(j,m+1){
			if(j-arr[i]>=0) dp[i+1][j]|=dp[i][j-arr[i]];
			if(j+arr[i]<=m) dp[i+1][j]|=dp[i][j+arr[i]];
		}
	}
	int ans=-1;
	FOR(i,m+1) if(dp[n][i])ans=max(ans,i);
	printf("%d",ans); 
	return 0;
}