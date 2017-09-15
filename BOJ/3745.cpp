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

int N;
ll dp[100003];
ll A[100003];
int main() {
	fastio();
	while(cin >> N){
		int ans = 0;
		memset(dp,0x3c,sizeof(dp));
		dp[0] = -infl;
		for(int i = 0 ; i < N; i++) {
			cin >> A[i];
			int len = lower_bound(dp, dp + ans + 1, A[i]) - dp;
			ans = max(ans, len);
			dp[len] = min(dp[len], A[i]);			
		}
		cout << ans << '\n';
	}
	return 0;
}