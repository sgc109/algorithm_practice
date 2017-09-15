#include <bits/stdc++.h>
#define fastio() ios_base::sync_with_stdio(0),cin.tie(0)
using namespace std;
typedef long long ll;
const int mod = 1e9+9;
const int INF = 0x3c3c3c3c;
const long long INFL = 0x3c3c3c3c3c3c3c3c;

ll gcd(ll a, ll b){
	return !b ? a : gcd(b, a % b);
}
ll poww(ll x, ll k){
	if(k & 1) return poww(x, k - 1) * x % mod;
	return poww(x * x % mod, k / 2);
}
int N;
ll pane[3003][3003];
ll rowGcd[3003], colGcd[3003];
int main() {
	fastio();
	cin >> N;
	ll allMult = 1;
	for(int i = 0 ; i < N; i++){
		for(int j = 0 ; j < N; j++){
			cin >> pane[i][j];
			allMult *= pane[i][j];
		}
	}
	ll upper = 1;
	for(int i = 0 ; i < 2 * N - 1; i++) upper = (upper * allMult) % mod;
	for(int i = 0 ; i < N; i++){
		rowGcd[i] = pane[i][0];
		for(int j = 1; j < N; j++) rowGcd[i] = gcd(rowGcd[i], pane[i][j]);
	}
	for(int j = 0 ; j < N; j++){
		colGcd[j] = pane[0][j];
		for(int i = 1; i < N; i++) colGcd[j] = gcd(colGcd[j], pane[i][j]);
	}

	for(int i = 0 ; i < N; i++) printf("%lld ", rowGcd[i]);

	return 0;
}