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

ll tMax[3000003], tMin[3000003];
ll A[100003];
ll L[100003], R[100003];
ll psum[100003];
int N, size;
void update(int pos, ll val, ll *t){
	for(t[pos += size] = val; pos > 1; pos /= 2){
		t[pos / 2] = max(t[pos], t[pos ^ 1]);
	}
}
ll query(int l, int r, ll *t, int isMax){
	ll ret = isMax ? -1 : -N;
	for(l += size, r += size; l <= r; l /= 2, r /= 2){
		if(l & 1) ret = max(ret, t[l++]);
		if(~r & 1) ret = max(ret, t[r--]);
	}
	return ret;
}
ll ans;
int main() {
	fastio();
	cin >> N;
	for(size = 1; size <= 1000000; size *= 2);
	for(int i = 0 ; i < 2 * size; i++) tMax[i] = -1, tMin[i] = -N;
	for(int i = 0 ; i < N; i++) cin >> A[i];
	for(int i = 0 ; i < N; i++) psum[i + 1] = psum[i] + A[i];
	for(int i = 0 ; i < N; i++){
		L[i] = query(0, A[i] - 1, tMax, 1) + 1;
		update(A[i], i, tMax);
	}
	for(int i = N - 1 ; i >= 0; i--){
		R[i] = -query(0, A[i] - 1, tMin, 0) - 1;
		update(A[i], -i, tMin);
	}
	
	for(int i = 0 ; i < N; i++){
		ans = max(ans, (psum[R[i] + 1] - psum[L[i]]) * A[i]);
	}
	cout << ans;
	return 0;
}