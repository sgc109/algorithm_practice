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
const double EPSILON = 1e-9;
const double PI = acos(0.0)*2;
const int MOD = 1000000007;
const int INF = 0x3c3c3c3c;
const long long INFL = 0x3c3c3c3c3c3c3c3c;
const int MAX_N = 102;

ll N;
int K;
ll go(ll n, int k){
	if(k==0) return 1;
	if(k%2) return ((n*go(n,(k-1)/2))%MOD*go(n,(k-1)/2))%MOD;
	return (go(n,k/2)*go(n,k/2))%MOD;
}
int main() {
	cin >> K >> N;
	ll up=1;
	REP(i,1,K+1){
		up=(up*(N+i-1))%MOD;
	}
	ll down=1;
	REP(i,1,K+1) down=(down*i)%MOD;
	down = go(down,MOD-2);
	
	printf("%lld",(up*down)%MOD);
	return 0;
}
