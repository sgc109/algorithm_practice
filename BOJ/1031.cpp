#include <vector>
#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>
#define fastio() ios_base::sync_with_stdio(0),cin.tie(0)
using namespace std;
typedef long long ll;
const int mod = 1e9 + 7;
const int INF = 0x3c3c3c3c;
const long long INFL = 0x3c3c3c3c3c3c3c3c;

int N, M, a;
vector<int> G[102];
int cap[102][102];
int ans[53][53];
int level[102], iter[102];
int dfs(int cur, int sink, int minF) {
	if (cur == sink) return minF;
	for (int& i = iter[cur]; i < (int)G[cur].size(); i++) {
		int next = G[cur][i];
		if (cap[cur][next] <= 0 || level[next] != level[cur] + 1) continue;
		int f = dfs(next, sink, min(minF, cap[cur][next]));
		if (f) {
			cap[cur][next] -= f;
			cap[next][cur] += f;
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
			if (cap[cur][next] <= 0 || level[next] != -1) continue;
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
int TEAM1(int x) { return 2 + x; }
int TEAM2(int x) { return 2 + N + x; }
void connect(int a, int b, int c) {
	G[a].push_back(b);
	G[b].push_back(a);
	cap[a][b] = c;
}
int main() {
	int src = 0, sink = 1;
	scanf("%d%d", &N, &M);
	int sum1 = 0, sum2 = 0;
	for (int i = 0; i < N; i++) {
		scanf("%d", &a);
		if (a > M) return !printf("-1");
		sum1 += a;
		connect(src, TEAM1(i), a);
	}
	for (int i = 0; i < M; i++) {
		scanf("%d", &a);
		if (a > N) return !printf("-1");
		sum2 += a;
		connect(TEAM2(i), sink, a);
	}
	if(sum1 != sum2) return !printf("-1");
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			connect(TEAM1(i), TEAM2(j), 1);
		}
	}

	int ret = dinic(src, sink);
	if(ret != sum2) return !printf("-1");

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (cap[TEAM1(i)][TEAM2(j)]) {
				cap[TEAM1(i)][TEAM2(j)] = 0;
				continue;
			}
			cap[src][TEAM1(i)]++;
			cap[TEAM2(j)][sink]++;
			cap[TEAM1(i)][src]--;
			cap[sink][TEAM2(j)]--;
			cap[TEAM2(j)][TEAM1(i)]--;
			int ret = dinic(src, sink);
			if (!ret) {
				ans[i][j] = 1;
				cap[src][TEAM1(i)]--;
				cap[TEAM2(j)][sink]--;
				cap[TEAM1(i)][src]++;
				cap[sink][TEAM2(j)]++;
				cap[TEAM2(j)][TEAM1(i)]++;
			}
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			printf("%d", ans[i][j]);
		}
		printf("\n");
	}
	return 0;
}