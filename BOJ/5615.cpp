#include <bits/stdc++.h>
#define fastio() ios_base::sync_with_stdio(0),cin.tie(0)
using namespace std;
typedef long long ll;
const int mod = 1e9+7;
const int INF = 0x3c3c3c3c;
const long long INFL = 0x3c3c3c3c3c3c3c3c;

int T;
int main() {
	fastio();
	cin >> T;
	int ans = 0;
	while(T--){
		ll K;
		cin >> K;
		int ok = 0;
		for(ll y = 1 ; y * y <= K; y++){
			if((K - y) % (2 * y + 1)) continue;
			ll x = (K - y) / (2 * y + 1);
			ok = 1;
			break;
		}
		if(ok) continue;
		ans++;
	}

	cout << ans;
	return 0;
}