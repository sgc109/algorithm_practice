#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod = 1e9+7;
const int inf = 0x3c3c3c3c;
const long long infl = 0x3c3c3c3c3c3c3c3c;

int T,N,K;
int A[1000003];
int main() {
	cin >> T;
	for(int t = 1 ; t <= T; t++){
		cin >> N;
		for(int i = 0 ; i < N; i++) cin >> A[i];
		cin >> K;
		bool ok = true;
		for(int i = 0 ; i < N-1; i++) if(A[i+1] - A[i] > K) ok = false;
		if(!ok){
			cout << "Case #" << t << endl;
			cout << -1 << endl;
			continue;
		}
		int cur = 0;
		int ans = 0;
		for(int i = 0 ; i < N; i++){
			if(A[i] - cur > K) {
				cur = A[i-1];
				ans++;
			}
		}
		ans++;
		cout << "Case #" << t << endl;
		cout << ans << endl;
	}
	return 0;
}