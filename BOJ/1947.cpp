#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod = 1e9;
const int inf = 0x3c3c3c3c;
const long long infl = 0x3c3c3c3c3c3c3c3c;

int N;
ll dp[1000003][2];
ll go(int pos, int o){
	if(pos==1) return o;
	ll& cache = dp[pos][o];
	if(cache != -1) return cache;

	ll ret = (pos-1) * go(pos-1,1) % mod;
	if(o) ret = (ret + go(pos-1,0)) % mod;

	return cache = ret;
}
int main() {
	memset(dp,-1,sizeof(dp));
	cin >> N;
	cout << go(N,0);
	return 0;
}
	