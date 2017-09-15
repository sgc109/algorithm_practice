#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod = 1e9+7;
const int inf = 0x3c3c3c3c;
const long long infl = 0x3c3c3c3c3c3c3c3c;
int T,N;
vector<int> G[10003];
int dp[10003][2];
void dfs(int here, int dad){
	if(G[here].size() == 1 && G[here][0] == dad) {
		dp[here][0] = 100;
		dp[here][1] = 0;
		return;
	}
	int allSel = 0;
	int noSel = 0;
	for(int there : G[here]){
		if(there == dad) continue;
		dfs(there, here);
		allSel += dp[there][0];
		noSel += dp[there][1];
	}
	
	// 부모가 나와 잇는 엣지 보호 안해준 경우
	int& dp0 = dp[here][0];
	dp0 = inf;
	// case 1
	dp0 = min(dp0, allSel + 100); 
	
	// case 2
	for(int there : G[here]) {
		if(there == dad) continue;
		dp0 = min(dp0, allSel - dp[there][0] + dp[there][1] + 175);
	}
	// case 3
	dp0 = min(dp0, noSel + 500);

	// 부모가 나와 잇는 엣지 보호해준 경우
	int& dp1 = dp[here][1];
	dp1 = inf;
	// case 1
	dp1 = min(dp1, allSel);

	// case 2
	for(int there : G[here]) {
		if(there == dad) continue;
		dp1 = min(dp1, allSel - dp[there][0] + dp[there][1] + 100);
	}

	// case 3
	int minn = inf, ans = inf;
	for(int there : G[here]) {
		if(there == dad) continue;
		ans = min(ans, minn - dp[there][0] + dp[there][1]);
		minn = min(minn, -dp[there][0] + dp[there][1]);
	}
	dp1 = min(dp1, allSel + ans + 175);

	// case 4
	dp1 = min(dp1, noSel + 500);
}
int main() {
	cin >> T;
	while(T--){
		for(int i = 0 ; i < 10003; i++) G[i].clear();
		cin >> N;
		for(int i = 0 ; i < N-1; i++) {
			int u,v;
			cin >> u >> v;
			G[u].push_back(v);
			G[v].push_back(u);
		}
		dfs(0,-1);
		cout << '$' << dp[0][1] << endl;
	}
	return 0;
}