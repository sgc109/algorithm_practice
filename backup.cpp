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
set<int> st;
vll range;
vl comp;
ll d[800003];
ll t[800003];
ll pow2[100003];
int size;

void update(int nl, int nr, int l, int r, int node){
	if(d[node]){
		t[node] = (t[node] * pow2[d[node]]) % MOD;
		if(nr-nl) d[2*node] += d[node], d[2*node+1] += d[node];
	}
	if(nr < l || r < nl) return;
	if(l <= nl && nr <= r){
		t[node]*=2;
		if(nr-nl) d[2*node]++,d[2*node+1]++;
		return;
	}
	int nm = (nl+nr)>>1;
	update(nl, nm, l, r, 2*node);
	update(nm+1, nr, l, r, 2*node);
	t[node] = (t[2*node] + t[2*node+1]) % MOD;
}

ll query(int nl, int nr, int l, int r, int node){
	if(d[node]){
		t[node] = (t[node] * pow2[d[node]]) % MOD;
		if(nr-nl) d[2*node] += d[node], d[2*node+1] += d[node];
	}
	if(nr < l || r < nr) return 0;
	if(l <= nl && nr <= r) return t[node];
	int nm = (nl+nr)>>1;
	return (query(nl, nm, l, r, 2*node) | query(nm+1, nr, l, r, 2*node+1)) % MOD;
}

void update(int l, int r){
	update(0, size-1, l, r, 1);
}

ll query(int l, int r){
	return query(0, size-1, l, r, 1);
}

ll go(int pos, int last){
	
	return 0;
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


	
	return 0;
}
