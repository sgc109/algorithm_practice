#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod = 1e9+7;
const int inf = 0x3c3c3c3c;
const long long infl = 0x3c3c3c3c3c3c3c3c;

int N;
ll fact[100003];
ll dp[100003][2];
ll go(int size, int empty){
	if(size == 2) return 1;
	if(size == 1) return empty;
	ll& cache = dp[size][empty];
	if(cache != -1) return cache;
	cache = 0;
	if(empty) cache = (go(size-1,0) + (size-1)*go(size-1,1)%mod) % mod;
	else cache = (size-1)*(go(size-2,0)%mod + (size-2)*go(size-2,1)%mod)%mod;
	return cache;
}
int main() {
	memset(dp,-1,sizeof(dp));
	scanf("%d",&N);
	fact[0] = 1;
	for(int i = 0 ; i < 100002; i++) fact[i+1] = fact[i]*(i+1)%mod;
	printf("%lld",go(N,0)*fact[N]%mod);
	return 0;
}
