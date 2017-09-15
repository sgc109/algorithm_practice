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

ll ans;
ll a, b, c, d, u;
int main() {
	fastio();
	cin >> a >> b >> c >> d >> u;
	ll tmp = c;
	while(tmp <= u){
		if(tmp - a < 0 || (tmp - a) % b) ans++;
		if(d == 1) break;
		tmp *= d;
	}
	
	if(u - a >= 0) ans += (u - a) / b + 1;
	cout << ans;
	return 0;
}