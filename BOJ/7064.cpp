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

int T, N, M;
int bM[243], vis[243];
vector<int> G[243];
int dfs(int cur){
	if(vis[cur]) return 0;
	vis[cur] = 1;
	for(int nxt : G[cur]){
		if(bM[nxt] == -1 || dfs(bM[nxt])){
			bM[nxt] = cur;
			return 1;
		}
	}
	return 0;
}
int main() {
	fastio();
	cin >> T;
	while(T--){
		for(int i = 0 ; i < 243; i++) G[i].clear();
		memset(bM,-1,sizeof(bM));
		cin >> N >> M;
		for(int i = 0 ; i < M; i++){
			int a, b;
			cin >> a >> b;
			a--, b--;
			G[a].pb(b);
		}
		int ans = 0;
		for(int i = 0 ; i < N; i++){
			memset(vis,0,sizeof(vis));
			if(dfs(i)) ans++;
		}
		cout << N - ans << '\n';
	}
	return 0;
}