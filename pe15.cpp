#include <bits/stdc++.h>
#define pb push_back
#define sz(v) ((int)(v).size())
#define all(v) (v).begin(), (v).end()
using namespace std;
typedef long long ll;
const int mod = 1e9+7;
const int inf = 0x3c3c3c3c;
const long long infl = 0x3c3c3c3c3c3c3c3c;

ll dp[43][43];
int main() {
	for(int i = 1 ; i < 43; i++) dp[i][0] = 1;
	for(int i = 1; i <= 40; i++){
		for(int j = 1; j < i; j++){
			dp[i][j] = dp[i - 1][j] + dp[i - 1][j - 1];
		}
		dp[i][i] = 1;
	}
	cout << dp[40][20];
	return 0;
}