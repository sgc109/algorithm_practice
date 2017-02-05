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

ll D[1003][1003];
int K[1003][1003];
int N,M;
ll S[1003];
int A[1003];

int C(int l, int r){
	if(l>=r) return 0;
	return A[r]-A[l-1];
}
int main() {
	inp2(N,M);
	REP(i,1,M) inp1(A[i]);
	sort(A+1,A+M+1);
	A[++M]=N;
	memset(D,0x3c,sizeof(D));
	REP(i,1,M) D[i][i]=0,K[i][i]=i;
	for(int size=2;size<=M;size++){
		for(int i=1;i+size-1<=M;i++){
			int j=i+size-1;
			REP(k,K[i][j-1],K[i+1][j]){
				ll newV=D[i][k]+D[k+1][j]+C(i,j);
				if(D[i][j]>newV) D[i][j]=newV,K[i][j]=k;
			}
		}
	}
	printf("%lld",D[1][M]);
	return 0;
}
