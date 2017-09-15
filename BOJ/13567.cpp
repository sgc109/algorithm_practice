#include <bits/stdc++.h>
#define pb push_back
#define sz(v) ((int)(v).size())
#define all(v) (v).begin(), (v).end()
#define fastio() ios::sync_with_stdio(0),cin.tie(0)
using namespace std;
typedef long long ll;
const int mod = 1e9+7;
const int inf = 0x3c3c3c3c;
const ll infl = 0x3c3c3c3c3c3c3c3c;

int Z[1000003], L, R;
int cnt[1000003];
int ans[1000003];
int main() {
	fastio();
	string S;
	cin >> S;
	int N = sz(S);
	for (int i = 1; i < N; i++) {
		if (i > R) {
			L = R = i;
			while (R < N && S[R - L] == S[R]) R++;
			Z[i] = R - L; R--;
		} else {
			int k = i - L;
			if (Z[k] < R - i + 1) Z[i] = Z[k];
			else {
				L = i;
				while (R < N && S[R - L] == S[R]) R++;
				Z[i] = R - L; R--;
			}
		}
	}
	for(int i = 1; i < N; i++) cnt[Z[i]]++;
	for(int i = N - 1; i >= 0; i--) cnt[i] += cnt[i + 1];
	int sum = 1;
	for(int i = 1; i < N; i++) {
		if(i + Z[i] == N) ans[Z[i]] = cnt[Z[i]] + 1, sum++;
	}
	cout << sum << '\n';
	for(int i = 0 ; i < N; i++){
		if(ans[i]) cout << i << ' ' << ans[i] << '\n';
	}
	cout << N << ' ' << 1;
	return 0;
}