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
ll A[5003];
int main() {
	fastio();
	cin >> N;
	for(int i = 0 ; i < N; i++) cin >> A[i];
	sort(A, A + N);
	ll minn = infl;
	vector<int> ans;
	for(int i = 0 ; i < N; i++){
		int l = i + 1, r = N - 1;
		while(l < r){
			ll sum = A[i] + A[l] + A[r];
			if(abs(sum) < minn){
				minn = abs(sum);
				ans.clear();
				ans.pb(A[i]);
				ans.pb(A[l]);
				ans.pb(A[r]);
			}
			if(sum > 0) r--;
			else l++;
		}
	}
	sort(all(ans));
	for(int i = 0 ; i < 3; i++) cout << ans[i] << ' ' ;
	return 0;
}