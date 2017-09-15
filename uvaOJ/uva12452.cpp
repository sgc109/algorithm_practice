#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod = 1e9+7;
const int inf = 0x3c3c3c3c;
const long long infl = 0x3c3c3c3c3c3c3c3c;

int T,N;
vector<int> G[10003];
int dp[10003][2];
int dfs(int here, int dad, int parSel){
	if(G[here].size() == 1 && G[here][0] == dad) return dp[here][parSel] = (1-parSel) * 100;
	if(dp[here][parSel] != -1) return dp[here][parSel];
	int ret = inf;
	int allSel = 0;
	int noSel = 0;
	for(int there : G[here]){
		if(there == dad) continue;
		allSel += dfs(there, here, 0);
		noSel += dfs(there, here, 1);
	}
	if(parSel){
		ret = min(ret, allSel);
		for(int there : G[here]) ret = min(ret, allSel - dp[there][0] + dp[there][1] + 100);
		int minn = inf, ans = inf;
		for(int there : G[here]) ans = min(ans, minn - dp[there][0] + dp[there][1]), minn = min(minn, -dp[there][0] + dp[there][1]);
		ret = min(ret, allSel + ans + 175);
	}
	else {
		ret = min(ret, allSel + 100);
		for(int there : G[here]) ret = min(ret, allSel - dp[there][0] + dp[there][1] + 175);
	}
	ret = min(ret, noSel + 500);
	return dp[here][parSel] = ret;
}
int main() {
	freopen("output.txt","w",stdout);
	cin >> T;
	while(T--){
		memset(dp,-1,sizeof(dp));
		for(int i = 0 ; i < 10003; i++) G[i].clear();
		cin >> N;
		for(int i = 0 ; i < N-1; i++) {
			int u,v;
			cin >> u >> v;
			G[u].push_back(v);
			G[v].push_back(u);
		}
		dfs(0,-1,1);
		cout << '$' << dp[0][1] << endl;
	}
	return 0;
}