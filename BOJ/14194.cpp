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

int T, N;
vector<int> v;
int main() {
	fastio();
	cin >> T;
	while(T--){
		v.clear();
		cin >> N;
		int sum = 0;
		for(int i = 0 ; i < N; i++){
			int a;
			cin >> a;
			sum += a;
			v.pb(a);
		}
		sort(all(v));
		double A = (v[0] + v.back()) / 2;
		double B = (double)sum / N;
		if(fabs(A - B) <= 1.0 + 1e-9) cout << "Yes\n";
		else cout << "No\n";
	}
	return 0;
}