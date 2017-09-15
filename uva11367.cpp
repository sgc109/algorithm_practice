#include <bits/stdc++.h>
#define pb push_back
#define sz(v) ((int)(v).size())
#define all(v) (v).begin(), (v).end()
#define fastio() ios_base::sync_with_stdio(false),cin.tie(NULL)
using namespace std;
typedef long long ll;
const int mod = 1e9+7;
const int inf = 0x3c3c3c3c;
const ll infl = 0x3c3c3c3c3c3c3c3c;
struct Node{
	int cost, id, fuel;
	bool operator<(const Node& rhs) const{
		return cost > rhs.cost;
	}
};
int N, M, Q;
int p[1003];
vector<pair<int,int> > G[1003];
int dist[1003][103];
priority_queue<Node> pq;
int main() {
	// freopen("input.txt", "r", stdin);
	// freopen("output.txt", "w", stdout);
	fastio();
	cin >> N >> M;
	for(int i = 0 ; i < N; i++) cin >> p[i];
	while(M--){
		int u, v, d;
		cin >> u >> v >> d;
		G[u].pb({v, d});
		G[v].pb({u, d});
	}
	cin >> Q;
	while(Q--){
		memset(dist,0x3c,sizeof(dist));
		int c, s, e;
		cin >> c >> s >> e;
		dist[s][0] = 0;
		pq.push(Node{0, s, 0});
		while(!pq.empty()){
			auto cur = pq.top();
			pq.pop();
			if(dist[cur.id][cur.fuel] < cur.cost) continue;
			for(auto pp : G[cur.id]){
				int nxt = pp.first;
				int nxtD = pp.second;
				for(int i = max(0, nxtD - cur.fuel); i <= c - cur.fuel; i++) {
					int nxtCost = cur.cost + i * p[cur.id];
					int restFuel = cur.fuel + i - nxtD;
					if(dist[nxt][restFuel] > nxtCost){
						pq.push(Node{nxtCost, nxt, restFuel});
						dist[nxt][restFuel] = nxtCost;
					}
				}
			}
		}
		int ans = inf;
		for(int i = 0 ; i < c; i++) ans = min(ans, dist[e][i]);
		if(ans == inf) cout << "impossible\n";
		else cout << ans << '\n';
	}
	return 0;
}