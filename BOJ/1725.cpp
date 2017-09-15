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
stack<pair<ll, int> > s;
ll h[100003];
ll ans;
int main() {
	fastio();
	cin >> N;
	for(int i = 0 ; i < N; i++) cin >> h[i];
	for(int i = 0 ; i < N; i++){
		ll l = i;
		while(!s.empty() && s.top().first >= h[i]) {
			auto p = s.top();
			s.pop();
			ans = max(ans, p.first * (i - p.second));
			l = p.second;
		}
		s.push({h[i], l});
	}
	while(!s.empty()){
		auto p = s.top();
		s.pop();
		ans = max(ans, p.first * (N - p.second));
	}
	cout << ans;
	return 0;
}