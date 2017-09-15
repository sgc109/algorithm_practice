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

struct Point{ll x,y;};
int N;
ll flowers[2003];
ll rx1,ry1,rx2,ry2;
Point points[2003];
pll distFrom[2003];
ll t[5000];
ll sqr(ll a) {return a*a;}
void init(){
	FOR(i,N) t[N+i]=distFrom[i].second;
	for(int i=N-1;i>=1;i--) t[i]=max(t[i<<1],t[i<<1|1]);
}
ll query(int l, int r) {
	ll ret = 0;
	for (l += N, r += N; l <= r; l >>= 1, r >>= 1) {
		if (l&1) ret = max(ret,t[l++]);
		if (!(r&1)) ret = max(ret,t[r--]);
	}
	return ret;
}
void update(int pos, ll val){
	for(t[pos+=N]=val;pos>1;pos>>=1){
		t[pos>>1]=t[pos]+t[pos^1];
	}
}
int main() {
	cin >> N >> rx1 >> ry1 >> rx2 >> ry2;
	FOR(i,N){
		cin >> points[i].x >> points[i].y;
		distFrom[i]={sqr(points[i].x-rx1)+sqr(points[i].y-ry1),sqr(points[i].x-rx2)+sqr(points[i].y-ry2)};
	}
	sort(distFrom,distFrom+N);
	init();
	ll ans=query(0,N-1);
	FOR(i,N){
		ans=min(ans,distFrom[i].first+query(i+1,N-1));
	}
	printf("%lld",ans);
	return 0;
}
