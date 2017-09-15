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

ll T, a, b, c;
ll xgcd(ll a, ll b, ll& x, ll& y){
	if(!b){
		x = 1, y = 0;
		return a;
	}
	ll ret = xgcd(b, a % b, x, y);
	ll nx = y, ny = x - a / b * y;
	x = nx, y = ny;
	return ret;
}
int main() {
	fastio();
	cin >> T;
	while(T--){
		cin >> a >> b >> c;
		int rev = 0;
		if(a > b) rev = 1, swap(a, b);
		ll tr;
		ll g = xgcd(xgcd(a, b, tr, tr), c, tr, tr);
		a /= g, b /= g, c /= g;
		ll x, y;
		g = xgcd(a, b, x, y);
		if(g != 1){
			cout << "Impossible\n";
			continue;
		}
		x *= c, y *= c;
		ll dx = -b / g, dy = a / g;
		if(x < 0){
			int k = abs(x) / abs(dx) + (abs(x) % abs(dx) ? 1 : 0);
			x += -dx * k, y += -dy * k;
		}
		else if(x > 0){
			int k = abs(x) / abs(dx) ;
			x += dx * k, y += dy * k;
		}
		if(y < 0) {
			cout << "Impossible\n";
			continue;
		}
		if(rev) swap(x, y);
		cout << x << ' ' << y << '\n';
	}
	return 0;
}