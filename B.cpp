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

int n, k;
int main() {
	fastio();
	cin >> n >> k;
	if(k == 0 || k == n) return !printf("0 0");
	int mx = 0;
	if(n % 3 == 0){
		int mn = n / 3;
		if(mn == 1) {
			if(k == 1) mx = 2;
			else if(k == 2) mx = 1;
		}
		else if(k <= mn) mx = k * 2;
		else {
			mx = n - mn;y
			k -= mn;
			mx -= k;
		}
	}
	else if(n % 3 == 1){
		int mn = n / 3;
		if(mn == 1){
			if(k == 1) mx = 2;
			else if(k == 2) mx = 2;
			else mx = 1;
		}
		else if(k <= mn) mx = k * 2;
		else{
			mx = n - mn - 1;
			k -= mn;
			mx -= k - 1;
		}
	}
	else {
		int mn = (n + 1) / 3;
		if(mn == 1) mx = 1;
		else if(k < mn) mx = k * 2;
		else{
			mx = n - mn;
			k -= mn;
			mx -= k;
		}
	}
	// mx = max(1, mx);
	printf("1 %d\n", mx);
	return 0;
}