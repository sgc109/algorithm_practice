#include <bits/stdc++.h>
#define fastio() ios_base::sync_with_stdio(0),cin.tie(0)
using namespace std;
typedef long long ll;
const int mod = 1e9 + 7;
const int INF = 0x3c3c3c3c;
const long long INFL = 0x3c3c3c3c3c3c3c3c;

int T, N;
int restCon[33];
int totRest;
int nowScore[33];
char pane[53][53];
int cap[963][963], flow[963][963];
int level[963], iter[963];
vector<int> G[963];
void connect(int a, int b, int c) {
	G[a].push_back(b);
	G[b].push_back(a);
	cap[a][b] = c;
}
int MAN(int x) { return 2 + x; }
int GAME(int a, int b) { return 2 + N + a * N + b; }
int dfs(int cur, int sink, int minF) {
	if (cur == sink) return minF;
	for (int& i = iter[cur]; i < (int)G[cur].size(); i++) {
		int next = G[cur][i];
		if (cap[cur][next] - flow[cur][next] <= 0 || level[next] != level[cur] + 1) continue;
		int f = dfs(next, sink, min(minF, cap[cur][next] - flow[cur][next]));
		if (f) {
			flow[cur][next] += f;
			flow[next][cur] -= f;
			return f;
		}
	}
	return 0;
}
int bfs(int src, int sink) {
	memset(level, -1, sizeof(level));
	queue<int> q;
	q.push(src);
	level[src] = 0;
	while (!q.empty() && level[sink] == -1) {
		int cur = q.front();
		q.pop();
		for (int next : G[cur]) {
			if (cap[cur][next] - flow[cur][next] <= 0 || level[next] != -1) continue;
			level[next] = level[cur] + 1;
			q.push(next);
		}
	}
	return level[sink] != -1;
}
int dinic(int src, int sink) {
	int ret = 0;
	while (1) {
		if (!bfs(src, sink)) break;
		memset(iter, 0, sizeof(iter));
		while (1) {
			int f = dfs(src, sink, INF);
			if (!f) break;
			ret += f;
		}
	}
	return ret;
}
int main() {
	int src = 0, sink = 1;
	fastio();
	cin >> T;
	while (T--) {
		totRest = 0;
		memset(nowScore, 0, sizeof(nowScore));
		memset(restCon, 0, sizeof(restCon));
		for (int i = 0; i < 963; i++) G[i].clear();
		cin >> N;
		for (int i = 0; i < N; i++) {
			cin >> pane[i];
			for (int j = i + 1; j < N; j++) {
				char c = pane[i][j];
				if (c == '.') {
					restCon[i]++, restCon[j]++, totRest++;
					connect(MAN(i), GAME(i, j), INF);
					connect(MAN(j), GAME(i, j), INF);
					connect(GAME(i, j), sink, 2);
				}
				else if (c == '1') nowScore[i] += 2;
				else if (c == 'd') nowScore[i]++, nowScore[j]++;
				else if (c == '0') nowScore[j] += 2;
			}
		}
		for (int i = 0; i < N; i++) connect(src, MAN(i), 0);
		vector<int> ans;
		for (int i = 0; i < N; i++) {
			int ok = 1;
			for (int j = 0; j < N; j++) {
				int c = nowScore[i] + restCon[i] * 2 - nowScore[j];
				if(c < 0) ok = 0;
				cap[src][MAN(j)] = c;
			}
			if(!ok) continue;
			int maxFlow = dinic(src, sink);
			if (maxFlow == 2 * totRest) ans.push_back(i + 1);
			memset(flow, 0, sizeof(flow));
		}
		for (int a : ans) cout << a << " ";
		cout << endl;
	}
	return 0;
}