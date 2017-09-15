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

ll X, Y;
int main() {
	fastio();
	while(cin >> X >> Y){
		ll lo = 0, hi = 1e9 + 1;
		int prv = Y * 100 / X;
		if(prv >= 99) {
			cout << -1 << '\n';
			continue;
		}
		while(lo < hi){
			ll mid = (lo + hi) / 2;
			int nxt = (Y + mid) * 100 / (X + mid);
			if(prv != nxt) hi = mid;
			else lo = mid + 1;
		}
		cout << lo << '\n';
	}
	return 0;
}