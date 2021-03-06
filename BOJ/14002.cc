#include <bits/stdc++.h>
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

int dp[1000];
int C[1000];
int N;
int A[1000];
int main() {
	memset(C,-1,sizeof(C));
	inp1(N);
	FOR(i,N) inp1(A[i]);
	FOR(i,N) dp[i]=1;
	for(int i=N-1;i>=0;i--){
		for(int j=i+1;j<N;j++){
			if(A[i]<A[j]) {
				if(dp[i]<dp[j]+1){
					dp[i]=dp[j]+1;
					C[i]=j;
				}
			}
		}
	}
	int ans=-1, maxI;
	FOR(i,N) if(ans<dp[i]) ans=dp[i],maxI=i;
	printf("%d\n",ans);
	for(int p=maxI;p!=-1;p=C[p]) printf("%d ",A[p]);
	return 0;
}
