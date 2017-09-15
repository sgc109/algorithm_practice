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

int T, N, W;
int pane[2][10003];
int dp[10003][2][1 << 4][1 << 2];
int go(int pos, int down, int mask, int start) {
	if (!down) mask >>= 2;
	if (N == 1 && pos == N && !down) mask |= (start);
	if (pos == N) return (mask == ((1 << 2) - 1) ? 0 : inf);
	int& cache = dp[pos][down][mask][start];
	if (cache != -1) return cache;
	int ret = inf;
	if (pos >= N - 1 && !down) mask |= (start << 2);
	if (!down) {
		if (mask & 1) return cache = go(pos, down ^ 1, mask, start);
		if (!pos) ret = min(ret, go(pos, down ^ 1, mask, start));
		ret = min(ret, 1 + go(pos, down ^ 1, mask | 1, !pos ? start | 1 : start));
		if (pane[down][pos] + pane[down][(pos + 1) % N] <= W && ~mask >> 2 & 1) ret = min(ret, 1 + go(pos, down ^ 1, mask | 5, !pos ? start | 1 : start));
		if (pane[down][pos] + pane[down ^ 1][pos] <= W && ~mask >> 1 & 1) ret = min(ret, 1 + go(pos + 1, down, mask | 3, !pos ? start | 3 : start));
	}
	else {
		if (mask & 2) return cache = go(pos + 1, down ^ 1, mask, start);
		if (!pos) ret = min(ret, go(pos + 1, down ^ 1, mask, start));
		ret = min(ret, 1 + go(pos + 1, down ^ 1, mask | 2, !pos ? start | 2 : start));
		if (pane[down][pos] + pane[down][(pos + 1) % N] <= W && ~mask >> 3 & 1) ret = min(ret, 1 + go(pos + 1, down ^ 1, mask | 5 << 1, !pos ? start | 2 : start));
	}
	return cache = ret;
}
int main() {
	fastio();
	cin >> T;
	while (T--) {
		memset(dp, -1, sizeof(dp));
		cin >> N >> W;
		for (int i = 0; i < 2; i++) {
			for (int j = 0; j < N; j++) {
				cin >> pane[i][j];
			}
		}
		cout << go(0, 0, 0, 0) << '\n';
	}
	return 0;
}