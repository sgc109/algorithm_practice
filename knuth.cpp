#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9+7;
const int INF = 0x3c3c3c3c;
const long long INFL = 0x3c3c3c3c3c3c3c3c;

int T;
int M, N;
int distSum[503][503];
int dp[503][503];
int K[503][503];
int home[503];

void dnc(int t, int s, int e, int p, int q){
	if(s > e) return;
	int m = (s+e)>>1;
	dp[m][t] = INF;
	for(int k = p; k <= q && k <= m; k++) {
		if(dp[m][t] > dp[m-k][t-1] + distSum[m-k+1][m]) {
			dp[m][t] = dp[m-k][t-1] + distSum[m-k+1][m], K[t][m] = k;
		}
	}
	dnc(t, s, m-1, p, K[t][m]);
	dnc(t, m+1, e, K[t][m], q);
}

int main() {
	scanf("%d",&T);
	for(int t = 1; t <= T; t++){
		memset(dp, 0x3c, sizeof(dp));
		memset(distSum, 0, sizeof(distSum));

		scanf("%d%d", &N, &M);
		for(int i = 1 ; i <= N; i++){
			scanf("%d", home+i);
		}
		sort(home+1, home+1+N);

		for(int i = 1 ; i <= N; i++){
			for(int j = i ; j <= N; j++){
				distSum[i][j] = distSum[i][j-1] + home[j] - home[i + (j-i)/2];
			}
		}
		for(int i = 0 ; i <= M; i++) dp[0][i] = 0;
		for(int i = 1 ; i <= M; i++) dnc(i, 1, N, 1, N);

		printf("Case #%d\n%d\n", t, dp[N][M]);
	}
	return 0;
}
