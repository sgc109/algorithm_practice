#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9+7;
const int INF = 0x3c3c3c3c;
const long long INFL = 0x3c3c3c3c3c3c3c3c;

int T;
int M, N;
int distSum[503][503];
int dp[503][503];
int home[503];

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
		
		for(int i = 1 ; i <= N; i++){
			for(int j = 1 ; j <= M; j++){
				for(int k = 1 ; k <= i; k++){
					dp[i][j] = min(dp[i][j], dp[i-k][j-1] + distSum[i-k+1][i]); 
				}
			}
		}

		printf("Case #%d\n%d\n", t, dp[N][M]);
	}
	return 0;
}
