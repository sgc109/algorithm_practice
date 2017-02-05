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

ll bitAX[1000002],bitB[1000002];
ll A[1000002];
int o,l,r;
ll c;
int N,M,K;
void update(ll* t, int pos, ll add){
	while(pos<=N){
		t[pos]+=add;
		pos+=pos&-pos;
	}
}
ll query(ll* t, int pos){
	ll ret=0;
	while(pos>0){
		ret+=t[pos];
		pos-=pos&-pos;
	}
	return ret;
}
ll query(int l, int r){
	return query(bitAX,r)*r-query(bitAX,l-1)*(l-1)+query(bitB,r)-query(bitB,l-1);
}
void update(int l, int r, ll v){
	update(bitAX,l,v);
	update(bitAX,r+1,-v);
	update(bitB,l,-v*(l-1));
	update(bitB,r+1,v*r);
}
int main() {
	ios::sync_with_stdio(false);
	cin >> N >> M >> K;
	FOR(i,N) cin >> A[i];
	FOR(i,N) update(bitB,i+1,A[i]);
	FOR(i,M+K){
		cin >> o;
		if(o-1){
			cin >> l >> r;
			cout << query(l,r) << "\n";
		}
		else {
			cin >> l >> r >> c;
			update(l,r,c);
		}
	}
	return 0;
}
