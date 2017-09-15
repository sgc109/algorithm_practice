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
typedef vector<piii> viii;
const double EPSILON = 1e-9;
const double PI = acos(0.0)*2;
const int MOD = 1000000007;
const int INF = 0x3c3c3c3c;
const long long INFL = 0x3c3c3c3c3c3c3c3c;
const int MAX_N = 102;

ll t[2000003],z[2000003],arr[2000003];
int size,N,M,a,b,c,d;

ll init(int nl, int nr, int nd){
	if(nl==nr) return t[nd]=arr[nl];
	int nm=(nl+nr)>>1;
	return t[nd]=init(nl,nm,nd<<1)^(init(nm+1,nr,nd<<1|1));
}

ll query(int nl, int nr, int l, int r, int nd){
	if(z[nd]) {
		t[nd]^=z[nd];
		if(nl-nr) z[nd<<1]^=z[nd],z[nd<<1|1]^=z[nd];
		z[nd]=0;
	}
	if(l<=nl&&nr<=r) return t[nd];
	if(r<nl||nr<l) return 0;
	int nm=(nl+nr)>>1;
	return query(nl,nm,l,r,nd<<1)^query(nm+1,nr,l,r,nd<<1|1);
} ll query(int l, int r){return query(0,size-1,l,r,1);}

ll update(int nl, int nr, int l, int r, int nd, int v){
	if(z[nd]) {
		t[nd]^=z[nd];
		if(nl-nr) z[nd<<1]^=z[nd],z[nd<<1|1]^=z[nd];
		z[nd]=0;
	}
	if(l<=nl&&nr<=r) {
		if(nr-nl) z[nd<<1]^=v,z[nd<<1|1]^=v;
		return t[nd]^=v;
	}
	if(r<nl||nr<l) return t[nd];
	int nm=(nl+nr)>>1;
	return t[nd]=update(nl,nm,l,r,nd<<1,v)^update(nm+1,nr,l,r,nd<<1|1,v);
} void update(int l, int r, int v){update(0,size-1,l,r,1,v);}

int main() {
	inp1(N);
	FOR(i,N) scanf("%lld",arr+i);
	size=4*N;
	init(0,size-1,1);
	inp1(M);
	while(M--){
		inp3(a,b,c);
		if(a-1) printf("%lld\n",query(b,c));
		else{
			inp1(d);
			update(b,c,d);
		}
	}
	return 0;
}
