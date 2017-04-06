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

int n;
int scores[MAX_N];
int dp[MAX_N][MAX_N];
int solve(int l, int r){
	int& cache = dp[l][r];
	if(cache!=-1) return cache;
	if(l>r) return cache=0;

	int ret=-INF;
	if(r-l+1>=2) {
		ret=max(ret,-solve(l+2,r));
		ret=max(ret,-solve(l,r-2));
	}
	ret=max(ret,scores[l]-solve(l+1,r));
	ret=max(ret,scores[r]-solve(l,r-1));
	return cache=ret;	
}
int main() {
	int T;
	inp1(T);
	while(T--){
		memset(dp,-1,sizeof(dp));
		inp1(n);
		FOR(i,n) inp1(scores[i]);
		int ans = solve(0,n-1);
		printf("%d\n",ans);
	}
	return 0;
}