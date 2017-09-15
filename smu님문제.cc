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
// #include <unordered_set>
// #include <map>
#define REP(i,a,b) for(int i = a; i < b;++i) 
#define FOR(i,n) REP(i,0,n)
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

const int MOD = 1000000007;
const int INF = 0x3c3c3c3c;
const long long INFL = 0x3c3c3c3c3c3c3c3c;
const int MAX_N = 102;

int main() {
	ll n,m,k;
	scanf("%lld%lld%lld",&n,&m,&k);
	vector<pll> v;
	while(m--){
		ll l,r,d;
		scanf("%lld%lld%lld",&l,&r,&d);
		v.pb(mp(l,d));
		v.pb(mp(r+1,-d));
	}
	v.pb(mp(1,0));
	v.pb(mp(n+1,0));
	sort(v.begin(),v.end());
	ll ans=0;
	ll cur=0;
	FOR(i,v.size()){
		if(i==v.size()-1) break;
		cur+=v[i].second;
		if(v[i].first==v[i+1].first) continue;
		if(cur==k) ans+=v[i+1].first-v[i].first;
	}
	printf("%lld",ans);
	return 0;
}