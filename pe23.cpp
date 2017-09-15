#include <bits/stdc++.h>
#define pb push_back
#define sz(v) ((int)(v).size())
#define all(v) (v).begin(), (v).end()
using namespace std;
typedef long long ll;
const int mod = 1e9+7;
const int inf = 0x3c3c3c3c;
const long long infl = 0x3c3c3c3c3c3c3c3c;

ll d[30003];
int check[30003];
ll maxx;
vector<int> v;
int main() {
	for(int i = 1; i <= 30000; i++){
		ll sum = 0;
		for(int j = 1; j * j <= i; j++){
			if(i % j == 0){
				sum += j;
				if(j * j != i) sum += i / j;
			}
		}
		sum -= i;
		d[i] = sum;
	}

	for(int i = 1; i <= 28123; i++) if(d[i] > i) v.pb(i);
	for(int i = 0 ; i < sz(v); i++){
		for(int j = i ; j < sz(v); j++){
			int hab = v[i] + v[j];
			if(hab > 28123) continue;
			check[hab] = 1;
		}
	}

	ll ans = 0;
	for(int i = 1; i <= 28123; i++) if(!check[i]) ans += i;
	cout << ans;
	return 0;
}