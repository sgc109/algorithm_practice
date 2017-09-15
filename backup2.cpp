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
set<ll> st;
vll range;
vl comp;
ll t[800003];
ll pow2[100003];
int size;

void update(int pos, int v){
	while(pos <= size){
		t[pos] += v;
		pos += pos&-pos;
	}
}

ll query(int pos){
	ll ret = 0;
	while(pos > 0){
		ret += t[pos];
		pos -= pos&-pos;
	}
	return ret;
}

bool cmp(pll& A, pll& B){
	if(A.second != B.second) return A.second < B.second;
	return A.first < B.first;
}

int main() {
	inp1(N);
	FOR(i,N){
		ll a,b;
		scanf("%lld%lld",&a,&b);
		st.insert(a), st.insert(b);
		range.pb({a,b});
	}
	for(auto it = st.begin() ; it != st.end(); it++){
		comp.pb((*it));
	}
	size = sz(comp);

	FOR(i,N){
		ll& a = range[i].first;
		ll& b = range[i].second;
		a = lower_bound(all(comp),a) - comp.begin() + 1;
		b = lower_bound(all(comp),b) - comp.begin() + 1;
	}
	sort(all(range),cmp);

	pow2[0] = 1;
	FOR(i,100001) pow2[i+1] = (pow2[i] * 2) % MOD;

	FOR(i,N){
		update(range[i].first,1);
	}

	ll ans = 0;

	FOR(i,N){
		update(range[i].first,-1);
		ans = (ans + pow2[query(range[i].second-1)]) % MOD;
	}
	
	printf("%lld",ans);
	return 0;
}
