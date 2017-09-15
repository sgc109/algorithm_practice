#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod = 1e9+7;
const int inf = 0x3c3c3c3c;
const long long infl = 0x3c3c3c3c3c3c3c3c;

int T,N;
ll A[100003];
ll gcd(ll a, ll b){
	return b ? gcd(b, a % b) : a;
}
int main() {
	cin >> T;
	for(int t = 1; t <= T; t++){
		cin >> N;
		for(int i = 0 ; i < N; i++) cin >> A[i];
		bool same = true;
		for(int i = 0 ; i < N-1; i++) if(A[i] != A[i+1]) same = false;
		if(same) {
			cout << "Case #" << t << endl;
			cout << 1 << endl;
			continue;
		}
		ll g = -1;
		for(int i = 0 ; i < N-1 ; i++) {
			ll a = A[i+1] - A[i];
			if(!a) {
				g = 0;
				break;
			}
			if(g==-1) g = a;
			else g = gcd(g, a);
		}
		int ans = 0;
		if(!g) ans = 0;
		else {
			map<ll, int> divisors;
			ll limit = g;
			for(ll i = 2; i * i <= limit; i++){
				while(g % i == 0) divisors[i]++, g/=i;
			}
			if(g != 1) divisors[g]++;
			ll gob = 1;
			for(auto it = divisors.begin(); it != divisors.end(); it++){
				gob *= ((*it).second+1);
			}
			ans = gob;
		}
		cout << "Case #" << t << endl;
		cout << ans << endl;
	}
	return 0;
}