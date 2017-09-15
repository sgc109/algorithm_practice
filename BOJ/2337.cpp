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

int size[153];
int order[153];
int orderNode[153];
vector<int> G[153];
int dp[153][153];
int N, M;
int ord;
int dfs(int cur, int dad){
	order[cur] = ord++;
	size[cur] = 1;
	for(int next : G[cur]){
		if(next == dad) continue;
		size[cur] += dfs(next, cur);
	}
	return size[cur];
}
int go(int cur, int rest){
	if(cur == N) return rest == M ? 0 : INF;
	int& cache = dp[cur][rest];
	if(cache != -1) return cache;
	int ret = INF;
	ret = min(ret, 1 + go(orderNode[order[cur] + size[cur]], rest - size[cur]));
	ret = min(ret, go(orderNode[order[cur] + 1], rest));
	return cache = ret;
}
int main() {
	fastio();
	cin >> N >> M;
	for(int i = 0 ; i < N - 1; i++) {
		int a, b;
		cin >> a >> b;
		a--, b--;
		G[a].push_back(b);
		G[b].push_back(a);
	}
	int ans = INF;

	for(int root = 0 ; root < N; root++){
		ord = 0;
		memset(dp,-1,sizeof(dp));
		dfs(root, -1);
		for(int i = 0 ; i < N; i++) orderNode[order[i]] = i;
		orderNode[N] = N;
		int ret =  go(orderNode[0], N);
		ans = min(ans, ret);
	}
	if(ans >= N) ans = -1;
	
	cout << ans;
	return 0;
}