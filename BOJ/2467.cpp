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
int minSum, ans1, ans2;
int main() {
	fastio();
	cin >> N;
	minSum = 2e9 + 1;
	for(int i = 0 ; i < N; i++) cin >> A[i];
	int l = 0, r = N - 1;
	while(l < r){
		int sum = A[l] + A[r];
		if(minSum > abs(sum)){
			minSum = abs(sum);
			ans1 = A[l], ans2 = A[r];
		}
		if(sum < 0) l++;
		else if(sum > 0) r--;
		else break;
	}
	cout << ans1 << ' ' << ans2;
	return 0;
}