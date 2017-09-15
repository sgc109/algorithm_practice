#include <bits/stdc++.h>
#define REP(i,a,b) for(int i=a;i<=b;++i)
#define FOR(i,n) for(int i=0;i<n;++i)
// #define mp make_pair
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
typedef queue<int> QU;

const double EPSILON = 1e-9;
const double PI = acos(0.0)*2;
const int MOD = 1000000007;
const int INF = 0x3c3c3c3c;
const long long INFL = 0x3c3c3c3c3c3c3c3c;
const int MAX_N = 102;

int N;
ll A[203];
ll D[203][203][2];
int i;
int L,R;
int main() {
	inp1(N);
	FOR(i,N) scanf("%lld",A+i);
	for(i=0;i<N;i++) if(A[i]>0) break;
	L=i,R=N-L;
	A[N++]=0;
	sort(A,A+N);
	memset(D,0x3c,sizeof(D));
	D[0][0][1]=D[0][0][0]=0;
	REP(i,0,L){
		REP(j,0,R){
			if(i>0) D[i][j][0]=min(D[i-1][j][0]+(N-i-j)*(A[L-i+1]-A[L-i]),D[i-1][j][1]+(N-i-j)*(A[L+j]-A[L-i]));
			if(j>0) D[i][j][1]=min(D[i][j-1][0]+(N-i-j)*(A[L+j]-A[L-i]),D[i][j-1][1]+(N-i-j)*(A[L+j]-A[L+j-1]));
		}
	}
	printf("%lld",min(D[L][R][0],D[L][R][1]));
	return 0;
}
