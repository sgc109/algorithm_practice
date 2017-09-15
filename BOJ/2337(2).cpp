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

int N, M;
int dp[153][153];
int tdp[153];
int size[153];
vector<int> G[153];
int ans;
void dfs(int cur, int dad) {
	size[cur] = 1;
	dp[cur][1] = 0;
	for (int next : G[cur]) {
		if (next == dad) continue;
		dfs(next, cur);
		memset(tdp, 0x3c, sizeof(tdp));
		for (int i = 1; i <= size[cur]; i++) {
			for (int j = 0; j <= size[next]; j++) {
				tdp[i + j] = min(tdp[i + j], dp[cur][i] + dp[next][j]);
			}
		}
		for (int i = 0; i < 153; i++) dp[cur][i] = tdp[i];

		size[cur] += size[next];
	}
	dp[cur][0] = 1;
	// dp[cur][size[cur]] = 0;
	
	ans = min(ans, dp[cur][M] + 1);
}
int main() {
	fastio();
	memset(dp, 0x3c, sizeof(dp));
	ans = INF;
	cin >> N >> M;
	for (int i = 0; i < N - 1; i++) {
		int a, b;
		cin >> a >> b;
		a--, b--;
		G[a].push_back(b);
		G[b].push_back(a);
	}
	dfs(0, -1);
	ans = min(ans, dp[0][M]);
	if (ans == INF) ans = -1;
	cout << ans;
	return 0;
}