#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod = 1e9+7;
const int inf = 0x3c3c3c3c;
const long long infl = 0x3c3c3c3c3c3c3c3c;

ll T;
ll A[100003];
ll S;
int N;
int main() {
	cin >> T;
	for(int t = 1; t <= T; t++){
		cin >> N >> S;
		for(int i = 0 ; i < N; i++) cin >> A[i];
		ll sum = 0;
		ll l = 0, r = 0;
		ll ans = infl;
		while(r < N){
			if(sum >= S){
				ans = min(ans, r-l);
				sum -= A[l++];
				continue;
			}
			if(sum < S){
				sum += A[r++];
				continue;
			}
		}
		while(l < N && sum >= S){
			ans = min(ans, r-l);
			sum -= A[l++];
			continue;
		}
		if(ans == infl) ans = 0;

		cout << "#testcase" << t << "\n" << ans << "\n";
	}
	return 0;
}
