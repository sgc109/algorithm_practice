// #include <bits/stdc++.h>
#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
#include <vector>
#include <string>
#include <algorithm>
#include <utility>
#include <set>
#include <map>
using namespace std;
typedef long long ll;
const int mod = 1e9 + 7;
const int inf = 0x3c3c3c3c;
const long long infl = 0x3c3c3c3c3c3c3c3c;

int N, K, X;
int W[5003], sz[5003];
int dp[5003][103][103];
int tdp[103][103];
vector<int> G[5003];
int dfs1(int from) {
	sz[from] = 1;
	for (int to : G[from]) sz[from] += dfs1(to);
	return sz[from];
}
void dfs(int here) {
	dp[here][1][0] = 0;
	int szSum = 1;
	for (int c : G[here]) {
		memset(tdp, 0x3c, sizeof(tdp));
		dfs(c);	
		for (int k1 = 1; k1 <= min(K,szSum); k1++) {
			for (int k2 = 1; k2 <= min(K,sz[c]); k2++) {
				for (int x1 = 0; x1 <= min(X - 1, szSum/K); x1++) {
					for (int x2 = 0; x2 <= min(X - 1, sz[c]/K); x2++) {
						if (k2 == K) tdp[k1][min(X - 1, x1 + x2 + 1)] = min(tdp[k1][min(X - 1, x1 + x2 + 1)], dp[here][k1][x1] + dp[c][k2][x2] + W[c]);
						tdp[min(K, k1 + k2)][min(X - 1, x1 + x2)] = min(tdp[min(K, k1 + k2)][min(X - 1, x1 + x2)], dp[here][k1][x1] + dp[c][k2][x2]);
					}
				}
			}
		}
		for (int k = 1; k <= K; k++) {
			for (int x = 0; x <= X - 1; x++) {
				dp[here][k][x] = tdp[k][x];
			}
		}
		szSum += sz[c];
	}
}
int main() {
	memset(dp, 0x3c, sizeof(dp));
	cin >> N >> K >> X;
	for (int i = 2; i <= N; i++) {
		int a, b;
		cin >> a >> b;
		G[a].push_back(i);
		W[i] = b;
	}
	dfs1(1);
	dfs(1);
	int ans = dp[1][K][X-1];
	if (ans == inf) ans = -1;
	cout << ans;
	return 0;
}