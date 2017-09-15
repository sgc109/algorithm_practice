#include <bits/stdc++.h>
#define fastio() ios_base::sync_with_stdio(false),cin.tie(NULL)
using namespace std;
typedef long long ll;
const int mod = 1e9+7;
const int INF = 0x3c3c3c3c;
const long long INFL = 0x3c3c3c3c3c3c3c3c;

int N,K;
vector<int> G[203];
string words[203];
int rev[203][203];
int dp[23][23];
int color[203];
int dfs(int cur, int col){
	color[cur] = col;
	for(int next : G[cur]){
		if(color[next] == col) return 0;
		if(color[next]) continue;
		int ret = dfs(next, 3 - col);
		if(!ret) return ret;
	}
	return 1;
}
int main() {
	fastio();
	cin >> N >> K;
	int cnt = 0;
	for(int i = 0 ; i < N; i++) cin >> words[i];
	for(int i = 0 ; i < N; i++){
		for(int j = i + 1; j < N; j++){
			int maxLen = 0;
			memset(dp,0,sizeof(dp));
			for(int a = 1; a <= (int)words[i].size(); a++){
				for(int b = 1; b <= (int)words[j].size(); b++){
					char c1 = words[i][a - 1];
					char c2 = words[j][b - 1];
					if(c1 == c2) dp[a][b] = dp[a - 1][b - 1] + 1;
					else dp[a][b] = 0;
					maxLen = max(maxLen, dp[a][b]);
				}
			}
			if(maxLen >= K) {
				cnt++;
				G[i].push_back(j);
				G[j].push_back(i);
			}
		}
	}
	
	for(int i = 0 ; i < N; i++){
		if(!color[i]) {
			int ret = dfs(i, 1);
			if(!ret) {
				cout << "No" << endl;
				return 0;
			}
		}
	}
	cout << "Yes" << endl;
	if(!cnt) color[0] = 3 - color[0];
	for(int i = 0 ; i < N; i++) cout << color[i] << endl;

	return 0;
}