#include <bits/stdc++.h>
#define REP(i,a,b) for(int i=a;i<=b;++i)
#define FOR(i,n) for(int i=0;i<n;++i)
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
typedef vector<pair<int,int> > vii;
typedef vector<vector<int> > vvi;
typedef pair<int,int> pii;
typedef pair<int,pair<int,int> > piii;
const double EPSILON = 1e-9;
const double PI = acos(0.0)*2;
const int MOD = 1000000007;
const int INF = 0x3c3c3c3c;
const long long INFL = 0x3c3c3c3c3c3c3c3c;
const int MAX_N = 102;

int T,t;
ll D[303][90003];
ll C[303][303];
int N,M;
int main() {
	freopen("pie_progress.txt","r",stdin);
	freopen("output.txt","w",stdout);
	for(inp1(T),t=0;T-t;t++){
		memset(D,0x3c,sizeof(D));
		memset(C,0,sizeof(C));
		inp2(N,M);
		REP(i,1,N) REP(j,1,M) inp1(C[i][j]);
		REP(i,1,N) sort(C[i]+1,C[i]+M+1);
		REP(i,1,N) REP(j,1,M) C[i][j]+=C[i][j-1];
		D[0][0]=0;
		REP(i,1,N){
			FOR(j,N+1){
				REP(k,0,M){
					D[i][j]=min(D[i][j],D[i-1][j+1-k]+C[i][k]+k*k);
				}
			}
		}
		ll ans=INFL;
		FOR(i,N*M+1) ans=min(ans,D[N][i]);
		printf("Case #%d: %lld\n",t+1,ans);
	}
	return 0;
}
