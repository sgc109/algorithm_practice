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

struct vector2{
	ll x,y;
	vector2(ll x, ll y):x(x),y(y){}
	vector2(){}
	bool operator<(const vector2& rhs) const{
		if(y==rhs.y) return x<rhs.x;
		return y<rhs.y;
	}
	vector2 operator-(const vector2& rhs) const {return vector2(x-rhs.x,y-rhs.y);}
	ll cross(const vector2& rhs){return x*rhs.y-y*rhs.x;}
	ll size(){return x*x+y*y;}
};
vector2 base;
ll ccw(vector2& a, vector2& b, vector2& c){
	return (b-a).cross(c-a);
}
bool cmpAngle(pair<vector2,int>& A, pair<vector2,int>& B){
	vector2 lhs=A.first,rhs=B.first;
	vector2 a = lhs-base;
	vector2 b = rhs-base;
	if(!ccw(base,lhs,rhs)) return a.size()<b.size();
	return ccw(base,lhs,rhs)>0;
}
int N,T;
ll a,b;
vector<pair<vector2,int> > points;
int main() {
	for(inp1(T);T--;){
		points.clear();
		inp1(N);
		FOR(i,N){
			scanf("%lld%lld",&a,&b);
			points.pb({vector2{a,b},i});
		}
		sort(all(points));
		base=points[0].first;
		printf("%d ",points[0].second);
		points.erase(points.begin());
		sort(all(points),cmpAngle);
		vector2 s = points.back().first-base;
		int bi;
		for(int i=0;i<sz(points);i++){
			vector2 cur = points[i].first-base;
			if(atan2(s.y,s.x)<=atan2(cur.y,cur.x)) {
				bi=i;
				break;
			}
			printf("%d ",points[i].second);
		}
		for(int i=sz(points)-1;i>=bi;i--) printf("%d ",points[i].second);
		printf("\n");
	}
	return 0;
}