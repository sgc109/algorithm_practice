#include <bits/stdc++.h>
#define pb push_back
#define sz(v) ((int)(v).size())
#define all(v) (v).begin(), (v).end()
using namespace std;
typedef long long ll;
const int mod = 1e9+7;
const int inf = 0x3c3c3c3c;
const long long infl = 0x3c3c3c3c3c3c3c3c;

int dp[100000000];
int go(ll x){
	if(x == 1) return 0;
	if(x < 100000000 && dp[x] != -1) return dp[x];
	int ret = 0;
	if(x & 1) ret = 1 + go(3 * x + 1);
	else ret = 1 + go(x / 2);
	if(x < 100000000) dp[x] = ret;
	return ret;
}
int main() {
	memset(dp, -1, sizeof(dp));
	int maxx = 0;
	int num = 0;
	for(ll i = 1 ; i <= 1000000; i++){
		int ret = go(i);
		if(maxx < ret) {
			maxx = ret;
			num = i;
		}
	}

	cout << num;
	return 0;
}