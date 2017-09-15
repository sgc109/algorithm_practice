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

const int MOD = 9901;
const int INF = 0x3c3c3c3c;
const long long INFL = 0x3c3c3c3c3c3c3c3c;
const int MAX_N = 102;
const int MAX_2N = (1<<14)-1;

int R,C;
int dp[300][MAX_2N];
int solve(int N, int S){
	S%=(1<<14);
	if(N>=R*C) return 1;
	int& cache = dp[N][S];
	if(cache!=-1) return cache;
	int ret=0;
	if((1<<(C-1))&S) ret += solve(N+1,S*2);
	else {
		if(((N%C)<C-1)&&!((1<<(C-2))&S)) ret += solve(N+2,S*4);
		if((N/C)<R-1) ret += solve(N+1,(S*2)|1);
	}
	return cache = ret%MOD;
}
int main() {
	memset(dp,-1,sizeof(dp));
	inp2(R,C);
	printf("%d",solve(0,0));
	return 0;
}