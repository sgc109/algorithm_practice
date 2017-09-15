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
const int MAX_N = 1002;
const int MAX_D = 100010;

int A[MAX_N],B[MAX_N];
int n;
int dp[2][MAX_D];
int b[2][MAX_D];
int calcB(){
	int Bsum=0;
	FOR(i,n) Bsum+=B[i];
	b[0][0]=Bsum;
	FOR(i,n){
		FOR(j,MAXD){
			if(j-A[i]>=0) b[(i+1)%2][j]=min(b[(i+1)%2][j],b[i%2][j-A[i]]-B[i]);
			b[(i+1)%2][j] = min(b[(i+1)%2][j],b[i%2][j]);
		}
	}
}
int solve(){
	dp[0][0] = max(0,b[n%2][0]);
	FOR(i,n){
		FOR(j,MAX_D){
			dp[(i+1)%2][j+A[i]]=min(dp[(i+1)%2][j+A[i]],max(j+A[i],b[i%2][j+A[i]]));
			dp[(i+1)%2][j] = min(dp[(i+1)%2][j],dp[i%2][j]);
		}
	}
}
int main() {
	int T;
	inp1(T);
	while(T--){
		memset(dp,0x3c,sizeof(dp));
		memset(b,0x3c,sizeof(b));
		inp1(n);
		FOR(i,n) inp2(A[i],B[i]);
		calcB();
		solve();
		int ans = INF;
		FOR(i,MAX_D) ans = min(ans, dp[n%2][i]);
		printf("%d\n",ans);
	}
	return 0;
}