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

const int MOD = 44444444;
const int INF = 0x3c3c3c3c;
const long long INFL = 0x3c3c3c3c3c3c3c3c;
const int MAX_N = 1002;
int N,K;
ll dp[MAX_N+1][10][MAX_N+1]; // dp(n,num,len) : 길이가 n이고 오른쪽끝이 num이라는 숫자가 len개 반복된 seq의 수(최대 K개의 연속된 수들을 가지고있음)
ll sum[MAX_N]; // sum(i) : 길이가 i 인 최대 K-1개의 연속된수를 갖는 seq들의 수
ll dp2[MAX_N+1][10][MAX_N+1];
int main() {
	memset(dp,0,sizeof(dp));
	memset(dp2,0,sizeof(dp2));
	int ans=0;
	inp2(N,K);
	REP(i,1,10) dp[1][i][1]=1;
	REP(i,1,10) dp2[1][i][1]=(K>1?1:0);
	sum[0]=(K>1?1:0);
	sum[1]=(K>1?9:0);
	REP(i,1,N){
		FOR(j,10){
			REP(k,1,K+1){
				FOR(l,10){
					if(j==l && k<K) dp[i+1][j][k+1]=(dp[i+1][j][k+1]+dp[i][j][k])%MOD;
					if(j!=l) dp[i+1][l][1]=(dp[i+1][l][1]+dp[i][j][k])%MOD;

					if(j==l && k<K-1) dp2[i+1][j][k+1]=(dp2[i+1][j][k+1]+dp2[i][j][k])%MOD;
					if(j!=l) dp2[i+1][l][1]=(dp2[i+1][l][1]+dp2[i][j][k])%MOD;
				}
			}
		}
	}
	// FOR(i,N) printf("sum[%d]:%d\n",i,sum[i]);
	REP(i,1,N+1){
		REP(n,i,N+1){
			FOR(j,10){
				ans=(ans+(dp[i][j][K])*(i!=n?9*(sum[n-i-1]):1))%MOD;
				// printf("i:%d,n:%d,j:%d,k:%d, added:%d\n",i,n,j,K,(dp[i][j][K])*(i!=n?9*(sum-i-1?1:(sum[n-i-1]-dp[n-i-1][j][K])):1));
			}
		}
		// printf("ans:%d\n",ans);
	}
	printf("%lld",ans);
	return 0;
}