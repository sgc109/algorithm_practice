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
ll ccw(vector2& a, vector2& b, vector2& c){
    ll x = (b-a).cross(c-a);
    if(!x) return 0;
    if(x>0) return 1;
    return -1;
}
bool cmpAngle(vector2& lhs, vector2& rhs){
    vector2 unit = vector2(1,0);
    vector2 a = lhs-base;
    vector2 b = rhs-base;
    if(!ccw(base,lhs,rhs)) return a.size()<b.size();
    return ccw(base,lhs,rhs)>0;
}
void getConvexHull(vector<vector2>& poly, vector<vector2>& points){
    sort(all(points));
    base=points[0];
    points.erase(points.begin());
    sort(all(points),cmpAngle);
    poly.pb(base);
    for(int i=0;i<sz(points);i++){
        while(poly.size()>=2&&ccw(poly[poly.size()-2],poly.back(),points[i])<=0) poly.pop_back();
        poly.pb(points[i]);
    }
}
double crossX(vector2& u, vector2& v, vector2& p){
    if(v.y==u.y) {
        if(u.y==p.y) return p.x;
        return INFL;
    }
    return (double)(p.y-v.y)*(v.x-u.x)/(v.y-u.y)+v.x;
}
bool inRange(vector2& l, vector2& m, vector2& r){
    return min(l.x,r.x)<=m.x&&m.x<=max(l.x,r.x)&&min(l.y,r.y)<=m.y&&m.y<=max(l.y,r.y);
}
bool isOverlap(vector<vector2>& poly1, vector<vector2>& poly2){
    for(int pNum=0; pNum<sz(poly1);pNum++){
        vector2 p = poly1[pNum];
        int passed=0;
        for(int u=0; u<sz(poly2);u++){
            int v=(u+1)%(sz(poly2));
            double atX = crossX(poly2[u],poly2[v],p);
            if(p.x==atX && inRange(poly2[u],p,poly2[v])) return true;
            if((poly2[u].y>p.y)!=(poly2[v].y>p.y)){
                if(atX > p.x) passed++;
            }
        }
        if(passed%2) return true;
    }
    return false;
}
bool isReach(vector2& a, vector2& b, vector2& c, vector2& d){
    if(b<a) swap(a,b);
    if(d<c) swap(c,d);
    int cond1 = ccw(d,c,a)*ccw(d,c,b);
    int cond2 = ccw(b,a,c)*ccw(b,a,d);
    if(!cond1&&!cond2) return !(b<c || d<a);
    return cond1<=0 && cond2<=0;
}
bool isLine(vector<vector2>& vv){
    return sz(vv)==2;
}
int N,M,T;
ll a,b;
vector<vector2> points;
vector<vector2> poly1,poly2;
int main() {
    points.clear();
    poly1.clear();
    poly2.clear();
    inp2(N,M);
    FOR(i,N){
        scanf("%lld%lld",&a,&b);
        points.pb(vector2{a,b});
    }
    getConvexHull(poly1,points);
    points.clear();
    FOR(i,M){
        scanf("%lld%lld",&a,&b);
        points.pb(vector2{a,b});    
    }
    getConvexHull(poly2,points);
    bool isNo=false;
    
    if(isOverlap(poly1,poly2)||isOverlap(poly2,poly1)) isNo=true;
    FOR(i,sz(poly1)){
        int ni = (i+1)%sz(poly1);
        FOR(j,sz(poly2)){
            int nj = (j+1)%sz(poly2);
            if(isReach(poly1[i],poly1[ni],poly2[j],poly2[nj])) isNo=true;
        }
    }
    if(isNo) printf("NO\n");
    else printf("YES\n");
    return 0;
}