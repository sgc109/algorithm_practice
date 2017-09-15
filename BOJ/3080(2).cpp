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
string S[3003];
ll fact[33];
ll go(int dep, int s, int e){
	if(s == e) return 1;
	ll ret = 1;
	int cnt = 0;
	int prv = s;
	for(int i = s + 1; i <= e; i++){
		if(sz(S[prv]) == dep || S[prv][dep] != S[i][dep]) {
			cnt++;
			ret = (ret * go(dep + 1, prv, i - 1)) % mod;
			prv = i;
		}
	}
	cnt++;
	ret = (ret * go(dep + 1, prv, e)) % mod;
	ret = (ret * fact[cnt]) % mod;
	assert(cnt <= 27);
	return ret;
}
int main() {
	fastio();
	fact[0] = 1;
	for(int i = 1; i <= 30; i++) fact[i] = (i * fact[i - 1]) % mod;
	cin >> N;
	for(int i = 0 ; i < N; i++) cin >> S[i];
	sort(S, S + N);
	ll ans = go(0, 0, N - 1);
	cout << ans;
	return 0;
}