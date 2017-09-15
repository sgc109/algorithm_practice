#include <bits/stdc++.h>
#define pb push_back
#define sz(v) ((int)(v).size())
#define all(v) (v).begin(), (v).end()
#define fastio() ios::sync_with_stdio(0),cin.tie(0)
using namespace std;
typedef long long ll;
const int mod = 1e9+7;
const int inf = 0x3c3c3c3c;
const ll infl = 0x3c3c3c3c3c3c3c3c;

int T, K, N;
ll dp[1003][1003];
int main() {
	fastio();
	// freopen("galactic.in", "r", stdin);
	cin >> T;
	while(T--){
		memset(dp,0,sizeof(dp));
		dp[0][0] = 1;
		cin >> N >> K;
		if(K > N){
			cout << 0 << '\n';
			continue;
		}
		for(int i = 1; i <= K; i++){
			for(int j = 1; j <= N; j++){
				dp[i][j] = (dp[i][j - 1] * i + dp[i - 1][j - 1] * (K - i + 1)) % mod;
			}
		}
		cout << dp[K][N] << '\n';
	}
	return 0;
}