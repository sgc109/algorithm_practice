#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod = 1e9+7;
const int inf = 0x3c3c3c3c;
const long long infl = 0x3c3c3c3c3c3c3c3c;

int N,K,B;
map<int,int> mp;
vector<pair<int,int> > state;
int dp[1003][1003][4];
int dist(int l, int r){
	return state[r].first - state[l].first;
}
int main() {
	memset(dp,0x3c,sizeof(dp));
	cin >> N >> K >> B;
	for(int i = 0 ; i < N; i++){
		int r,c;
		cin >> r >> c;
		mp[c] = mp[c] | (1<<(r-1));
	}
	state.push_back({0,0});
	for(auto p : mp) state.push_back(p);
	N = (int)state.size()-1;
	dp[0][0][0] = 0;
	for(int i = 1 ; i <= N; i++){
		auto p = state[i];
		int o = p.second;
		for(int k = 1; k <= K; k++){
			int& cache0 = dp[i][k][0];
			int& cache1 = dp[i][k][1];
			int& cache2 = dp[i][k][2];
			int& cache3 = dp[i][k][3];

			for(int j = 0 ; j < 4; j++) cache0 = min(cache0, dp[i-1][k-1][j] + 2);
			cache0 = min(cache0, dp[i-1][k][0] + 2 * dist(i-1, i));
			if(o == 1) {
				for(int j = 0 ; j < 4; j++) cache1 = min(cache1, dp[i-1][k-1][j] + 1);
				cache1 = min(cache1, dp[i-1][k][1] + dist(i-1, i));
				cache1 = min(cache1, dp[i-1][k][3] + dist(i-1, i));
			}
			if(o == 2){
				for(int j = 0 ; j < 4; j++) cache2 = min(cache2, dp[i-1][k-1][j] + 1);
				cache2 = min(cache2, dp[i-1][k][2] + dist(i-1, i));
				cache2 = min(cache2, dp[i-1][k][3] + dist(i-1, i));
			}
			if(k > 1) for(int j = 0 ; j < 4; j++) cache3 = min(cache3, dp[i-1][k-2][j] + 2);
			for(int j = 1 ; j <= 3; j++) cache3 = min(cache3, dp[i-1][k-1][j] + 1 + dist(i-1, i));
			cache3 = min(cache3, dp[i-1][k][3] + 2 * dist(i-1, i));
		}
	}
	int ans = 2e9;
	for(int i = 0 ; i < 4; i++) ans = min(ans, dp[N][K][i]);
	cout << ans;
	return 0;
}