#include <bits/stdc++.h>
#define pb push_back
#define sz(v) ((int)(v).size())
#define all(v) (v).begin(), (v).end()
#define fastio() ios_base::sync_with_stdio(0),cin.tie(0)
using namespace std;
typedef long long ll;
const int MOD = 1e9+7;
const int INF = 0x3c3c3c3c;
const long long INFL = 0x3c3c3c3c3c3c3c3c;

int dp[2001][2001];
int A[2001], C[2001];
int N;
int main() {
	memset(dp,0xc3,sizeof(dp));
	fastio();
	cin >> N;
	for(int i = 1; i <= N; i++) cin >> A[N - i + 1];
	for(int i = 1; i <= N; i++) C[i] = C[i - 1] + A[i];
	for(int i = 0; i <= N; i++) dp[0][i] = 0;
	for(int i = 1; i <= N; i++) {
		for(int j = 1; j <= i; j++){
			dp[i][j] = max(dp[i][j - 1], C[i] - C[i - j] - dp[i - j][min(2 * j, i - j)]);
		}
	}
	cout << (dp[N][2] + C[N]) / 2;
	return 0;
}