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
const int MAX_N = 102;

struct myLR{
	int l,r;
};
int n;
myLR lr[16];
int t[16][101];
int dp[102][1<<16];
int solve(int day, int done){
	if(day>100) return 0;
	int& cache = dp[day][done];
	if(cache!=-1) return cache;

	int ret=0;
	FOR(i,n){
		if(done&(1<<i)||day<lr[i].l||lr[i].r<day||lr[i].r<day+t[i][day-lr[i].l]-1) continue;
		ret=max(ret,1+solve(day+t[i][day-lr[i].l]-1,done|(1<<i)));
	}
	ret=max(ret,solve(day+1,done));
	return cache=ret;
}
int main() {
	memset(dp,-1,sizeof(dp));
	inp1(n);
	FOR(i,n){
		int l,r;
		inp2(l,r);
		lr[i]={l,r};
		FOR(j,r-l+1) inp1(t[i][j]);
	}
	cout << solve(1,0);
	return 0;
}
