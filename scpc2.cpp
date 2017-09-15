#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod = 1e9+7;
const int INF = 0x3c3c3c3c;
const long long INFL = 0x3c3c3c3c3c3c3c3c;

int base = 257;
int N;
int dp[5003];
ll poww[5003];
string S;
ll cache[5003][5003];
int go(int pos){
	if(pos == N) return 0;
	if(pos == N-1) return INF;
	if(dp[pos] != -1) return dp[pos];
	dp[pos] = INF;
	int l = pos+1;
	int len = 1;
	ll h1 = S[pos], h2 = S[l];
	while(l < N) {
		cache[pos][len] = h1;
		if(pos + len > l || h1 != h2) {
			if(len > 1){
				h2 -= poww[len-1] * S[l];
				len--;
				l++;
				h1 = cache[pos][len];
			}
			else {
				h2 -= poww[len-1] * S[l];
				h2 *= base;
				h2 += S[l+len];
				l++;
			}
		}
		else {
			dp[pos] = min(dp[pos], go(l+len) + 1);
			h1 = h1 * base + S[pos+len];
			h2 = h2 * base + S[l+len];
			len++;
		}
	}
	return dp[pos];
}
int main() {
	poww[0] = 1;
	for(int i = 1 ; i < 5003; i++) poww[i] = poww[i-1] * base;
	int T;
	cin >> T;
	for(int t = 1; t <= T; t++){
		memset(dp,-1,sizeof(dp));
		cin >> N;
		cin >> S;
		cout << "Case #" << t << endl;
		int ans = go(0);
		if(ans == INF) ans = 0;
		cout << ans << endl;
	}
	return 0;
}