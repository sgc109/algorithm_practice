#include <bits/stdc++.h>
#define pb push_back
#define sz(v) ((int)(v).size())
#define all(v) (v).begin(), (v).end()
#define fastio() ios_base::sync_with_stdio(false),cin.tie(NULL)
using namespace std;
typedef long long ll;
const int mod = 1e9+7;
const int inf = 0x3c3c3c3c;
const long long infl = 0x3c3c3c3c3c3c3c3c;

int N, K;
int dp[43];
int go(int n, int k){
	int ret = 0;
	for(int i = 1; i < k; i++) ret += dp[k - i - 1] * dp[n - k];
	for(int i = 0; i <= n - k; i++) ret += dp[k - 1] * dp[n - k - i];
	return ret;
}
int main() {
	fastio();
	cin >> N >> K;
	dp[0] = 1;
	dp[1] = 1;
	for(int i = 2; i <= N; i++) dp[i] = dp[i - 1] + dp[i - 2];
	int A = K - 1;
	int B = N - 1 - A;
	int ans = dp[A] * dp[B];
	int tmp = 0;
	for(int i = 1 ; i <= A; i++) tmp += go(A, i);
	ans += tmp * dp[B];
	tmp = 0;
	for(int i = 1 ; i <= B; i++) tmp += go(B, i);
	ans += tmp * dp[A];
	cout << ans;
	return 0;
}