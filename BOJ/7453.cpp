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

int A[4003][4];
int N;
vector<int> v;
int cnt;
int main() {
	fastio();
	cin >> N;
	v.resize(N * N);
	for(int i = 0 ; i < N; i++) for(int j = 0 ; j < 4; j++) cin >> A[i][j];
	for(int i = 0 ; i < N; i++) for(int j = 0 ; j < N; j++) v[cnt++] = A[i][0] + A[j][1];
	sort(all(v));

	ll ans = 0;
	for(int i = 0 ; i < N; i++){
		for(int j = 0 ; j < N; j++){
			int p = -(A[i][2] + A[j][3]);
			ans += upper_bound(all(v), p) - lower_bound(all(v), p);
		}
	}

	cout << ans;
	return 0;
}