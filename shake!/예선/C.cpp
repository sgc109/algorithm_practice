#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod = 1e9+7;
const int inf = 0x3c3c3c3c;
const long long infl = 0x3c3c3c3c3c3c3c3c;

int T,W,H;
ll image[103][103][2];
ll dp[103][103];

ll diff(ll a, ll b){
	return (a-b)*(a-b);
}
ll go(int hpos, int wpos){
	if(hpos == H) return 0;
	ll& cache = dp[hpos][wpos];
	if(cache != -1) return cache;
	cache = infl;
	for(int k = 0 ; k < 3; k++){
		int nwpos = wpos + "120"[k]-'1';
		if(0 <= nwpos && nwpos < W) cache = min(cache, diff(image[hpos][nwpos][0],image[hpos][nwpos][1]) + go(hpos+1,nwpos));
	}
	return cache;
}
int main() {
	freopen("output.txt","w",stdout);
	cin >> T;
	for(int t = 1; t <= T; t++){
		memset(dp,-1,sizeof(dp));
		cin >> H >> W;
		for(int k = 0 ; k < 2; k++){
			for(int i = 0 ; i < H; i++){
				for(int j = 0 ; j < W; j++){
					cin >> image[i][j][k];
				}
			}
		}
		ll ans = infl;
		for(int i = 0 ; i < W; i++){
			ans = min(ans, go(0,i));
		}
		cout << "Case #" << t << "\n" << ans << endl;

	}

	return 0;
}
