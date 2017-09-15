#include <bits/stdc++.h>
#define pb push_back
#define sz(v) ((int)(v).size())
#define all(v) (v).begin(), (v).end()
#define fastio() ios::sync_with_stdio(0),cin.tie(0)
using namespace std;
typedef long long ll;
const int mod = 1e9+7;
const int inf = 0x3c3c3c3c;
const ll infl = 0x3c3c3c3c3c3c3c3c;

int N, W;
int A[23];
int wsum[1 << 18];
int dp[1 << 18];
int par[1 << 18];
vector<int> ans;
int main() {
	fastio();
	memset(dp,0x3c,sizeof(dp));
	cin >> N >> W;
	for(int i = 0 ; i < N; i++) cin >> A[i];
	for(int mask = 0 ; mask < 1 << N; mask++){
		for(int i = 0 ; i < N; i++){
			if(~mask >> i & 1) continue;
			wsum[mask] += A[i];
		}
	}
	dp[0] = 0;
	for(int mask = 0 ; mask < 1 << N; mask++){
		int inv = ~mask & ((1 << N) - 1);
		for(int sub = inv; sub; sub = (sub - 1) & inv){
			if(wsum[sub] > W) continue;
			int& cache = dp[mask | sub];
			if(cache > 1 + dp[mask]){
				cache = 1 + dp[mask];
				par[mask | sub] = mask;
			}
		}
	}
	cout << dp[(1 << N) - 1] << '\n';
	par[0] = 0;
	for(int p = (1 << N) - 1; par[p] != p; p = par[p]){
		ans.pb(par[p] ^ p);
	}
	for(int num : ans) {
		vector<int> tmp;
		for(int i = 0; num; i++, num /= 2) {
			if(num & 1) tmp.pb(i + 1);
		}
		cout << sz(tmp) << ' ';
		for(int n : tmp) cout << n << ' ';
		cout << '\n';
	}
	return 0;
}