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
const int MAX_N = 1002;
const int MAX_M = 1002;

int rangeSum[MAX_N][MAX_M];
int map[MAX_N][MAX_M];
int n,m;
int dp[MAX_N][MAX_M][3];
enum{FROMUP=0,FROMLEFT,FROMRIGHT};
int solve(int hereI, int hereJ, int from){
	if(hereI==n-1) return rangeSum[n-1][m-1]-(hereJ?rangeSum[n-1][hereJ-1]:0);
	int& cache = dp[hereI][hereJ][from];
	if(cache != -1) return cache;
	int ret=-INF;
	if((from==FROMUP||from==FROMRIGHT)&&hereJ>0) ret=max(ret,map[hereI][hereJ]+solve(hereI,hereJ-1,FROMRIGHT));
	if((from==FROMUP||from==FROMLEFT)&&hereJ<m-1) ret=max(ret,map[hereI][hereJ]+solve(hereI,hereJ+1,FROMLEFT));
	ret=max(ret,map[hereI][hereJ]+solve(hereI+1,hereJ,FROMUP));
	return cache = ret;
}

int main() {
	memset(dp,-1,sizeof(dp));
	inp2(n,m);
	FOR(i,n){
		FOR(j,m){
			inp1(map[i][j]);
			if(j==0) rangeSum[i][j] = map[i][j];
			else rangeSum[i][j] = rangeSum[i][j-1] + map[i][j];
		}
	}
	printf("%d",solve(0,0,FROMUP));


	return 0;
}