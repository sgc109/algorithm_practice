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

ll sqr(ll x){return x*x;}
struct vector2{
	ll x,y;
	vector2(ll x, ll y):x(x),y(y){}
	vector2(){}
	bool operator<(const vector2& rhs) const{
		if(y==rhs.y) return x<rhs.x;
		return y<rhs.y;
	}
	vector2 operator-(const vector2& rhs) const {return vector2(x-rhs.x,y-rhs.y);}
	ll dot(vector2& rhs){return x*rhs.x+y*rhs.y;}
	ll cross(const vector2& rhs){return x*rhs.y-y*rhs.x;}
	ll size(){return x*x+y*y;}
};
vector2 base;
ll ccw(vector2& a, vector2& b){
	return a.cross(b);
}
ll ccw(vector2& a, vector2& b, vector2& c){
	return (b-a).cross(c-a);
}
bool cmpAngle(vector2& lhs, vector2& rhs){
	vector2 unit = vector2(1,0);
	vector2 a = lhs-base;
	vector2 b = rhs-base;
	if(!ccw(base,lhs,rhs)) return a.size()<b.size();
	return ccw(base,lhs,rhs)>0;
}
ll dist(vector2& a, vector2& b){
	return sqr(a.x-b.x)+sqr(a.y-b.y);
}
int N,T;
ll a,b;
vector<vector2> points;
vector<vector2> poly;
int main() {
	inp1(N);
	FOR(i,N){
		scanf("%lld%lld",&a,&b);
		points.pb(vector2{a,b});
	}
	sort(all(points));
	base=points[0];
	points.erase(points.begin());
	sort(all(points),cmpAngle);
	poly.pb(base);
	for(int i=0;i<sz(points);i++){
		while(poly.size()>=2&&ccw(poly[poly.size()-2],poly.back(),points[i])<=0) poly.pop_back();
		poly.pb(points[i]);
	}
	vector2 ansA,ansB;
	ll d=0;

	ll ans=-1;
	vector2 p1,p2;
	int j=1;
	FOR(i,sz(poly)){
		int ni = (i+1)%sz(poly);
		for(;;){
			int nj = (j+1)%sz(poly);
			vector2 v1 = poly[ni]-poly[i], v2 = poly[nj]-poly[j];
			if(ccw(v1,v2)<=0) break;
			else j=nj;
		}
		ans=max(ans,dist(poly[i],poly[j]));
	}
	printf("%.7lf",sqrt(ans));
	return 0;
}