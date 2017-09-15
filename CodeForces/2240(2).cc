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
const int MAX_N = 102;

int dp[1002][32][2];
int arr[1002];
int t,w;
int solve(int pos, int move, int side){
	if(pos==t) return 0;
	int& cache = dp[pos][move][side];
	if(cache!=-1) return cache;
	int ret=0;
	if(move>0) ret=max(ret,solve(pos+1,move-1,side^1));
	ret = max(ret,solve(pos+1,move,side));

	return cache = ret+(arr[pos]==side+1);
}
int main() {
	memset(dp,-1,sizeof(dp));
	inp2(t,w);
	FOR(i,t) inp1(arr[i]);
	int ans = solve(0,w,0);
	ans = max(ans,solve(0,w-1,1));
	printf("%d",ans);
	return 0;
}