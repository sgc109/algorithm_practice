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
const int MAX_N = 1002;

int pLeft[MAX_N], pRight[MAX_N];
int pLeftRight[MAX_N][MAX_N];
int n,m;
int w[MAX_N], pos[MAX_N];
ll dp[MAX_N][MAX_N][2];
ll solve(int left, int right, int side){
	if(left<0 || right<0) return INFL;
	if(left==0 && right==0) return 0;
	ll& cache = dp[left][right][side];
	if(cache!=-1) return cache;
	ll ret=min(solve(left-1,right,0)+(!left?0:pLeftRight[left][right]*(!side?pos[left]-pos[left-1]:pos[n-right-1]-pos[left-1])),solve(left,right-1,1)+(!right?0:pLeftRight[left][right]*(!side?pos[n-right]-pos[left]:pos[n-right]-pos[n-right-1])));
	return cache = ret;
}
int main() {
	memset(dp,-1,sizeof(dp));
	inp2(n,m);
	FOR(i,n) inp2(pos[i],w[i]);
	FOR(i,n) pLeft[i+1] = pLeft[i]+w[i];
	FOR(i,n) pRight[i+1] = pRight[i]+w[n-i-1];
	FOR(i,n+1) FOR(j,n+1) pLeftRight[i][j] = pLeft[i]+pRight[j];
	printf("%lld",solve(m-1,n-m,0));
	return 0;
}