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

ll N,K;
vl divisors;
int size;
int main() {
	scanf("%lld%lld",&N,&K);

	if(K>1e9){
		printf("-1");
		return 0;
	}
	ll ans = -1;
	for(ll i = 1; i * i <= N; i++){
		if(N%i==0){
			divisors.pb(i);
			if(i != N/i) divisors.pb(N/i);
		}
	}
	sort(all(divisors));
	FOR(i,sz(divisors)){
		if(divisors[i] >= K*(K+1)/2) {
			ans = divisors[i];
			break;
		}
	}
	if(ans==-1) {
		printf("-1");
		return 0;
	}
	for(ll i = 1; i <= K; i++){
		if(i!=K){
			printf("%lld ",i*(N/ans));
		}
		else {
			printf("%lld ",(ans-(K*(K-1)/2))*(N/ans));
		}
	}
	return 0;
}
