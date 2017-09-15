#include <bits/stdc++.h>
#define fastio() ios_base::sync_with_stdio(0),cin.tie(0)
using namespace std;
typedef long long ll;
const int mod = 1e9+7;
const int INF = 0x3c3c3c3c;
const long long INFL = 0x3c3c3c3c3c3c3c3c;

int N, a;
int main() {
	fastio();
	cin >> N;
	int ans = 0;
	for(int i = 1 ; i <= N; i++) {
		cin >> a;
		if(a - i) ans++;
	}
	cout << ans;
	return 0;
}