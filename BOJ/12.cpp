#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod = 1e9+7;
const int INF = 0x3c3c3c3c;
const long long INFL = 0x3c3c3c3c3c3c3c3c;

int N, K;
ll A[300003];
int main() {
	cin >> N >> K;
	for(int i = 0 ; i < N; i++) cin >> A[i];
	sort(A, A + N);
	int l = 0, r = N - 1;
	ll ans = 0;
	for(int cnt = 0; cnt < K - 1; cnt++){
		if(~cnt & 1) ans += A[r] - A[l], r--;
		else l++;
	}
	if(K & 1) ans += A[r];
	else ans += A[l];

	cout << ans;
	return 0;
}