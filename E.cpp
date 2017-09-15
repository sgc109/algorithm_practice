#include <bits/stdc++.h>
#define pb push_back
#define sz(v) ((int)(v).size())
#define all(v) (v).begin(), (v).end()
#define fastio() ios::sync_with_stdio(0),cin.tie(0)
using namespace std;
typedef long long ll;
const int mod = 1e9+7;
const int inf = 0x3c3c3c3c;
const ll infl = 0x3c3c3c3c3c3c3c3c;
const int MAX_N = 1e5 + 9;

int arr[MAX_N], ans[MAX_N];
vector<int> G[MAX_N];

int main() {
	fastio();
	freopen("jumping.in", "r", stdin);
	int T;
	cin >> T;
	while(T--){
		int N;
		cin >> N;
		for(int i = 0; i < N; i++) G[i].clear();
		memset(ans, -1, sizeof(ans));
		for(int i = 0; i < N; i++){
			cin >> arr[i];
		}
		for(int i = 0; i < N; i++){
			if(i + arr[i] < N) G[i + arr[i]].push_back(i);
			if(i - arr[i] >= 0) G[i - arr[i]].push_back(i);
		}
		queue<int> q;
		int cnt = 0;
		ans[N - 1] = 0;
		q.push(N - 1);
		while(!q.empty()){
			int sz = q.size();
			for(int i = 0; i < sz; i++){
				int curr = q.front();
				q.pop();
				for(int next : G[curr]){
					if(ans[next] == -1){
						ans[next] = cnt + 1;
						q.push(next);
					}
				}
			}
			cnt++;
		}
		for(int i = 0; i < N; i++) cout << ans[i] << "\n";
	}
	return 0;
}