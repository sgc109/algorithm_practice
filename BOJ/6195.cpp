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
int N, a;
priority_queue<int> pq;
int main() {
	fastio();
	cin >> N;
	for(int i = 0 ; i < N; i++){
		cin >> a;
		pq.push(-a);
	}
	ll ans = 0;
	while(sz(pq) > 1) {
		int a1 = -pq.top();
		pq.pop();
		int a2 = -pq.top();
		pq.pop();
		int a3 = a1 + a2;
		ans += a3;
		pq.push(-a3);
	}
	
	cout << ans;

	return 0;
}