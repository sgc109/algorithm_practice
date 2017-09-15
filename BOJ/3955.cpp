#include <bits/stdc++.h>
#define fastio() ios_base::sync_with_stdio(0),cin.tie(0)
using namespace std;
typedef long long ll;
const int mod = 1e9+7;
const int INF = 0x3c3c3c3c;
const long long INFL = 0x3c3c3c3c3c3c3c3c;

ll K,C,T;
ll xGCD(ll a, ll b, ll& x, ll& y){
	if(!b){
		x = 1, y = 0;
		return a;
	}
	ll x1, y1;
	ll ret = xGCD(b, a % b, x1, y1);
	x = y1, y = x1 - (a/b) * y1;
	return ret;
}
int main() {
	fastio();
	cin >> T;
	while(T--){
		cin >> K >> C;
		ll x, y;
		ll ret = xGCD(K, C, x, y);
		if(ret != 1) {
			cout << "IMPOSSIBLE" <<endl;
			continue;
		}
		else {
			if(y > K) y %= K;
			if(y <= 1) y += K;
			cout << y << endl;
		}
	}
	return 0;
}