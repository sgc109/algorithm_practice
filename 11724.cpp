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

int N, M;
vector<int> G[1003];
int vis[1003];
void dfs(int cur){
    if(vis[cur]) return;
    vis[cur] = 1;
    for(int nxt : G[cur]) dfs(nxt);
}
int main() {
	fastio();
    cin >> N >> M;
    for(int i = 0; i < M; i++){
        int a, b;
        cin >> a >> b;
        G[a].pb(b);
        G[b].pb(a);
    }
    int ans = 0;
    for(int i = 1; i <= N; i++) {
        if(vis[i]) continue;
        ans++;
        dfs(i);
    }
    cout << ans;
}
