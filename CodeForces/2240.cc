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

int dp[1002][32][2];
int arr[1002];
int main() {
	memset(dp,-1,sizeof(dp));
	int t,w;
	inp2(t,w);
	FOR(i,t) inp1(arr[i]);
	dp[0][w][0]=0;
	FOR(i,t){
		FOR(j,w+1){
			FOR(k,2){
				if(dp[i][j+1][k^1]!=-1 && j!=w) dp[i+1][j][k]=max(dp[i+1][j][k],dp[i][j+1][k^1]+(arr[i]-1==k));
				if(dp[i][j][k]!=-1) dp[i+1][j][k]=max(dp[i+1][j][k],dp[i][j][k]+(arr[i]-1==k));
			}
		}	
	}
	int ans=0;
	FOR(i,w+1)ans=max(ans,max(dp[t][i][0],dp[t][i][1]));
	printf("%d",ans);
	return 0;
}