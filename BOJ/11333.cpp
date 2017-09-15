#include <bits/stdc++.h>
#define pb push_back
#define sz(v) ((int)(v).size())
#define all(v) (v).begin(), (v).end()
#define fastio() ios_base::sync_with_stdio(false),cin.tie(NULL)
using namespace std;
typedef long long ll;
const int mod = 1e9+7;
const int inf = 0x3c3c3c3c;
const long long infl = 0x3c3c3c3c3c3c3c3c;

int N, T;
int dp[10003][4][1 << 9];
int go(int ci, int cj, int mask){
	if(cj == 4) return go(ci + 1, 0, mask);
	if(ci == N) return 1;
	int& cache = dp[ci][cj][mask];
	if(cache != -1) return cache;
	int ret = 0;
	if(cj < 2 && ~mask & 1 && ~mask >> 1 & 1 && ~mask >> 2 & 1) ret = (ret + go(ci, cj + 3, mask >> 3)) % mod;
	if(ci < N - 2 && ~mask & 1 && ~mask >> 4 & 1 && ~mask >> 8 & 1) ret = (ret + go(ci, cj + 1, (mask | 273) >> 1)) % mod;
	if(mask & 1) ret = (ret + go(ci, cj + 1, mask >> 1)) % mod;
	return cache = ret;
}
int main() {
	fastio();
	cin >> T;
	while(T--){
		memset(dp,-1,sizeof(dp));
		cin >> N;
		cout << go(0, 0, 0) << '\n';
	}
	return 0;
}