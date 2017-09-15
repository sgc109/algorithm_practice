#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod = 1e9+7;
const int inf = 0x3c3c3c3c;
const long long infl = 0x3c3c3c3c3c3c3c3c;

int T;
double P;
ll ans[5];
ll gcd(ll a, ll b){
	return b ? gcd(b, a % b) : a;
}
int main() {
	cin >> T;
	for(int t = 1; t <= T; t++){
		memset(ans,0,sizeof(ans));
		cin >> P;
		ll S = 1e12;
		ll GCD = gcd(P*S, S);
		ll C = S/GCD;
		S = P * C;
		S -= C;

		ans[4] = S/4;
		if(S%4) ans[S%4]++;

		ans[0] = C - ans[1] - ans[2] - ans[3] - ans[4];

		cout << "#testcase" << t << "\n";
		for(int i = 0 ; i < 5; i++) cout << ans[i] << " ";
		cout << endl;
	}
	return 0;
}