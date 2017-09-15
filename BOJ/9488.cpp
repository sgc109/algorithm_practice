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

int main() {
	fastio();
	while(1){
		ll k;
		cin >> k;
		if(!k) break;
		cout << k * (k + 1) * (k + 2) / 6 << '\n';
	}	
	return 0;
}