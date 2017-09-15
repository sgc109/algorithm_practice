#include <bits/stdc++.h>
#define pb push_back
#define sz(v) ((int)(v).size())
#define all(v) (v).begin(), (v).end()
using namespace std;
typedef long long ll;
const int mod = 1e9+7;
const int inf = 0x3c3c3c3c;
const long long infl = 0x3c3c3c3c3c3c3c3c;

int two[20];
int ten[10];
int go(int x){
	int ret = 0;
	if(x % 100 < 20) ret += two[x % 100];
	else {
		ret += ten[(x % 100) / 10];
		ret += two[x % 10];
	}
	if(x / 100) ret += (x % 100 ? 3 : 0) + two[x / 100] + 7;
	return ret;
}
int main() {
	string s = "03354435543668877988";
	for(int i = 0 ; i < sz(s); i++) two[i] = s[i] - '0';
	s = "0066555766";
	for(int i = 0 ; i < sz(s); i++) ten[i] = s[i] - '0';
	ll ans = 11;
	for(int i = 1; i <= 999; i++){
		ans += go(i);
	}
	cout << ans;
	// for(int i = 1; i <= 30; i++){
	// 	printf("i : %d, cnt : %d\n", i, go(i));
	// }
	return 0;
}