#include <bits/stdc++.h>
#define fastio() ios_base::sync_with_stdio(0),cin.tie(0)
using namespace std;
typedef long long ll;
const int mod = 1e9+7;
const int INF = 0x3c3c3c3c;
const long long INFL = 0x3c3c3c3c3c3c3c3c;

int N, a;
priority_queue<pair<int,int> > pq;
int main() {
	fastio();
	cin >> N;
	int ans = 0;
	for(int i = 0 ; i < N; i++){
		cin >> a;
		while(!pq.empty() && -pq.top().first < a){
			auto p = pq.top();
			int idx = p.second;
			pq.pop();
			ans = max(ans, i - 1 - idx);
		}
		pq.push({-a, i});
	}
	while(!pq.empty()) {
		auto p = pq.top();
		pq.pop();
		ans = max(ans, N - 1 - p.second);
	}
	cout << ans;
	return 0;
}