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

int n,k;
int l,r;
int order[21];
int dp[21][21][21];
int solve(int i, int left, int right){
	if(i==k) return 0;
	int ret;
	if(order[i] < left) {
		// printf("(1)i:%d, left:%d, right:%d, %d\n",i,left,right,left-order[i]);
		int& cache = dp[i+1][order[i]][right];
		if(cache==-1) cache=solve(i+1,order[i],right);
		ret = left-order[i]+cache;
	}
	else if(order[i] == left || order[i] == right) {
		// printf("(2)i:%d, left:%d, right:%d, %d\n",i,left,right,0);
		int& cache = dp[i+1][left][right];
		if(cache==-1) cache=solve(i+1,left,right);
		ret = cache;
	}
	else if(left < order[i] && order[i] < right) {
		// printf("(3)i:%d, left:%d, right:%d, %d\n",i,left,right,order[i]-left);
		int& cache1 = dp[i+1][order[i]][right];
		if(cache1==-1) cache1 = solve(i+1,order[i],right);
		ret = order[i]-left+cache1;
		// printf("(3)i:%d, left:%d, right:%d, %d\n",i,left,right,right-order[i]);
		int& cache2 = dp[i+1][left][order[i]];
		if(cache2==-1) cache2 = solve(i+1,left,order[i]);
		ret = min(ret, right-order[i]+cache2);
	}
	else {
		// printf("(4)i:%d, left:%d, right:%d, %d\n",i,left,right,order[i]-right);
		int& cache = dp[i+1][left][order[i]];
		if(cache==-1) cache=solve(i+1,left,order[i]);
		ret = order[i]-right+cache;
	}
	return ret;
}
int main() {
	memset(dp,-1,sizeof(dp));
	inp1(n);
	inp2(l,r);
	if(l > r) swap(l,r);
	inp1(k);
	FOR(i,k){
		inp1(order[i]);
	}
	printf("%d",solve(0,l,r));
	return 0;
}