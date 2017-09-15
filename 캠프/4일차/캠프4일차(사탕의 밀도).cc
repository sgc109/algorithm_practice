#include <bits/stdc++.h>
#define REP(i,a,b) for(int i=a;i<=b;++i)
#define FOR(i,n) for(int i=0;i<n;++i)
// #define mp make_pair
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
typedef vector<pair<int,int> > vii;
typedef vector<vector<int> > vvi;
typedef pair<int,int> pii;
typedef pair<int,pair<int,int> > piii;
typedef queue<int> QU;

const double EPSILON = 1e-9;
const double PI = acos(0.0)*2;
const int MOD = 1000000007;
const int INF = 0x3c3c3c3c;
const long long INFL = 0x3c3c3c3c3c3c3c3c;
const int MAX_N = 102;

int N;
double C[53],W[53];
double diffSum(double d){
	double ret=0;
	FOR(i,N){
		ret+=fabs(W[i]-C[i]*d);
	}
	return ret;
}
int main() {
	inp1(N);
	FOR(i,N) scanf("%lf",C+i);
	FOR(i,N) scanf("%lf",W+i);
	double ans=INFL;
	FOR(i,N){
		ans=min(ans,diffSum(W[i]/C[i]));
	}
	printf("%.10lf",ans);
	return 0;
}
