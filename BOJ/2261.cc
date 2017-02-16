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

struct Point{int x,y;};
bool cmpX(Point& a, Point& b){return a.x<b.x;}
bool cmpY(Point& a, Point& b){return a.y<b.y;}
int sqr(int x) {return x*x;}
int dist(Point& a, Point& b){return sqr(a.x-b.x)+sqr(a.y-b.y);}
Point p[100003];
int d,n,a,b;
void dnc(int l, int r){
	if(l>=r) return;
	int m=(l+r)>>1;
	dnc(l,m);
	dnc(m+1,r);
	vector<Point> vp;
	for(int i=l;i<=r;i++) if(sqr(p[i].x-p[m].x)<d) vp.pb(p[i]);
	sort(all(vp),cmpY);
	for(int i=0;i<sz(vp);i++){
		for(int j=i+1;j<sz(vp)&&sqr(vp[i].y-vp[j].y)<d;j++){
			d=min(d,dist(vp[i],vp[j]));
		}
	}
}
int main() {
	inp1(n);
	FOR(i,n) {
		inp2(a,b);
		p[i]=Point{a,b};
	}
	sort(p,p+n,cmpX);
	d=INF;
	dnc(0,n-1);
	printf("%d",d);
	return 0;
}
