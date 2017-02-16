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
struct Circle{
	ll x,y,r;
};

int T,W,N,a,b,c;
Circle cir[1003];
int p[1003],h[1003];
vector<pair<double,pair<int,int> > > edges;
int find(int here){
	if(p[here]==here) return here;
	return p[here]=find(p[here]);
}
void merge(int a, int b){
	a=find(a),b=find(b);
	if(a==b) return;
	if(h[a]<h[b]) swap(a,b);
	p[b]=a;
	if(h[a]==h[b]) h[a]++;
}
ll sqr(ll x) {return x*x;}
double dist(Circle& lhs, Circle& rhs){
	return sqrt(sqr(lhs.x-rhs.x)+sqr(lhs.y-rhs.y))-lhs.r-rhs.r;
}
int main() {
	for(inp1(T);T--;){
		edges.clear();
		inp2(W,N);
		FOR(i,N){
			inp3(a,b,c);
			cir[i]=Circle{a,b,c};
		}
		FOR(i,N+2) p[i]=i,h[i]=1;
		FOR(i,N){
			REP(j,i+1,N-1){
				if(dist(cir[i],cir[j])<=0) merge(i+2,j+2);
				else edges.pb({dist(cir[i],cir[j]),{i+2,j+2}});
			}
			if(cir[i].x-cir[i].r<=0) merge(i+2,0);
			else edges.pb({cir[i].x-cir[i].r,{i+2,0}});
			if(W-cir[i].x-cir[i].r<=0) merge(i+2,1);
			else edges.pb({W-cir[i].x-cir[i].r,{i+2,1}});
		}
		edges.pb({W,{0,1}});
		sort(all(edges));
		double ans=-1;
		for(auto e : edges){
			if(find(0)==find(1)) break;
			merge(e.second.first,e.second.second);
			ans=e.first;
		}
		if(ans==-1) printf("0\n");
		else printf("%.7lf\n",ans/2);
	}
	return 0;
}
