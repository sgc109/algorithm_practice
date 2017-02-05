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

int D[503][503];
int N;
int L[503],R[503];
int main() {
	inp1(N);
	FOR(i,N){
		inp2(L[i],R[i]);
	}
	memset(D,0x3c,sizeof(D));
	FOR(i,N) D[i][i]=0;
	for(int size=2; size<=N; size++){
		for(int i=0;i+size<=N; i++){
			int j=i+size-1;
			for(int k=i;k<=j-1;k++){
				D[i][j]=min(D[i][j],D[i][k]+D[k+1][j]+L[i]*R[k]*R[j]);
			}
		}
	}
	printf("%d",D[0][N-1]);
	return 0;
}
