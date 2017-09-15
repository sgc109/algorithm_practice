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

ll N, M, D;
ll dp[2][300003];
struct fire{
	ll a, b, t;
	bool operator<(const fire& rhs) const{
		return t < rhs.t;
	}
};
fire fires[303];
int main() {
	fastio();
	cin >> N >> M >> D;
	fires[0] = fire{0, 0, 0};
	for(int i = 1 ; i <= M; i++){
		ll a, b, t;
		cin >> a >> b >> t;
		fires[i] = fire{a, b, t};
	}

	for(int i = 1; i <= M; i++){
		ll L = min(2 * N, 2 * D * (fires[i].t - fires[i - 1].t) + 1);
		deque<int> dq;
		for(int j = N + 1; j <= 2 * N; j++) dp[(i + 1) % 2][j] = -infl;
		for(int j = 1; j <= 2 * N; j++){
			while(!dq.empty() && dq.front() <= j - L) dq.pop_front();
			while(!dq.empty() && dp[(i + 1) % 2][dq.back()] <= dp[(i + 1) % 2][j]) dq.pop_back();
			dq.push_back(j);
			ll mx = dp[(i + 1) % 2][dq.front()] + fires[i].b - abs(fires[i].a - (j - L / 2));
			if(0 < j - L / 2 && j - L / 2 <= N) dp[i % 2][j - L / 2] = mx;
		}
	}
	
	ll ans = -infl;
	for(int i = 1; i <= N; i++) ans = max(ans, dp[M % 2][i]);
	cout << ans;
	
	return 0;
}