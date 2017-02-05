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

const int MOD = 5;
const int INF = 0x3c3c3c3c;
const long long INFL = 0x3c3c3c3c3c3c3c3c;
const int MAX_N = 52;
const int MAX_K = 1000002;

int n,K,m;
int playTime[MAX_N];
double prob[MAX_N][MAX_N];
double dp[MOD][MAX_N];
int favors[12];
int main() {
	int T;
	inp1(T);
	while(T--){
		FOR(i,MOD) FOR(j,MAX_N) dp[i][j]=0.0;
		inp3(n,K,m);
		FOR(i,n) inp1(playTime[i]);
		FOR(i,n) FOR(j,n) scanf("%lf",&prob[i][j]);
		FOR(i,m) inp1(favors[i]);
		dp[0][0]=1.0;
		REP(i,1,K+1){
			FOR(j,n) dp[i%MOD][j]=0.0;
			FOR(j,n){
				FOR(k,n){
					if(i-playTime[k]<0) continue;
					dp[i%MOD][j]+=dp[(i-playTime[k])%MOD][k]*prob[k][j];
				}
			}
		}
		FOR(i,m){
			double ans=0.0;
			FOR(j,playTime[favors[i]]){
				if(K-j<0)continue;
				ans+=dp[(K-j)%MOD][favors[i]];
			}
			printf("%.8lf ",ans);
		}
		printf("\n");
	}
	return 0;
}