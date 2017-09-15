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

int n;
int gcd(int a, int b){
	return !b ? a : gcd(b, a % b);
}
int main() {
	fastio();
	cin >> n;
	int up, down;
	for(up = (n - 1) / 2; up >= 1; up--){
		down = n - up;
		if(gcd(up, down) == 1) break;
	}
	cout << up << ' ' << n - up;
	return 0;
}