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

ll t[103],pSum[103];
ll D[103][103][2];
int N,T,S;
ll C(int l, int r){
	return pSum[r]-pSum[l-1];
}
int main() {
	memset(D,0x3c,sizeof(D));
	D[0][0][0]=D[0][0][1]=0;
	for(inp1(T);T--;){
		inp2(N,S);
		REP(i,1,N-1) scanf("%lld",t+i),pSum[i]=pSum[i-1]+t[i];
		REP(i,0,S-1){
			REP(j,0,N-S){
				if(!i&&!j) continue;
				if(i>0) D[i][j][0]=min(D[i-1][j][0]+(N-i-j)*C(S-i,S-i),D[i-1][j][1]+(N-i-j)*C(S-i,S+j-1));
				if(j>0) D[i][j][1]=min(D[i][j-1][0]+(N-i-j)*C(S-i,S+j-1),D[i][j-1][1]+(N-i-j)*C(S+j-1,S+j-1));
			}
		}
		printf("%lld\n",min(D[S-1][N-S][0],D[S-1][N-S][1]));
	}
	return 0;
}