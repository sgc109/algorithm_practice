#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod = 1e9+7;
const int inf = 0x3c3c3c3c;
const long long infl = 0x3c3c3c3c3c3c3c3c;

int N,T;
int up[1003],down[1003];
int possi(int k){
	int lo = 0, hi = 0;
	for(int i = 0 ; i < N; i++){
		if(down[i] > k) return 0;
		lo += down[i];
		hi += min(up[i], k);
	}
	return lo <= T && T <= hi;
}
int main() {
	cin >> N >> T;
	for(int i = 0 ; i < N; i++){
		cin >> down[i] >> up[i];
	}
	int lo = 1, hi = 1e7;
	while(lo<hi){
		int mid = (lo+hi)>>1;
		if(possi(mid)) hi = mid;
		else lo = mid+1;
	}
	if(lo >= 1e7) cout << -1;
	else cout << lo;

	return 0;
}
