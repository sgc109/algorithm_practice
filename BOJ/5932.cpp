#include <bits/stdc++.h>
#define pb push_back
#define sz(v) ((int)(v).size())
#define all(v) (v).begin(), (v).end()
#define fastio() ios_base::sync_with_stdio(0),cin.tie(0)
using namespace std;
typedef long long ll;
const int MOD = 1e9+7;
const int INF = 0x3c3c3c3c;
const long long INFL = 0x3c3c3c3c3c3c3c3c;

int t[100003], A[100003];
int N, a;
int query(int x){
	int ret = 0;
	while(x){
		ret += t[x];
		x -= x & -x;
	}
	return ret;
}
void update(int x, int v){
	while(x <= N){
		t[x] += v;
		x += x & -x;
	}
}

int main() {
	fastio();
	cin >> N;
	for(int i = 0 ; i < N; i++) cin >> A[i];
	ll ans = INFL, sum = 0;
	for(int i = N - 1; i >= 0; i--){
		sum += query(A[i]);
		update(A[i], 1);
	}
	for(int i = 0 ; i < N; i++){
		ans = min(ans, sum);
		cout << ans << "\n";
		sum += N - 2 * A[i] + 1;
	}

	// cout << ans;
	return 0;
}