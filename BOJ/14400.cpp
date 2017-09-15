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

int N;
pair<int,int> store[100003];
vector<int> xs, ys;
int main() {
	fastio();
	cin >> N;
	for(int i = 0 ; i < N; i++){
		int x, y;
		cin >> x >> y;
		store[i] = {x, y};
		xs.pb(x);
		ys.pb(y);
	}
	sort(all(xs));
	sort(all(ys));
	int cx = xs[sz(xs) / 2];
	int cy = ys[sz(ys) / 2];
	ll ans = 0;
	for(int i = 0 ; i < N; i++){
		ans += abs(cx - store[i].first) + abs(cy - store[i].second);
	}

	cout << ans;

	return 0;
}