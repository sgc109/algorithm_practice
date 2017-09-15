#pragma comment(linker, "/STACK:2000000")
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
const int MAX_N = 52;
const int MAX_D = 1000010;

int dp[MAX_N][MAX_D];
int n;
int blocks[MAX_N];
int solve(int pos, int diff){
	if(pos==n) return (!diff?0:-INF);
	int& cache = dp[pos][diff+500002];
	if(cache!=-1) return cache;
	int ret = max(blocks[pos]+solve(pos+1,diff+blocks[pos]),solve(pos+1,diff-blocks[pos]));
	ret = max(ret,solve(pos+1,diff));
	return cache = ret;
}
int main() {
	memset(dp,-1,sizeof(dp));
	inp1(n);
	FOR(i,n) inp1(blocks[i]);
	int ans = solve(0,0);
	if(ans<=0) printf("-1");
	else printf("%d",ans);
	return 0;
}