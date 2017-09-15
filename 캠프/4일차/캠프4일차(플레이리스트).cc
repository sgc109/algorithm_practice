#include <cstdio>
const int MOD = 1e9+7;
long long dp[101][101];
int N,M,P;
int main() {
	scanf("%d%d%d",&N,&M,&P);
	dp[0][0]=1;
	for(int i = 1; i <= P; i++){
		for(int j = 0; j <= N; j++){
			if(j > 0) (dp[i][j] += dp[i-1][j-1] * (N-j+1)) %= MOD;
			if(j > M) (dp[i][j] += dp[i-1][j] * (j-M)) %= MOD;
		}
	}
	printf("%lld",dp[P][N]);
	return 0;
}
