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

int X,Y,D,T;
double sqr(double x){return x*x;}
double ans1,ans2,ans3;
double dist(double x, double y){
	return sqrt(sqr(x)+sqr(y));
}
int main() {
	while(scanf("%d%d%d%d",&X,&Y,&D,&T)!=-1){
		double d = dist(X,Y);
		ans1 = d;
		double in,out;
		int n;
		if(d<D){
			ans2=D-d+T;
			ans3=2*T;
		}
		else {
			for(n=0, out=0.0; out<d; out+=D, n++){}
			in = out-D;
			ans2 = min(d-in+(n-1)*T,out-d+n*T);
			ans3 = n*T;
		}
		printf("%.13lf\n",min({ans1,ans2,ans3}));
	}

	return 0;
}
