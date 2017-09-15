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

int A[4003][4003];
ll C[4003][4003];
ll pSumX[4003][4003],pSumY[4003][4003];
int N,M;
ll D[803][4003];
int K[803][4003];

void DC(int i, int s, int e, int p, int q){
	if(s>e) return;
	int m=(s+e)>>1;
	for(int k=p;k<=q&&k<m;k++){
		ll nv = D[i-1][k]+C[k+1][m]/2;
		if(D[i][m]>nv) D[i][m]=nv,K[i][m]=k;
	}
	DC(i,s,m-1,p,K[i][m]);
	DC(i,m+1,e,K[i][m],q);
}
int main() {
	inp2(N,M);
	REP(i,1,N) REP(j,1,N) inp1(A[i][j]), pSumX[i][j]=pSumX[i][j-1]+A[i][j];
	REP(i,1,N) REP(j,1,N) pSumY[i][j]=pSumY[i][j-1]+A[j][i];
	REP(i,1,N) {
		REP(j,i,N) {
			C[i][j]=C[i][j-1]+pSumX[j][j]-pSumX[j][i-1]+pSumY[j][j]-pSumY[j][i-1]-A[j][j];
		}
	}
	memset(D,0x3c,sizeof(D));
	D[0][0]=0;
	REP(i,1,M) DC(i,1,N,i-1,N-1);
	printf("%lld",D[M][N]);
	return 0;
}
