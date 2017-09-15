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

int N;
int A[100005];
map<pair<int,int>, long long> dp;
int gcd(int a, int b){
	return b ? gcd(b, a%b) : a;
}
long long go(int pos, int GCD){
	if(pos == N) return GCD == 1;
	auto it = dp.find(make_pair(pos, GCD));
	if(it!=dp.end()) return (*it).second;

	return dp[make_pair(pos, GCD)] = (go(pos+1, !GCD ? A[pos] : gcd(GCD, A[pos])) + go(pos+1, GCD)) % MOD;
}
int main() {
	inp1(N);
	FOR(i,N) inp1(A[i]);
	printf("%lld", go(0,0));
	return 0;
}
