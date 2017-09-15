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

int N, M;
int vis[13][13];
int pane[13][13];
int visBck[3][13][13];
int paneBck[3][13][13];
bool inRange(int i, int j) {
	return 0 <= i && i < N && 0 <= j && j < M;
}
int dfs(int ci, int cj, int num) {
	vis[ci][cj] = 1;
	pane[ci][cj] = 0;
	int ret = 1;
	for (int k = 0; k < 4; k++) {
		int ni = ci + "2110"[k] - '1';
		int nj = cj + "1201"[k] - '1';
		if (!inRange(ni, nj) || pane[ni][nj] != num || vis[ni][nj]) continue;
		ret += dfs(ni, nj, num);
	}
	return ret;
}
int go(int th) {
	if (th == 3) return 0;
	memset(vis, 0, sizeof(vis));
	int ret = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			paneBck[th][i][j] = pane[i][j];
		}
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (vis[i][j] || pane[i][j] == 0) continue;
			int cnt = dfs(i, j, pane[i][j]);
			for (int k = 0; k < N; k++) {
				for (int l = 0; l < M; l++) {
					visBck[th][k][l] = vis[k][l];
				}
			}
			for (int k = 0; k < M; k++) {
				int d = -1;
				for (int l = N - 1; l >= 0; l--) {
					if (pane[l][k] == 0) {
						d = l;
						break;
					}
				}
				if (d == -1) continue;
				int u = d;
				while (u >= 0) {
					while (u >= 0 && pane[u][k] == 0) u--;
					while(d >= 0 && pane[d][k] != 0) d--;
					if (u >= 0) pane[d][k] = pane[u][k], pane[u][k] = 0, d--, u--;
				}
			}
			ret = max(ret, cnt * cnt + go(th + 1));
			for (int k = 0; k < N; k++) {
				for (int l = 0; l < M; l++) {
					pane[k][l] = paneBck[th][k][l];
					vis[k][l] = visBck[th][k][l];
				}
			}
		}
	}
	return ret;
}
int main() {
	fastio();
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> pane[i][j];
		}
	}
	cout << go(0);
	return 0;
}