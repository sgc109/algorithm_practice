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

const int MOD = 10000000;
const int INF = 0x3c3c3c3c;
const long long INFL = 0x3c3c3c3c3c3c3c3c;
const int MAX_N = 102;

int dp[MAX_N][MAX_N];
int N;

int solve(int n, int prev){
	if(n==0) return 1;
	int& cache = dp[n][prev];
	if(cache != -1) return cache;
	int ret=0;
	for(int i = 1; i <=n; ++i){
		if(n==N) prev=2-i;
		// printf("n:%d, prev:%d, %d*solve(%d,%d)\n",n,prev,abs(prev-i)+1,n-i,i);
		ret += (abs(prev+i)-1)*solve(n-i,i);
		ret %= MOD;
	}
	return cache = ret;
}
int main() {
	int T;
	inp1(T);
	while(T--){
		memset(dp,-1,sizeof(dp));
		inp1(N);
		printf("%d\n",solve(N,0));
	}
	return 0;
}