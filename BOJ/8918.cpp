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
struct point{
	int x, y;
};
int dist(point a, point b){
	return abs(a.x - b.x) + abs(a.y - b.y);
}
int adj[3003][3003];
int deg[3003];
int d[3003][3003];
points point[3003];
void dfs(int cur){
	for(int nxt = 0; nxt < N; nxt++){
		if(!adj[cur][nxt]) continue;
		adj[cur][nxt] = adj[nxt][cur] = 0;
	}
}
int trans(int x, int mv){
	return 4 * x + mv;
}
int main() {
	fastio();
	cin >> T;
	while(T--){
		memset(d,0,sizeof(d));
		memset(deg,0,sizeof(deg));
		memset(adj,0,sizeof(adj));
		cin >> N;
		for(int i = 0 ; i < N; i++){
			int xx, yy;
			cin >> xx >> yy;
			points[i] = point{xx, yy};
		}
		cin >> M;
		for(int i = 0 ; i < M; i++){
			int u, v, dd;
			cin >> u >> v >> dd;
			u--, v--;
			d[u][v] = d[v][u] = dd;
		}
		for(int i = 0 ; i < N; i++){
			for(int j = i + 1; j < N; j++){
				for(int k = 0 ; k < 4; k++){
					int nx1 = points[i].x + "1122"[k] - '1';
					int ny1 = points[i].y + "1212"[k] - '1';
					for(int l = 0 ; l < 4; l++){
						int nx2 = points[j].x + "1122"[l] - '1';
						int ny2 = points[j].y + "1122"[l] - '1';
						if(!d[i][j] || dist(point{nx1, ny1}, point{nx2, ny2}) == d[i][j]) {
							adj[trans(i, k)][trans(j, l)] = adj[j][i] = 1;
							deg[i]++, deg[j]++;
						}
					}
				}
			}
		}
		for(int i = 0 ; i < N; i++) {
			if(deg[i] > 0) 
		}
	}
	return 0;
}