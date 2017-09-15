#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod = 1e9+7;
const int inf = 0x3c3c3c3c;
const long long infl = 0x3c3c3c3c3c3c3c3c;

int N,M,K,T;
int dp[103][103][13];
int pane[103][103];
int main() {
	cin >> T;
	for(int t = 1 ; t <= T; t++){
		cin >> M >> N >> K;
		for(int i = 1 ; i <= N+1; i++){
			for(int j = 1 ; j <= M+1; j++){
				cin >> pane[i][j];
			}
		}
		memset(dp,0x3c,sizeof(dp));
		dp[1][0][0] = dp[0][1][0] = 0;
		for(int i = 1 ; i <= N+1; i++){
			for(int j = 1 ; j <= M+1; j++){
				int water = pane[i][j] < 0;
				for(int k = water; k <= K; k++){
					dp[i][j][k] = min(dp[i][j][k], dp[i-1][j][k-water] + (i > 1 ? abs(abs(pane[i][j]) - abs(pane[i-1][j])) : 0));
					dp[i][j][k] = min(dp[i][j][k], dp[i][j-1][k-water] + (j > 1 ? abs(abs(pane[i][j]) - abs(pane[i][j-1])) : 0));
				}
				if(water) {
					dp[i][j][K] = min(dp[i][j][K], dp[i-1][j][K] + (i > 1 ? abs(abs(pane[i][j]) - abs(pane[i-1][j])) : 0));
					dp[i][j][K] = min(dp[i][j][K], dp[i][j-1][K] + (j > 1 ? abs(abs(pane[i][j]) - abs(pane[i][j-1])) : 0));
				}

			}
		}
		cout << "Case #" << t << endl;
		cout << dp[N+1][M+1][K] << endl;
	}
	return 0;
}