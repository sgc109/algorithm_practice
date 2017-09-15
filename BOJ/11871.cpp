#include <bits/stdc++.h>
#define fastio() ios_base::sync_with_stdio(0),cin.tie(0)
using namespace std;
typedef long long ll;
const int mod = 1e9+7;
const int INF = 0x3c3c3c3c;
const long long INFL = 0x3c3c3c3c3c3c3c3c;

int N;
ll A[103];
int main() {
	fastio();
	cin >> N;
	ll ans = 0;
	for(int i = 0 ; i < N; i++) {
		cin >> A[i];
		if(A[i] & 1) ans ^= (A[i] / 2 + 1);
		else ans ^= (A[i] / 2 - 1);
	}
	if(ans) cout << "koosaga";
	else cout << "cubelover";
	return 0;
}