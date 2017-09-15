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

int dp[2][23][23];
int a, b;
int main() {
	fastio();
	memset(dp,0xc3,sizeof(dp));
	dp[0][0][0] = 0;
	int k;
	for(k = 0; cin >> a >> b; k++){
		for(int i = 0; i <= 15; i++){
			for(int j = 0 ; j <= 15; j++){
				dp[~k & 1][i + 1][j] = max(dp[~k & 1][i + 1][j], dp[k & 1][i][j] + a);
				dp[~k & 1][i][j + 1] = max(dp[~k & 1][i][j + 1], dp[k & 1][i][j] + b);
				dp[~k & 1][i][j] = max(dp[~k & 1][i][j], dp[k & 1][i][j]);
			}
		}
	}
	cout << dp[k & 1][15][15];
	return 0;
}