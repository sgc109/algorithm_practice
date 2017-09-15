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
#include <deque>
// #include <unordered_set>
// #include <map>
#define REP(i,a,b) for(int i = a; i <= b;++i)
#define FOR(i,n) REP(i,0,n-1)
#define mp make_pair
#define pb push_back
#define all(v) (v).begin(),(v).end()
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

const double EPSILON = 1e-9;
const double PI = acos(0.0)*2;
const int MOD = 1000000007;
const int INF = 0x3c3c3c3c;
const long long INFL = 0x3c3c3c3c3c3c3c3c;
const int MAX_N = 102;

int N,K;
vector<pair<int,double> > adj;
int main() {
	inp2(N,K);
	FOR(i,N) scanf("%s",in[i]);
	FOR(i,N) FOR(j,N) dist[i][j]=in[i][j]-'0';
	REP(i,0,K) FOR(j,N) dp[i][j]=INFL;
	dp[0][0]=0;
	FOR(i,N-1){
		FOR(here,N){
			FOR(there,N){
				dp[0][there]=min(dp[0][there],dp[0][here]+dist[here][there]);
			}
		}
	}
	REP(i,1,K){
		FOR(here,N){
			FOR(there,N){
				dp[i][there]=min(dp[i][there],dp[i-1][here]+dist[here][there]/2);
			}
		}
	}
	double ans=INF;
	for(int i=0;i<=K;i++) ans=min(ans,dp[i][1]);
		printf("%.10lf",ans);
	return 0;
}
