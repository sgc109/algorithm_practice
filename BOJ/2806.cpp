#include <bits/stdc++.h>
#define fastio() ios_base::sync_with_stdio(0),cin.tie(0)
using namespace std;
typedef long long ll;
const int mod = 1e9+7;
const int INF = 0x3c3c3c3c;
const long long INFL = 0x3c3c3c3c3c3c3c3c;

int N;
string s;
int dp[1000003][2];
int main() {
	fastio();
	cin >> N >> s;
	dp[0][0] = dp[0][1] = 0;

	for(int i = 1 ; i <= N; i++){
		char c = s[i-1];
		if(c == 'A'){
			dp[i][0] = min(dp[i-1][0], dp[i-1][1] + 1);
			dp[i][1] = min(dp[i-1][0] + 1, dp[i-1][1] + 1);
		}
		if(c == 'B'){
			dp[i][0] = min(dp[i-1][0] + 1, dp[i-1][1] + 1);
			dp[i][1] = min(dp[i-1][0] + 1, dp[i-1][1]);
		}
	}
	cout << dp[N][0];
	return 0;
}