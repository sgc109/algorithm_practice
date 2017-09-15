#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod = 1e9+7;
const int inf = 0x3c3c3c3c;
const long long infl = 0x3c3c3c3c3c3c3c3c;

int N,C,T1,T2;
int hole[1003];
int dp[1003];
int main() {
	ios_base::sync_with_stdio(false),cin.tie(NULL);
	while(cin >> N >> C >> T1 >> T2){
		for(int i = 1 ; i <= N; i++) cin >> hole[i];
		int ans = inf;
		for(int i = 1 ; i <= N; i++) {
			memset(dp,0x3c,sizeof(dp));
			dp[0] = 0;
			for(int i = 1; i <= N; i++){
				int next = upper_bound(hole+1, hole+N+1, hole[i]+T1) - hole - 1;
				dp[next] = min(dp[next], dp[i-1] + T1);
				next = upper_bound(hole+1, hole+N+1, hole[i]+T2) - hole - 1;
				dp[next] = min(dp[next], dp[i-1] + T2);
			}
			ans = min(ans, dp[N]);
			int backup = hole[1];
			for(int i = 1 ; i < N; i++) hole[i] = hole[i+1];
			hole[N] = backup + C;
		}
		cout << ans << endl;
	}
	return 0;
}