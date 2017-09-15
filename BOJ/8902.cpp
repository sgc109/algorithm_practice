#include <bits/stdc++.h>
#define pb push_back
#define sz(v) ((int)(v).size())
#define all(v) (v).begin(), (v).end()
#define fastio() ios_base::sync_with_stdio(false),cin.tie(NULL)
using namespace std;
typedef long long ll;
const int mod = 1e9 + 7;
const int inf = 0x3c3c3c3c;
const long long infl = 0x3c3c3c3c3c3c3c3c;

int T, N, M;
int S[2][30], E[2][30];
string cars[2];
int dp[2][5003];
int cnt[5003][5003];
int main() {
	fastio();
	cin >> T;
	while (T--) {
		memset(S, 0x3c, sizeof(S));
		memset(E, -1, sizeof(E));
		memset(dp, 0x3c, sizeof(dp));
		for (int k = 0; k < 2; k++) {
			cin >> cars[k];
			for (int i = 0; i < sz(cars[k]); i++) {
				int id = cars[k][i] - 'A';
				S[k][id] = min(S[k][id], i);
				E[k][id] = max(E[k][id], i);
			}
		}
		N = sz(cars[0]), M = sz(cars[1]);
		cnt[0][0] = 0;
		for(int i = 0 ; i <= N; i++){
			for(int j = 0 ; j <= M; j++){
				int col1 = cars[1][j] - 'A';
				int add = 0;
				if (E[1][col1] == j && E[0][col1] < i) add--;
				if (S[1][col1] == j && S[0][col1] >= i) add++;
				cnt[i][j + 1] = cnt[i][j] + add;
			}
			int col0 = cars[0][i] - 'A';
			int add = 0;
			if (E[0][col0] == i && E[1][col0] < 0) add--;
			if (S[0][col0] == i && S[1][col0] >= 0) add++;
			cnt[i + 1][0] = cnt[i][0] + add;
		}
		dp[0][0] = 0;
		for (int i = 0; i <= N; i++) {
			memset(dp[~i & 1], 0x3c, sizeof(dp[~i & 1]));
			for (int j = 0; j <= M; j++) {
				if (i < N) {
					int col0 = cars[0][i] - 'A';
					int& cache0 = dp[~i & 1][j];
					cache0 = min(cache0, dp[i & 1][j] + cnt[i][j]);
				}

				if (j < M) {
					int col1 = cars[1][j] - 'A';
					int& cache1 = dp[i & 1][j + 1];
					cache1 = min(cache1, dp[i & 1][j] + cnt[i][j]);
				}
			}
		}
		cout << dp[N & 1][M] << '\n';
	}
	return 0;
}