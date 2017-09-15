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
const int MAX_N = 1003;

int leftCount[MAX_N][MAX_N];
int upCount[MAX_N][MAX_N];
char map[MAX_N][MAX_N];
int dp[MAX_N][MAX_N];
int n,m;
int main() {
	memset(leftCount,0,sizeof(leftCount));
	memset(upCount,0,sizeof(upCount));
	memset(dp,0,sizeof(dp));
	inp2(n,m);
	FOR(i,n)scanf("%s",map[i]);
	// FOR(i,n)printf("%s\n",map[i]);
	int ans=0;
	// FOR(i,n){
	// 	FOR(j,m){
	// 		if(map[i][j]=='0') continue;
	// 		upCount[i][j]=leftCount[i][j]=1;
	// 		if(j!=0) leftCount[i][j]+=leftCount[i][j-1];
	// 		if(i!=0) upCount[i][j]+=upCount[i-1][j];
	// 	}
	// }
	
	// FOR(i,n){
	// 	FOR(j,m){
	// 		dp[i][j]=min((i==0||j==0?1:dp[i-1][j-1]+1),min(upCount[i][j],leftCount[i][j]));
	// 		ans = max(ans, dp[i][j]);
	// 	}
	// }
	FOR(i,n){
		FOR(j,m){
			if(map[i][j]=='0') continue;
			dp[i][j]=1;		
			if(i&&j) dp[i][j]=min(dp[i-1][j-1],min(dp[i-1][j],dp[i][j-1]))+1;
			ans = max(ans, dp[i][j]);
		}
	}
	printf("%d",ans*ans);

	return 0;
}