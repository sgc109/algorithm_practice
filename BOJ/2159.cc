#include <iostream>
#include <cstdio>
#include <cstring>
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
typedef pair<int,int> pii;

const int MOD = 1000000007;
const int INF = 0x3c3c3c3c;
const long long INFL = 0x3c3c3c3c3c3c3c3c;
const int MAX_N = 100002;

int dy[5] = {-1,0,0,0,1};
int dx[5] = {0,-1,0,1,0};
int n;
pii spot[MAX_N+1];
ll dp[2][5]; // dp(pos,dir) : 현재 pos 까지 방문했고 dir방향에 있을 때 지금까지의 최단거리
int main() {
	memset(dp,0x3c,sizeof(dp));
	inp1(n);
	FOR(i,n+1){
		int a,b;
		inp2(a,b);
		spot[i]=mp(a,b);
	}
	dp[0][2] = 0;
	FOR(i,n){
		FOR(j,5){
			dp[(i+1)%2][j] = INFL;
			FOR(k,5){
				int preX = spot[i].first+dx[k];
				int preY = spot[i].second+dy[k];
				int nextX = spot[i+1].first+dx[j];
				int nextY = spot[i+1].second+dy[j];
				dp[(i+1)%2][j] = min(dp[(i+1)%2][j],dp[i%2][k]+abs(preX-nextX)+abs(preY-nextY));
			}
		}
	}
	ll ans=INFL;
	FOR(i,5) ans=min(ans,dp[n%2][i]);
	printf("%lld",ans);

	return 0;
}