#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod = 1e9+7;
const int inf = 0x3c3c3c3c;
const long long infl = 0x3c3c3c3c3c3c3c3c;

int T,N;
int A[200003];
int main() {
	cin >> T;
	for(int t = 1 ; t <= T; t++) {
		cin >> N;
		for(int i = 0 ; i < N; i++) cin >> A[i];
		int minH = inf;
		for(int i = 0 ; i < N; i++) {
			int h;
			cin >> h;
			minH = min(minH, h - i);
		}
		ll ans = 0;
		for(int i = 0 ; i < N; i++) ans += max(0, A[i] - minH);

		cout << "Case #" << t << endl;
		cout << ans << endl;
	}
	return 0;
}
	