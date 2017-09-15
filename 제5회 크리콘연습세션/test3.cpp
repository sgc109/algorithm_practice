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
#define fastio() ios_base::sync_with_stdio(false),cin.tie(NULL)
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

int N,P;
ll A[1000003];
ll sum[1003];
ll go(int x, int n){
	if(!x) return 0;
	if(n==0) return 1;
	if(n%2){
		ll tmp = go(x,(n-1)/2);
		return (x*tmp*tmp)%P;
	}
	ll tmp = go(x,n/2);
	return (tmp*tmp)%P;
}

int main() {
	inp2(N,P);
	FOR(i,N+1) scanf("%lld",A+i);
	if(P==1){
		printf("%lld",A[N]);
		return 0;
	}
	FOR(i,N+1) sum[i%(P-1)] += A[N-i];
	sum[0] -= A[N];
	FOR(i,P){
		ll ans = 0;
		FOR(j,P){
			ans = (ans + go(i, j) * sum[j]) % P;
		}
		printf("%lld\n",(ans+A[N])%P);
	}

	return 0;
}
