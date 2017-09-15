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

int push[100003];
int on[100003];
int N, K;
int main() {
	fastio();
	cin >> N >> K;
	for(int i = 0 ; i < N; i++) cin >> on[i];
	int tog = 0;
	int ans = 0;
	for(int i = 0 ; i < N; i++){
		if(i >= K) tog ^= push[i - K];
		if(on[i] ^ tog) {
			if(i > N - K) return !printf("Insomnia");
			push[i] = 1;
			ans++;
		}
		tog ^= push[i];
	}
	cout << ans;
	return 0;
}