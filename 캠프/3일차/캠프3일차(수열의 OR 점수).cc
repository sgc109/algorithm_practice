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

ll D[5003][5003];
int K[5003][5003];
int pSum[5003][32];
int C[5003][5003];
int A[5003];
int N,M;
void DNC(int i, int l, int r, int p, int q){
	if(l>r) return;
	int m=(l+r)>>1;
	for(int k=p;k<=q&&k<m;k++){
		if(D[i][m]<D[i-1][k]+C[k+1][m]) D[i][m]=D[i-1][k]+C[k+1][m],K[i][m]=k;
	}
	DNC(i,l,m-1,p,K[i][m]);
	DNC(i,m+1,r,K[i][m],q);
}
int main() {
	inp2(N,M);
	REP(i,1,N) {
		inp1(A[i]);
		FOR(j,32) pSum[i][j]=pSum[i-1][j]+(A[i]&(1<<j)?1:0);
	}
	REP(i,1,N) {
		int tmp=A[i];
		REP(j,i,N) {
			tmp|=A[j];
			C[i][j]=tmp;
		}
	}
	REP(i,1,M) DNC(i,1,N,0,N-1);
	printf("%lld",D[M][N]);
	return 0;
}
