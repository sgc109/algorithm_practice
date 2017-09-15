#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod = 1e9+7;
const int inf = 0x3c3c3c3c;
const long long infl = 0x3c3c3c3c3c3c3c3c;

int P,T;
vector<pair<int,int> > G[10003];
int dist[10003];
int rdist[10003];
void dijkstra(int* d, int s){
	priority_queue<pair<int,int> > pq;
	d[s] = 0;
	pq.push({0,s});
	while(!pq.empty()){
		int here = pq.top().second;
		int hereD = -pq.top().first;
		pq.pop();
		if(d[here] < hereD) continue;
		for(auto p : G[here]){
			int there = p.first;
			int cost = p.second;
			if(d[there] > d[here] + cost){
				d[there] = d[here] + cost;
				pq.push({-d[there], there});
			}
		}
	}
}
int main() {
	while(cin >> P >> T){
		memset(dist,0x3c,sizeof(dist));
		memset(rdist,0x3c,sizeof(rdist));
		for(int i = 0 ; i < 10003; i++) G[i].clear();
		for(int i = 0 ; i < T; i++){
			int u,v,l;
			cin >> u >> v >> l;
			G[u].push_back({v,l});
			G[v].push_back({u,l});
		}
		dijkstra(dist, 0);
		dijkstra(rdist, P-1);
		int ans = 0;
		for(int u = 0 ; u < P; u++){
			for(auto p : G[u]){
				int v = p.first;
				if(dist[u] + p.second + rdist[v] == dist[P-1]) ans += p.second;
			}
		}
		cout << 2*ans << endl;
	}

	return 0;
}