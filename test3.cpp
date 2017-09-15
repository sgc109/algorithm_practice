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

map<int, int> mpL, mpR;
int N;
int A[100003];
ll psum[100003];
int main() {
	fastio();
	cin >> N;
	for(int i = 1; i <= N; i++) cin >> A[i];
	for(int i = 1; i <= N; i++) psum[i] = psum[i - 1] + A[i];
	for(int i = 1; i <= N; i++) mpR[A[i]]++;
	int ok = 0;
	for(int i = 1; i <= N; i++){
		ll L = psum[i - 1];
		ll R = psum[N] - L;
		if(L == R) ok = 1;
		else if(L < R){
			if((R - L) % 2 == 0 && mpR[R - L >> 1]) ok = 1;
		}
		else {
			if((L - R) % 2 == 0 && mpL[L - R >> 1]) ok = 1;
		}
		mpL[A[i]]++;
		mpR[A[i]]--;
	}
	assert(!ok || psum[N] % 2 == 0);
	if(ok) cout << "YES";
	else cout << "NO";
	return 0;
}