#include <bits/stdc++.h>
#define pb push_back
#define sz(v) ((int)(v).size())
#define all(v) (v).begin(), (v).end()
#define fastio() ios_base::sync_with_stdio(0),cin.tie(0)
using namespace std;
typedef long long ll;
const int MOD = 1e9+7;
const int INF = 0x3c3c3c3c;
const long long INFL = 0x3c3c3c3c3c3c3c3c;

int last[100003];
int N, x, d;
int main() {
	fastio();
	cin >> N;
	for(int i = 1; i <= N; i++){
		cin >> x >> d;
		int cnt = 0;
		for(int j = 1; j * j <= x; j++){
			if(x % j) continue;
			if(last[j] + d < i) cnt++;
			if(j * j != x && last[x / j] + d < i) cnt++;
			last[j] = i;
			last[x / j] = i;
		}
		cout << cnt << "\n";
	}
	return 0;
}