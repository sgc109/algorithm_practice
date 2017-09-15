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
ll pow2[100003];
vll v;

int main() {
	inp1(N);
	int cnt = 0;
	FOR(i,N){
		ll a,b;
		scanf("%lld%lld",&a,&b);
		if(a>=b) {
			cnt++;
			continue;
		}
		v.pb({a,1});
		v.pb({b,-1});
	}
	N-=cnt;

	sort(all(v));

	pow2[0] = 1;
	FOR(i,100001) pow2[i+1] = (pow2[i] * 2) % MOD;

	ll sum = 0;
	int on = 0;
	
	FOR(i,sz(v)){
		on += v[i].second;
		if(!on) continue;
		if(i!=sz(v)-1) sum = (sum + (v[i+1].first-v[i].first)*(pow2[on]-1)) % MOD;;
	}

	int prev = 0;
	int cur = 0;
	ll ans = 0;
	on = 0;
	FOR(i,sz(v)){
		on += v[i].second;
		if(v[i].second == 1 && (i == sz(v)-1 || v[i+1].second == -1)){
			cur++;
			ans = (ans + pow2[prev]*(pow2[cur]-1)) % MOD;
			prev += cur;
			cur = 0;
		}
		if(v[i].second == 1 && (i < sz(v)-1 && v[i+1].second == 1)) cur++;
		if(v[i].second == -1) prev--;
	}


	printf("%lld %lld",sum, ans);
	return 0;
}
