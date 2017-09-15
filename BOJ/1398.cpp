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

int T;
ll N;
int main() {
	fastio();
	cin >> T;
	while(T--){
		cin >> N;
		int ans = 0;
		while(N){
			ll rest = N % 100;
			int cnt = inf;
			for(int i = 0 ; i < 100; i++){
				for(int j = 0 ; j < 10; j++){
					for(int k = 0 ; k < 4; k++){
						if(i + 10 * j + 25 * k == rest) cnt = min(cnt, i + j + k);
					}
				}
			}
			ans += cnt;
			N /= 100;
		}
		cout << ans << '\n';
	}	
	return 0;
}