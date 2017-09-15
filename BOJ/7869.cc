#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <queue>
#include <utility>
#include <stack>
#include <cstring>
#include <cstdlib>
#include <string>
#include <set>
#include <cmath>
// #include <unordered_set>
// #include <map>
#define REP(i,a,b) for(int i = a; i < b;++i)
#define FOR(i,n) REP(i,0,n)
#define mp make_pair
#define pb push_back
#define all(v) (v).begin(),(v).end()
#define inp1(a) scanf("%d",&a)
#define inp2(a,b) scanf("%d%d",&a,&b)
#define inp3(a,b,c) scanf("%d%d%d",&a,&b,&c)
#define inp4(a,b,c,d) scanf("%d%d%d%d",&a,&b,&c,&d)

using namespace std;

typedef long long ll;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<vector<int> > vvi;
typedef pair<int,int> pii;
typedef pair<int,pair<int,int> > piii;
typedef queue<int> QU;

const int MOD = 1000000007;
const int INF = 0x3c3c3c3c;
const long long INFL = 0x3c3c3c3c3c3c3c3c;
const int MAX_N = 102;

const double PI=acos(0.0)*2;
double pow2(double x){return x*x;}
double dist(double x1, double y1, double x2, double y2){return sqrt(pow2(x1-x2)+pow2(y1-y2));}
double p;
double sinn(double r1, double r2){
	double x=(pow2(r1)+pow2(p)-pow2(r2))/(2*r1*p);
	printf("x:%lf\n",x);
	return 2*sqrt(1-pow2(x))*x;
}
double x[2],y[2],r[2];
int main() {
	FOR(i,2){
		scanf("%lf%lf%lf",&x[i],&y[i],&r[i]);
	}
	if(r[0]>r[1]){
		swap(x[0],x[1]);
		swap(y[0],y[1]);
		swap(r[0],r[1]);
	}
	p=dist(x[0],y[0],x[1],y[1]);
	if(r[0]+r[1]<p){
		printf("0.000\n");
		return 0;
	}
	else if(r[1]<=p){
		double sin1=sinn(r[0],r[1]);
		double sin2=sinn(r[1],r[0]);
		double ans1=(pow2(r[0])/2)*(asin(sin1)-sin1);
		double ans2=(pow2(r[1])/2)*(asin(sin2)-sin2);
		printf("%.3lf",ans1+ans2);
	}
	else if(p<=r[1]-r[0]){
		printf("%.3lf\n",pow2(r[0])*PI);
	}
	else {
		double cosa=(pow2(r[0])+pow2(r[1])-pow2(p))/(2*r[0]*r[1]);
		double cosb=(pow2(r[1])+pow2(p)-pow2(r[0]))/(2*r[1]*p);
		double sina=sqrt(1-pow2(cosa));
		double sinb=sqrt(1-pow2(cosb));
		double sinn=2*(sina*cosb+cosa*sinb)*(cosa*cosb-sina*sinb);
		double sin2b=2*sinb*cosb;
		double ans=(pow2(r[1])/2)*(asin(sin2b)-sin2b);
		ans+=(pow2(r[0])*sinn/2);
		ans+=(pow2(r[0])*(2*PI-asin(sinn))/2);
		printf("%.3lf\n",ans);
	}
	return 0;
}
