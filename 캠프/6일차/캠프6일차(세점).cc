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

vii v;
ll ap[300003];
ll t1[300003],t2[300003];
int N;
void update(ll *ft, int x, ll v){
	while(x<=N){
		ft[x]+=v;
		x+=x&-x;
	}
}
ll query(ll *ft, int x){
	ll ret=0;
	while(x>0){
		ret+=ft[x];
		x-=x&-x;
	}
	return ret;
}
int a,b;
int idxs[300003];
int main() {
	inp1(N);
	v.pb({-INF,-INF});
	REP(i,1,N){
		inp2(a,b);
		v.pb({b,a});
	}
	sort(all(v));
	REP(i,1,N) v[i]={v[i].second,i};
	sort(all(v));
	for(int i=N;i>=1;i--){
		idxs[v[i].second]=i;
		ap[i]=query(t1,N)-query(t1,v[i].second);
		update(t1,v[i].second,1);
	}	
	ll ans=0;
	for(int i=N;i>=1;i--){
		ans+=(ap[idxs[i]]*(ap[idxs[i]]-1)/2)-((query(t2,N)-query(t2,idxs[i])));
		update(t2,idxs[i],ap[idxs[i]]);
	}
	printf("%lld\n",ans);
	return 0;
}
