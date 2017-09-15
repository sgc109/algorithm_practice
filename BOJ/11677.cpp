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

int A, B, E, P;
vector<int> G[5003], Gr[5003];
int cango[5003], rev[5003], vis[5003];
int dfs(int cur){
	if(vis[cur]) return 0;
	vis[cur] = 1;
	rev[cur]++;
	int ret = 1;
	for(int nxt : G[cur]) ret += dfs(nxt);
	return ret;
}
int main() {
	fastio();
	cin >> A >> B >> E >> P;
	while(P--){
		int a, b;
		cin >> a >> b;
		G[a].pb(b);
		Gr[b].pb(a);
	}
	int ans1 = 0, ans2 = 0, ans3 = 0;
	for(int i = 0 ; i < E; i++) {
		memset(vis,0,sizeof(vis));
		cango[i] = dfs(i);	
	}
	for(int i = 0 ; i < E; i++){
		int cnt = E - cango[i];
		if(rev[i] > B) ans3++;
		if(cnt < A) ans1++, ans2++;
		else if(cnt < B) ans2++;
	}
	cout << ans1 << '\n' << ans2 << '\n' << ans3;
	return 0;
}