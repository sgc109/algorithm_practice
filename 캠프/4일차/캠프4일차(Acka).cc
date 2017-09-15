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

int S,A,B,C;
int D[53][53][53][53];
int main() {
	inp4(S,A,B,C);
	D[0][0][0][0]=1;
	REP(l,1,S){
		REP(i,0,A){
			REP(j,0,B){
				REP(k,0,C){
					if(i) (D[l][i][j][k]+=D[l-1][i-1][j][k])%=MOD;
					if(i&&j) (D[l][i][j][k]+=D[l-1][i-1][j-1][k])%=MOD;
					if(i&&k) (D[l][i][j][k]+=D[l-1][i-1][j][k-1])%=MOD;
					if(i&&j&&k) (D[l][i][j][k]+=D[l-1][i-1][j-1][k-1])%=MOD;
					if(j) (D[l][i][j][k]+=D[l-1][i][j-1][k])%=MOD;
					if(j&&k) (D[l][i][j][k]+=D[l-1][i][j-1][k-1])%=MOD;
					if(k) (D[l][i][j][k]+=D[l-1][i][j][k-1])%=MOD;
				}
			}
		}
	}
	printf("%lld",D[S][A][B][C]);
	return 0;
}
