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

int N;
int A[100003];
int main() {
	fastio();
	cin >> N;
	for(int i = 0 ; i < N; i++) cin >> A[i];
	sort(A, A + N);
	int minn = 2e9 + 1;
	int ans1, ans2;

	int l = 0, r = N - 1;
	while(l < r){
		int sum = A[l] + A[r];
		if(abs(sum) < minn){
			minn = abs(sum);
			ans1 = A[l], ans2 = A[r];
		}
		if(sum > 0) r--;
		else l++;
	}
	cout << ans1 << ' ' << ans2;
	
	return 0;
}