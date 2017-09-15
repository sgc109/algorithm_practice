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

int N;
vector<int> G[200003];
int ans[200003];
pair<int, int> in[100003];
void dfs(int cur, int col){
	if(ans[cur]) return;
	ans[cur] = col;
	for(int next : G[cur]) dfs(next, 3 - col);
}
int main() {
	fastio();
	cin >> N;
	for(int i = 0 ; i < N; i++){
		int a, b;
		cin >> a >> b;
		a--, b--;
		in[i] = {a, b};
		G[a].push_back(b);
		G[b].push_back(a);
	}
	for(int i = 0 ; i < 2 * N; i+=2){
		G[i].push_back(i + 1);
		G[i + 1].push_back(i);
	}
	for(int i = 0 ; i < 2 * N; i++) dfs(i, 1);
	for(int i = 0 ; i < N; i++){
		cout << ans[in[i].first] << " " << ans[in[i].second] << "\n";
	}
	return 0;
}