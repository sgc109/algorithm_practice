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
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)

using namespace std;

typedef long long ll;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<vector<int> > vvi;
typedef pair<int,int> pii;
typedef pair<int,pair<int,int> > piii;

const int INF = 0x3c3c3c3c;
const long long INFL = 0x3c3c3c3c3c3c3c3c;
const int MAX_N = 1000000;

int n;
int dist[16][16];
int dp[16][1<<16];
int start;
int solve(int from, int visit) {
	if(visit == (1<<n)-1) return dist[from][start] != 0 ? dist[from][start] : INF;
	int ret=INF;
	int unvisited = visit;
	FOR(i,16) {
		if(!(unvisited&1) && dist[from][i] != 0) {
			int& cache = dp[i][visit|(1<<i)];
			if(cache==-1) cache = solve(i,visit|(1<<i));
			ret = min(ret, dist[from][i] + cache);
		}
		unvisited>>=1;
	}
	return ret;
}
int main() {
	memset(dp,-1,sizeof(dp));
	inp1(n);
	FOR(i,n)FOR(j,n)inp1(dist[i][j]);
	start=0;
	int ans = solve(0,1);
	printf("%d",ans);

	return 0;
}