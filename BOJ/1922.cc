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

int N,M,a,b,c;
viii edges;
int p[1003],h[1003];
int find(int here){
	if(p[here]==here) return here;
	return p[here]=find(p[here]);
}
void merge(int a, int b){
	a=find(a),b=find(b);
	if(h[a]<h[b]) swap(a,b);
	p[b]=a;
	if(h[a]==h[b]) h[a]++;
}
int main() {
	inp2(N,M);
	REP(i,1,N) p[i]=i,h[i]=1;
	FOR(i,M){
		inp3(a,b,c);
		edges.pb({c,{a,b}});
	}
	ll ans=0;
	sort(all(edges));
	for(auto e : edges){
		int u = e.second.first, v = e.second.second;
		int cost = e.first;
		if(find(u)==find(v)) continue;
		ans+=cost;
		merge(u,v);
	}
	printf("%lld",ans);
	return 0;
}
