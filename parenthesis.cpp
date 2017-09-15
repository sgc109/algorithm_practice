#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod = 1e9+7;
const int inf = 0x3c3c3c3c;
const long long infl = 0x3c3c3c3c3c3c3c3c;

ll dp[53][53];
int N;
ll go(int pos, int open){
	if(pos == N) return open==0;
	ll& cache = dp[pos][open];
	if(cache != -1) return cache;
	cache = 0;
	cache += go(pos+1, open+1);
	if(open>0) cache += go(pos+1,open-1);
	return cache;
}

int main() {
	memset(dp,-1,sizeof(dp));
	scanf("%d",&N);
	printf("%lld",go(0,0));
	return 0;
}
