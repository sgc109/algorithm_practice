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
const int MOD = 1000003;
const int INF = 0x3c3c3c3c;
const long long INFL = 0x3c3c3c3c3c3c3c3c;

int N,S,E,T;
int M;
int G[13][13];

struct matrix{
	vector<vector<ll> > v;
	int size;
	matrix(){}
	matrix(int sz):size(sz){
		v = vector<vector<ll> >(size, vector<ll>(size, 0));
	}
	matrix operator*(const matrix& rhs){
		matrix ret(size);
		FOR(i,size) FOR(j,size) FOR(k,size) (ret.v[i][j] += (v[i][k]*rhs.v[k][j]) % MOD) %= MOD;
		return ret;
	}
};

matrix matE;
matrix matPow(matrix mat, int n){
	if(n==0) return matE;
	if(n%2) {
		matrix tmp = matPow(mat, (n-1)/2);
		return mat*tmp*tmp;
	}
	matrix tmp = matPow(mat, n/2);
	return tmp*tmp;
}

ll dp[6][10];
int main() {
	inp4(N,S,E,T);
	S--,E--;
	FOR(i,N) FOR(j,N) scanf("%1d",&G[i][j]);

	queue<pii> q;
	q.push({S,0});
	while(!q.empty()){
		int here = q.front().first;
		int t = q.front().second;
		q.pop();
		if(t >= 6) continue;
		dp[t][here]++;
		FOR(there, N){
			if(!G[here][there]) continue;
			q.push({there,t+G[here][there]});
		}
	}

	M = 5*N;
	matE = matrix(M);
	FOR(i,matE.v.size()) matE.v[i][i] = 1;

	matrix start(M);
	FOR(i,N){
		int row = 4*N + i;
		FOR(j,N){
			if(!G[j][i]) continue;
			int col = (5-G[j][i])*N+j;
			start.v[row][col] = 1;
		}
	}
	FOR(i,4*N) start.v[i][i+N] = 1;

	matrix ret = matPow(start, T);

	ll ans = 0;
	FOR(i,M) (ans += (ret.v[E][i]*dp[i/N][i%N]) % MOD) %= MOD;
	printf("%lld\n",ans);

	return 0;
}
