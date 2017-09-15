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
typedef vector<pair<int,int> > vii;
typedef vector<vector<int> > vvi;
typedef pair<int,int> pii;
typedef pair<int,pair<int,int> > piii;
const double EPSILON = 1e-9;
const double PI = acos(0.0)*2;
const int MOD = 1000000007;
const int INF = 0x3c3c3c3c;
const long long INFL = 0x3c3c3c3c3c3c3c3c;
const int MAX_N = 102;

int T,N,M,S,t;
int umbr[2003];
ll go(ll n, int k){
	if(k==0) return 1;
	if(k%2) return ((n*go(n,(k-1)/2))%MOD*go(n,(k-1)/2))%MOD;
	return (go(n,k/2)*go(n,k/2))%MOD;
}
int main() {
	for(inp1(T),t=0;T-t;t++){
		ll ans=0;
		S=0;
		inp2(N,M);
		FOR(i,N) inp1(umbr[i]),S+=umbr[i];
		for(int i=0;i<N;i++){
			for(int j=i+1;j<N;j++){
				int inner = (S-umbr[i]-umbr[j])*2;
				int outer = M-1-umbr[i]-umbr[j];
				if(inner>outer) continue;
				if(inner==outer) {
					ans+=1;
					continue;
				}
				int r = outer-inner-1;
				int n = N-2+r;
				if(r>n/2) r=n-r;
				ll up=1;
				FOR(i,r) up=(up*(n-i))%MOD;
				ll down=1;
				FOR(i,r) down=(down*(i+1))%MOD;
				down=go(down,MOD-2);
				ans=(ans+(up*down)%MOD)%MOD;
			}
		}
		printf("%lld\n", ans);
	}
	return 0;
}
