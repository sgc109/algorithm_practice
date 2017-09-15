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
// #define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)

using namespace std;

typedef long long ll;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<vector<int> > vvi;
typedef pair<int,int> pii;
typedef pair<int,pair<int,int> > piii;
typedef queue<int> QU;

const int MOD = 1000000007;
const int INF = 0x3c3c3c3c;
const long long INFL = 0x3c3c3c3c3c3c3c3c;
const int MAX_N = 102;

int dp[MAX_N][MAX_N];
int N;
int solve(int n, int pos){
	if(pos==n) return 1;
	if(pos>n) return 0;
	int& cache = dp[n][pos];
	if(cache!=-1) return cache;
	int ret=0;
	return cache = (solve(n,pos+1)+solve(n,pos+2))%MOD;
}
int solve2(int size){
	if(size%2==0) return ((ll)solve(size,0)-solve(size/2,0)-solve(size/2-1,0)+MOD+MOD)%MOD;
	return (solve(size,0)+solve(size/2,0))%MOD;
}
int main() {
	int T;
	inp1(T);
	while(T--){
		memset(dp,-1,sizeof(dp));
		// memset(dp2,-1,sizeof(dp2));
		inp1(N);
		printf("%d\n",solve2(N));
	}
	return 0;
}