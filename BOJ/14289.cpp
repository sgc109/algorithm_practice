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
const int MOD = 1e9+7;
const int INF = 0x3c3c3c3c;
const long long INFL = 0x3c3c3c3c3c3c3c3c;
const int MAX_N = 102;

int N,M,D,a,b;
vi G[53];
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
	inp2(N,M);
	E = matrix(N);
	FOR(i,N) E.v[i][i] = 1;
	FOR(i,M){
		inp2(a,b);
		a--,b--;
		G[a].pb(b);
		G[b].pb(a);
	}
	inp1(D);
	matrix start(N);
	FOR(i,N) for(int j : G[i]) start.v[i][j] = 1;
	matrix ret = matPow(start,D);
	printf("%lld",ret.v[0][0]);
	return 0;
}
