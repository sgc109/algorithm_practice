#include <bits/stdc++.h>
#define fastio() ios_base::sync_with_stdio(0),cin.tie(0)
using namespace std;
typedef long long ll;
const int mod = 1e9+7;
const int INF = 0x3c3c3c3c;
const long long INFL = 0x3c3c3c3c3c3c3c3c;

int N;
int A[303], B[303];
int main() {
	fastio();
	cin >> N;
	for(int i = 0 ; i < N; i++) cin >> A[i];
	for(int i = 0 ; i < N; i++) cin >> B[i];
	int ans = 0;
	int curA = 0, curB = 0;
	for(int i = 0 ; i < N; i++){
		if(A[i] == B[i]){
			if(curA) curA = 0, curB = 1;
			else curA = 1, curB = 0;
		}
		else if(A[i] % 3 + 1 == B[i]) curB++, curA = 0;
		else curA++, curB = 0;
		
		ans = max(ans, curA);
		ans = max(ans, curB);
	}

	cout << ans;
	return 0;
}