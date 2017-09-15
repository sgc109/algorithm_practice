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

int main() {
	fastio();
	int N;
	cin >> N;
	ll ans = 0;
	for(int a = 1; a <= N / 3; a++){
		ans += max(0, (N - a) / 2 - max(a, N / 2 - a + 1) + 1);
	}
	cout << ans;
	return 0;
}