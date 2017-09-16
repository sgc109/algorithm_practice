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

struct RNG{
	unsigned int now;
	unsigned int next(){
		return now = now * 1664525 + 1013904223;
	}
};

int main() {
	fastio();
	RNG rng;
	for(int i = 0 ; i < 100; i++){
		ll ret = rng.next();
		cout << ret << '\n';
	}
	return 0;
}
