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

int N, M;
int pow3[13];
string rel[13];
int bits[13];
int dp[13][540000];
int go(int pos, int mask){
	// cout << "pos : " << pos << ", mask : " << mask << endl;
	if(pos == N) {
		int ok = 1;
		for(int tmp = mask; tmp ; tmp /= 3) if(tmp % 3 == 0) ok = 0;
		return ok ? 0 : inf;
	}
	int& cache = dp[pos][mask];
	if(cache != -1) return cache;
	int ret = inf;
	// cout << "bits : " << bits[pos] << endl;
	for(int sub = bits[pos]; sub; sub = (sub - 1) & bits[pos]){
		// cout << "sub : " << sub << endl;
		int flag = 0;
		for(int i = 0 ; i < M; i++){
			if(sub >> i & 1  && mask / pow3[i] % 3 > 0) flag = 1;
		}
		if((sub & -sub) != sub && flag) continue;
		// cout << "fuck\n";
		int nxt = mask;
		for(int i = 0 ; i < M; i++){
			if(~sub >> i & 1) continue;
			if(nxt / pow3[i] % 3 != 2) nxt += pow3[i];
		}
		ret = min(ret, go(pos + 1, nxt) + 1 - flag);
	}
	return cache = ret;
}

int main() {
	memset(dp,-1,sizeof(dp));
	fastio();
	pow3[0] = 1;
	for(int i = 1; i < 13; i++) pow3[i] = pow3[i - 1] * 3;
	cin >> N >> M;
	for(int i = 0 ; i < N; i++) {
		cin >> rel[i];
		for(int j = 0 ; j < M; j++){
			if(rel[i][j] == '1') bits[i] |= (1 << j);
		}
	}
	int ans = go(0, 0);
	if(ans == inf) ans = -1;
	cout << ans;
	return 0;
}