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

int N;
int X[60003];
int V[60003];
double go(double pos){
	double ret=-1;
	FOR(i,N){
		ret=max(ret,fabs(pos-X[i])/V[i]);
	}
	return ret;
}
int main() {
	inp1(N);
	FOR(i,N) inp1(X[i]);
	FOR(i,N) inp1(V[i]);
	double lo=0,hi=1e9+1;
	FOR(i,100){
		double mid1 = lo*2/3+hi/3;
		double mid2 = lo/3+2*hi/3;
		if(go(mid1)<go(mid2)) hi = mid2;
		else lo = mid1;
	}
	printf("%.9lf",go(lo));
	return 0;
}
