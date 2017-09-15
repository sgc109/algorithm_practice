#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod = 1e9+7;
const int inf = 0x3c3c3c3c;
const long long infl = 0x3c3c3c3c3c3c3c3c;

int T,N,M;
int A[5003];
int dp[2][10003];
int main() {
	cin >> T;
	for(int t = 1; t <= T; t++){
		cin >> N >> M;
		for(int i = 1 ; i <= N; i++) cin >> A[i];
		memset(dp,0,sizeof(dp));
		int ans = 0;
		dp[0][0] = 1;
		for(int i = 1 ; i <= N; i++){
			for(int j = 0; j <= M; j++){
				dp[i%2][j] = max(dp[i%2][j], max((j >= A[i] ? dp[(i+1)%2][j-A[i]] : 0), dp[(i+1)%2][j]));
				if(dp[i%2][j]) ans = max(ans, j);
			}
		}
		cout << "Case #" << t << "\n" << ans << "\n";
	}
	return 0;
}
	