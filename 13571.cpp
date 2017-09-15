#include <bits/stdc++.h>
#define REP(i,a,b) for(int i=a;i<=b;++i)
#define FOR(i,n) for(int i=0;i<n;++i)
#define pb push_back
#define all(v) (v).begin(),(v).end()
#define sz(v) ((int)(v).size())
#define inp1(a) scanf("%d",&a)
#define inp2(a,b) scanf("%d%d",&a,&b)
#define inp3(a,b,c) scanf("%d%d%d",&a,&b,&c)
#define inp4(a,b,c,d) scanf("%d%d%d%d",&a,&b,&c,&d)
#define inp5(a,b,c,d,e) scanf("%d%d%d%d%d",&a,&b,&c,&d,&e)
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
typedef vector<int> vi;	
typedef vector<ll> vl;
typedef pair<int,int> pii;
typedef vector<pii> vii;
typedef vector<pll> vll;
typedef vector<vector<int> > vvi;
typedef pair<int,pair<int,int> > piii;
typedef vector<piii> viii;
const double EPSILON = 1e-9;
const double PI = acos(-1);
const int MOD = 1000007;
const int INF = 0x3c3c3c3c;
const long long INFL = 0x3c3c3c3c3c3c3c3c;
const int MAX_N = 102;

int N,K,T;
int dy[] = {-2,-2,-1,-1,1,1,2,2};
int dx[] = {-1,1,-2,2,-2,2,-1,1};
int inRange(int i, int j){
	return 0<=i && i<N && 0<=j && j<N;
}
struct matrix{
	vector<vector<ll> > v;
	int size;
	matrix(){}
	matrix(int sz) : size(sz) {
		v = vector<vector<ll> >(size,vector<ll>(size,0));
	}
	matrix operator*(const matrix& rhs){
		matrix ret(rhs.size);
		FOR(i,size) FOR(j,size) FOR(k,size) (ret.v[i][j] += (v[i][k] * rhs.v[k][j]) % MOD) %= MOD;
		return ret;
	}
	matrix operator-(const matrix& rhs){
		matrix ret(rhs.size());
		FOR(i,size) FOR(j,size) ret.v[i][j] = v[i][j] - rhs.v[i][j];
		return ret;
	}
};
matrix E;
matrix matPow(matrix mat, int n){
	if(n==0) return E;
	if(n%2){
		matrix tmp = matPow(mat,(n-1)/2);
		return tmp*tmp*mat;
	}
	matrix tmp = matPow(mat,n/2);
	return tmp*tmp;
}
int main() {
	inp1(T);
	while(T--){
		inp2(N,K);
		N<<=1;
		E = matrix(N*N);
		FOR(i,N*N) E.v[i][i] = 1;
		matrix start(N*N);
		FOR(i,N*N){
			int hereI = i/N, hereJ = i%N;
			FOR(k,8){
				int nextI = hereI+dy[k], nextJ = hereJ+dx[k];
				if(!inRange(nextI,nextJ)) continue;
				int nextId = nextI*N+nextJ;
				start.v[i][nextId] = 1;
			}
			start.v[i][i] = 1;
		}
		matrix ret = matPow(start,K+1);
		ret = ret - E;
		
	}
	return 0;
}
