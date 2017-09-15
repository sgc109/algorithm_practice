#include<vector>
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#define pb push_back
#define sz(v) ((int)(v).size())
#define all(v) (v).begin(), (v).end()
#define fastio() ios_base::sync_with_stdio(false),cin.tie(NULL)
using namespace std;
typedef long long ll;
const int mod = 1e9 + 7;
const int inf = 0x3c3c3c3c;
const long long infl = 0x3c3c3c3c3c3c3c3c;

int N, K;
int dp[257][257][257];
int cntSqr(int i, int j, int k, int l) {
	return dp[i][j][k] - dp[i - l][j][k] - dp[i][j - l][k] - dp[i][j][k - l] + dp[i - l][j - l][k] + dp[i - l][j][k - l] + dp[i][j - l][k - l] - dp[i - l][j - l][k - l];
}
bool poss(int L) {
	for (int i = L; i <= 256; i++) {
		for (int j = L; j <= 256; j++) {
			for (int k = L; k <= 256; k++) {
				int cnt = cntSqr(i, j, k, L);
				if (cnt >= K) return true;
			}
		}
	}
	return false;
}
int main() {
	fastio();
	cin >> N >> K;
	for (int i = 0; i < N; i++) {
		int x, y, z;
		cin >> x >> y >> z;
		x++, y++, z++;
		dp[x][y][z]++;
	}

	for (int i = 1; i <= 256; i++) {
		for (int j = 1; j <= 256; j++) {
			for (int k = 1; k <= 256; k++) {
				dp[i][j][k] += dp[i - 1][j][k] + dp[i][j - 1][k] + dp[i][j][k - 1] - dp[i - 1][j - 1][k] - dp[i - 1][j][k - 1] - dp[i][j - 1][k - 1] + dp[i - 1][j - 1][k - 1];
			}
		}
	}

	int lo = 1, hi = 256;
	while (lo < hi) {
		int mid = (lo + hi) / 2;
		if (poss(mid)) hi = mid;
		else lo = mid + 1;
	}
	int L = lo;
	int ansX = 0, ansY = 0, ansZ = 0;
	int fnd = 0;
	for (int i = L; i <= 256 && !fnd; i++) {
		for (int j = L; j <= 256 && !fnd; j++) {
			for (int k = L; k <= 256 && !fnd; k++) {
				int cnt = cntSqr(i, j, k, L);
				if (cnt >= K) {
					ansX = i, ansY = j, ansZ = k;
					fnd = 1;
					break;
				}
			}
		}
	}	
	cout << L - 1 << '\n';

	int sel = 0;
	for (int i = ansX - L + 1; i <= ansX && sel < K; i++) {
		for (int j = ansY - L + 1; j <= ansY && sel < K; j++) {
			for (int k = ansZ - L + 1; k <= ansZ && sel < K; k++) {
				int c = cntSqr(i, j, k, 1);
				while (c-- && sel < K) {
					cout << i - 1 << ' ' << j - 1 << ' ' << k - 1 << '\n';
					sel++;
				}
			}
		}
	}

	return 0;
}