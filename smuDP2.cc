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

class SameDigits{
public:
	ll dp[MAX_N][MAX_N][2];
	ll sum[MAX_N];
	int howMany(int n, int k){
		memset(dp,0,sizeof(dp));
		inp2(n,k);
		dp[0][1][(k==1)]=9;
		if(k==1) sum[0]=9;
		FOR(i,n-1){
			REP(j,1,min(k+1,i+2)){
				dp[i+1][1][0]+=dp[i][j][0]*9;
				dp[i+1][1][0]%=MOD;
				dp[i+1][1][1]+=dp[i][j][1]*9;
				dp[i+1][1][1]%=MOD;
				if(j<k) dp[i+1][j+1][0]+=(j<k-1?dp[i][j][0]:0), dp[i+1][j+1][0]%=MOD;
				if(j<k) dp[i+1][j+1][1]+=(j==k-1?dp[i][j][0]:0)+dp[i][j][1], dp[i+1][j+1][1]%=MOD;
			}
		}
		ll ans=0;
		FOR(i,n){
			REP(j,1,k+1){
				ans+=dp[i][j][1];
				ans%=MOD;
			}
		}
		return (int)ans;

	}
};
int main(){
	SameDigits obj;
	printf("%d",obj.howMany(723,38));

	return 0;
}