#include <bits/stdc++.h>
#define pb push_back
#define sz(v) ((int)(v).size())
#define all(v) (v).begin(), (v).end()
using namespace std;
typedef long long ll;
const int mod = 1e9+7;
const int inf = 0x3c3c3c3c;
const long long infl = 0x3c3c3c3c3c3c3c3c;

int main() {
	int ans1 = 0, ans2 = 0;
	for(int i = 1; i <= 100; i++) {
		ans1 += i;
		ans2 += i * i;
	}
	cout << ans1 * ans1 - ans2;
	return 0;
}