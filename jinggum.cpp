#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod = 1e9+9;
const int inf = 0x3c3c3c3c;
const long long infl = 0x3c3c3c3c3c3c3c3c;

int T,N,K,L;
int mine[50003];
ll dp[50003][100];
ll sum[50003];
int main() {
	cin >> T;
	for(int t = 1; t <= T; t++){
		memset(dp,0,sizeof(dp));
		memset(sum,0,sizeof(sum));
		memset(mine,0,sizeof(mine));

		cin >> N >> K >> L;
		for(int i = 0 ; i < L; i++){
			int a;
			cin >> a;
			mine[a] = 1;
		}
		sum[0] = dp[0][0] = 1;
		for(int i = 1 ; i <= N; i++){
			if(mine[i]) continue;
			for(int j = 1; j <= K && i-j >= 0; j++){
				dp[i][j] = (dp[i][j] + sum[i-j] - dp[i-j][j] + mod) % mod;
				sum[i] = (sum[i] + dp[i][j]) % mod;
			}
		}
		cout << "Case #" << t << "\n";
		cout << sum[N] << "\n";
	}
	return 0;
}