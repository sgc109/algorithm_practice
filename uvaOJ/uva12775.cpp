#include <bits/stdc++.h>
#define fastio() ios_base::sync_with_stdio(0),cin.tie(0)
using namespace std;
typedef long long ll;
const int mod = 1e9+7;
const int INF = 0x3c3c3c3c;
const long long INFL = 0x3c3c3c3c3c3c3c3c;

ll trash;

ll xGCD(ll a, ll b, ll& x, ll& y){
	if(!b){
		x = 1, y = 0;
		return a;
	}
	ll x1, y1;
	ll ret = xGCD(b, a % b, x1, y1);
	x = y1, y = x1 - (a / b) * y1;
	return ret;
}

ll findRng(ll x0, ll y0, ll a, ll b){
	if(y0 <= 0) {
		swap(x0, y0);
		swap(a, b);
	}
	ll g = xGCD(a, b, trash, trash);
	ll dx = b / g, dy = - a / g;
	ll t1, t2;
	if(x0 < 0) t1 = (-x0 + dx - 1) / dx;
	else t1 = 0;
	t2 = y0 / (-dy);
	return max(0ll, t2 - t1 + 1);
}

ll T, A, B, C, P;
ll a, b, p;
int main() {
	fastio();
	cin >> T;
	for(ll t = 1; t <= T; t++){
		cout << "Case " << t << ": ";
		cin >> A >> B >> C >> P;
		ll ans = 0;
		for(int i = 0 ; i * C < P; i++){
			ll p = P - i * C;
			ll g = xGCD(xGCD(A, B, trash, trash), p, trash, trash);
			a = A / g, b = B / g, p /= g;
			ll x, y;
			ll gg = xGCD(a, b, x, y);
			if(gg != 1) continue;
			ans += findRng(x * p, y * p, a, b);
		}
		if(P % C == 0) ans++;
		cout << ans << endl;
	}
	return 0;
}