#include <cstdio>
#include <cstring>
const int MOD = 1000000007;
const int MAX_N = 102;
long long dp[MAX_N][MAX_N][MAX_N];
long long solve(int l, int r, int k){
	if(l<=0||r<=0) return 0;
	if(k==1) return (l==1&&r==1);
	long long& cache = dp[l][r][k];
	if(cache!=-1) return cache;
	return cache = (solve(l-1,r,k-1)+solve(l,r-1,k-1)+(k-2)*solve(l,r,k-1))%MOD;
}
int main() {
	memset(dp,-1,sizeof(dp));
	int L,R,N;
	scanf("%d%d%d",&N,&L,&R);
	printf("%lld",solve(L,R,N));
	return 0;
}