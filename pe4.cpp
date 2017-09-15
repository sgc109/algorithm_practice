#include <bits/stdc++.h>
#define pb push_back
#define sz(v) ((int)(v).size())
#define all(v) (v).begin(), (v).end()
using namespace std;
typedef long long ll;
const int mod = 1e9+7;
const int inf = 0x3c3c3c3c;
const long long infl = 0x3c3c3c3c3c3c3c3c;

bool isPalin(int x){
	string s;
	while(x){
		s += (x % 10) + '0';
		x /= 10;
	}
	reverse(all(s));
	for(int i = 0 ; i < sz(s) / 2; i++) {
		if(s[i] != s[sz(s) - 1 - i]) return false;
	}
	return true;
}
int main() {
	int ans = 0;
	for(int i = 100; i <= 999; i++){
		for(int j = 100; j <= 999; j++){
			if(isPalin(i * j)) ans = max(ans, i * j);
		}
	}
	cout << ans;
	return 0;
}