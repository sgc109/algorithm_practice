#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod = 1e9+7;
const int inf = 0x3c3c3c3c;
const long long infl = 0x3c3c3c3c3c3c3c3c;

int T,N;
int A[10003], B[10003];
int dp[10003];

int main() {
	cin >> T;
	for(int t = 1 ; t <= T; t++){
		memset(dp,0,sizeof(dp));

		cin >> N;
		for(int i = 1 ; i <= N; i++) cin >> A[i];
		for(int i = 1 ; i <= N; i++) cin >> B[i];
		dp[1] = max(A[1], B[1]);
		for(int i = 2; i <= N; i++) dp[i] = max(dp[i-1] + A[i], dp[i-2] + B[i]);
		cout << "Case #" << t << endl;
		cout << dp[N] << endl;
	}
	return 0;
}
	