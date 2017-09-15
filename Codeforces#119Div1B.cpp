#include <bits/stdc++.h>
#define REP(i,a,b) for(int i=a;i<=b;++i)
#define FOR(i,n) for(int i=0;i<n;++i)
#define pb push_back
#define all(v) (v).begin(),(v).end()
#define sz(v) ((int)(v).size())
#define inp1(a) scanf("%d",&a)
#define inp2(a,b) scanf("%d%d",&a,&b)
#define inp3(a,b,c) scanf("%d%d%d",&a,&b,&c)
#define inp4(a,b,c,d) scanf("%d%d%d%d",&a,&b,&c,&d)
#define inp5(a,b,c,d,e) scanf("%d%d%d%d%d",&a,&b,&c,&d,&e)
#define fastio() ios_base::sync_with_stdio(false),cin.tie(NULL)
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
typedef vector<int> vi;	
typedef vector<ll> vl;
typedef pair<int,int> pii;
typedef vector<pii> vii;
typedef vector<pll> vll;
typedef vector<vector<int> > vvi;
typedef pair<int,pair<int,int> > piii;
typedef vector<piii> viii;
const double EPSILON = 1e-9;
const double PI = acos(-1);
const int MOD = 1e9+7;
const int INF = 0x3c3c3c3c;
const long long INFL = 0x3c3c3c3c3c3c3c3c;
const int MAX_N = 102;

int N,M,R,S,E,K;
int dist[63][63][63];
int dp[1003][63][63];
int main() {
	memset(dp,0x3c,sizeof(dp));
	inp3(N,M,R);
	FOR(m,M){
		FOR(i,N){
			FOR(j,N){
				scanf("%d",&dist[m][i][j]);
			}
		}
	}

	FOR(m,M){
		FOR(k,N){
			FOR(i,N){
				FOR(j,N){
					dist[m][i][j] = min(dist[m][i][j], dist[m][i][k] + dist[m][k][j]);
				}
			}
		}
	}
	FOR(m,M) FOR(i,N) FOR(j,N) dp[0][i][j] = min(dp[0][i][j], dist[m][i][j]);

	REP(l,1,N-1){
		FOR(k,N){
			FOR(i,N){
				FOR(j,N){
					dp[l][i][j] = min(dp[l][i][j],dp[l-1][i][k] + dp[0][k][j]);
				}
			}
		}
	}

	FOR(i,R){
		inp3(S,E,K);
		printf("%d\n",dp[min(N-1,K)][S-1][E-1]);
	}
	return 0;
}
