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

const int MOD = 201
;
const int INF = 0x3c3c3c3c;
const long long INFL = 0x3c3c3c3c3c3c3c3c;
const int MAX_N = 102;

int price[MAX_N];
int like[MAX_N];
int dp[MOD];
int n,m;
int main() {
	int T;
	inp1(T);
	while(T--){
		memset(dp,0,sizeof(dp));
		inp2(n,m);
		m/=100;
		FOR(i,n) {
			inp2(price[i],like[i]);
			price[i]/=100;
		}
		dp[0]=0;
		FOR(i,m+1){
			FOR(j,n){
				if(i-price[j]<0) continue;
				dp[i%MOD]=max(dp[i%MOD],dp[(i-price[j])%MOD]+like[j]);
			}
		}
		printf("%d\n",dp[m%MOD]);
	}
	return 0;
}