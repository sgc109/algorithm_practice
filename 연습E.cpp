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
#define inp5(a,b,c,d,e) scanf("%d%d%d%d%d",&a,&b,&c,&d,&e)
#define fastio() ios_base::sync_with_stdio(false),cin.tie(NULL)
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
const double PI = acos(-1);
const int MOD = 1e9+7;
const int INF = 0x3c3c3c3c;
const long long INFL = 0x3c3c3c3c3c3c3c3c;
const int MAX_N = 102;

struct vector2{
	double x,y;
	vector2(){}
	vector2(double x, double y): x(x), y(y){}
	double hypot(){
		return sqrt(x*x+y*y);
	}
	double hypotPow(){
		return x*x+y*y;
	}
	double pos(){
		return atan2(y,x);
	}
};
struct circle{
	vector2 pos;
	double r;
	circle(){}
	circle(double x, double y, double r){
		pos.x = x;
		pos.y = y;
		r = r;
	}
};

double X, Y, V, T, R;
int N;
circle circles[100003];
vector<pair<double, double> > seqs;
double sqr(double x){return x*x;}
double findTheta(double a, double b, double c){
	return acos((a*a+b*b-c*c)/(2*a*b));
}
double myCos(double a, double b, double c){
	return (a*a+b*b-c*c)/(2*a*b);
}
int dcmp(double x){
	if(fabs(x) < EPSILON) return 0;
	return x < 0.0 ? -1 : 1;
}

int main() {
	scanf("%lf%lf%lf%lf",&X,&Y,&V,&T);
	R = V*T;
	scanf("%d",&N);
	bool found = false;
	for(int i = 0 ; i < N; i++) {
		scanf("%lf%lf%lf",&circles[i].pos.x, &circles[i].pos.y, &circles[i].r);
		if(found) continue;
		circles[i].pos.x -= X;
		circles[i].pos.y -= Y;
		if(dcmp(sqr(circles[i].pos.x)+sqr(circles[i].pos.y)-sqr(circles[i].r)) <= 0) {
			found = true;
			continue;
		}
	}

	X = Y = 0;
	if(found){
		printf("1.0000000");
		return 0;
	}
	if(dcmp(R) == 0){
		printf("0.0000000");
		return 0;
	}

	vector<pair<double, int> > a;

	for (int i = 0; i < N; i++) {
		double r = circles[i].r;
		double theta;
		double d = circles[i].pos.hypot();
		if(dcmp(circles[i].pos.hypot()-(R+r)) >= 0) continue;
		if(dcmp(d-R) <= 0) theta = asin(r/d);
		else theta = findTheta(d,R,r);
		double angM = circles[i].pos.pos();
		if(dcmp(angM)<=0) angM += 2*PI;
		double angL = angM - theta;
		double angR = angM + theta;

		if (dcmp(angL) < 0) {
			a.push_back(make_pair(angL + 2 * PI, 1));
			a.push_back(make_pair(2 * PI, -1));
			a.push_back(make_pair(0.0, 1));
			a.push_back(make_pair(angR, -1));
		} else if (dcmp(angR - 2*PI) > 0) {
			a.push_back(make_pair(angL, 1));
			a.push_back(make_pair(2 * PI, -1));
			a.push_back(make_pair(0.0, 1));
			a.push_back(make_pair(angR - 2 * PI, -1));
		} else {
			a.push_back(make_pair(angL, 1));
			a.push_back(make_pair(angR, -1));
		}
	}

	sort(a.begin(), a.end());

	double last = 0;
	int c = 0;
	double ans = 0;

	for (auto& p : a) {
		if (c > 0) {
			ans += p.first - last;
		}
		c += p.second;
		last = p.first;
	}

	ans /= 2 * PI;
	printf("%.11f", ans);

	return 0;
}