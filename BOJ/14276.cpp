	#include <bits/stdc++.h>
	using namespace std;
	typedef long long ll;
	const int mod = 1e9+7;
	const int inf = 0x3c3c3c3c;
	const long long infl = 0x3c3c3c3c3c3c3c3c;

	int N,M,K;
	ll dp[33][33][33][1<<9];
	ll go(int u, int v, int k, int mask){
		if(u == N || k == 0) return mask == 0 && k==0;
		if(v==N || v-u > K) {
			if(mask&1) return 0;
			return go(u+1,u+2,k,mask>>1);
		}
		ll& cache = dp[u][v][k][mask];
		if(cache != -1) return cache;

		cache = 0;
		cache = (cache + go(u,v+1,k,mask)) % mod;
		int nextmask = mask^(1<<(v-u));
		nextmask^=1;
		cache = (cache + go(u,v,k-1,nextmask)) % mod;
		return cache;
	}
	int main() {
		memset(dp,-1,sizeof(dp));
		scanf("%d%d%d",&N,&M,&K);
		printf("%lld",go(0,1,M,0));
		return 0;
	}
