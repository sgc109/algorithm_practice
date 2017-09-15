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
#include <deque>
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

const double EPSILON = 1e-9;
const double PI = acos(0.0)*2;
const int MOD = 1000000007;
const int INF = 0x3c3c3c3c;
const long long INFL = 0x3c3c3c3c3c3c3c3c;
const int MAX_N = 52;

int n,C;
double X[MAX_N];
double t[MAX_N];
bool poss(double limit){
	double siz = 0;
	FOR(i,n){
		siz+=(X[i]-limit)*t[i];
		if(siz>C) return false;
		if(siz<0) siz=0;
	}
	return true;
}
int main() {
	inp2(n,C);
	FOR(i,n) scanf("%lf",t+i);
	FOR(i,n) scanf("%lf",X+i);
	double lo=0,hi=1e12+1;
	while(fabs(hi-lo)>1e-9) {
		double mid = (hi+lo)/2;
		if(poss(mid)) hi=mid;
		else lo=mid;
	}
	printf("%.16lf",lo);
	return 0;
}
