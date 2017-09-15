#include <bits/stdc++.h>
#define fastio() ios_base::sync_with_stdio(0),cin.tie(0)
using namespace std;
typedef long long ll;
const int mod = 1e9+7;
const int INF = 0x3c3c3c3c;
const long long INFL = 0x3c3c3c3c3c3c3c3c;

ll xGCD(ll a, ll b, ll& x, ll& y){
	if(!b){
		x = 1, y = 0;
		return a;
	}
	ll x1, y1;
	int ret = xGCD(b, a % b, x1, y1);
	x = y1, y = x1 - (a / b) * y1;
	return ret;
}

ll chinese(vector<ll>& mods, vector<ll>& remains){
	ll lcm = 1;
	for(ll num : mods) lcm *= num;
	ll ret = 0;
	ll N = 1;
	for(ll num : mods) N *= num;
	for(int i = 0 ; i < (int)mods.size(); i++){
		ll n = mods[i];
		ll x, y;
		xGCD(n, N / n, x, y);
		if(y < 0) y %= N, y += N;
		ret = (ret + N / n * y % lcm * remains[i] % lcm) % lcm;
	}
	return ret;
}
int main() {
	fastio();
	vector<ll> mods({15, 28, 19});
	vector<ll> remains;
	for(int i = 0 ; i < 3; i++){
		ll a;
		cin >> a;
		a--;
		remains.push_back(a);
	}
	ll ret = chinese(mods, remains);
	cout << ret + 1;
	return 0;
}