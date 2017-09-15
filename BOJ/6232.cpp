#include <bits/stdc++.h>
#define pb push_back
#define sz(v) ((int)(v).size())
#define all(v) (v).begin(), (v).end()
using namespace std;
typedef long long ll;
const int mod = 1e9+7;
const int inf = 0x3c3c3c3c;
const long long infl = 0x3c3c3c3c3c3c3c3c;

int N, M;
bool canGo[1003][1003];
int vis[1003];
vector<int> G[1003];
void dfs(int cur, int start){
	if(vis[cur]) return;
	vis[cur] = 1;
	canGo[cur][start] = canGo[start][cur] = true;
	for(int next : G[cur]){
		dfs(next, start);
	}
}
int main() {
	scanf("%d %d", &N, &M);
	while(M--){
		int a, b;
		scanf("%d %d", &a, &b);
		G[a].push_back(b);
	}
	for(int i = 1; i <= N; i++) {
		memset(vis,0,sizeof(vis));
		dfs(i, i);
	}
	int ans = 0;
	for(int i = 1; i <= N; i++){
		for(int j = i + 1; j <= N; j++) {
			if(!canGo[i][j]) ans++;
		}
	}

	printf("%d", ans);
	return 0;
}