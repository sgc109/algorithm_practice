#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1e9+7;
const int inf = 0x3c3c3c3c;
const long long infl = 0x3c3c3c3c3c3c3c3c;

ll dp[3003][3003];
int S,N;
string str;
int main() {
	cin >> S >> str;
	N = (int)str.size();
	dp[0][0] = 1;
	for(int i = 1 ; i <= N; i++){
		ll sum = 0;
		for(int j = 0 ; j <= S; j++){
			sum = (sum + dp[i-1][j]) % mod;
			if(j > 25) sum = (sum - dp[i-1][j-26] + mod) % mod;
			dp[i][j] = sum;
		}
	}
	cout << dp[N][S];
	return 0;
}