#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod = 1e9+7;
const int inf = 0x3c3c3c3c;
const long long infl = 0x3c3c3c3c3c3c3c3c;

int T,N,M,K;
vector<pair<int,int> > G[100003];
int nearest[100003];
vector<int> shelter;
ll dist[100003];
void dijkstra(){
	priority_queue<pair<int,pair<int,int> > > pq;
	for(int n : shelter) pq.push({0,{n,n}}), dist[n] = 0, nearest[n] = n;
	while(!pq.empty()){
		auto p = pq.top();
		pq.pop();
		int here = p.second.first;
		int hereD = -p.first;
		int from = p.second.second;

		if(dist[here] < hereD) continue;
		if(dist[here] == hereD && nearest[here] < from) from = nearest[here];

		for(auto pp : G[here]){
			int there = pp.first;
			int cost = pp.second;
			if(dist[there] < hereD + cost) continue;
			else if(dist[there] == hereD + cost) nearest[there] = min(nearest[there], from);
			else {
				dist[there] = hereD + cost;
				nearest[there] = from;
				pq.push({-(hereD + cost), {there, from}});
			}
		}
	}
}
int main() {
	cin >> T;
	for(int t = 1; t <= T; t++){
		for(int i = 0 ; i < 100003; i++) G[i].clear();
		memset(dist,0x3c,sizeof(dist));
		shelter.clear();
		cin >> N >> M >> K;
		for(int i = 0 ; i < M; i++){
			int a,b,c;
			cin >> a >> b >> c;
			G[a].push_back({b,c});
			G[b].push_back({a,c});
		}
		for(int i = 0 ; i < K; i++){
			int n;
			cin >> n;
			shelter.push_back(n);
		}

		dijkstra();
		ll ans1 = 0;
		ll ans2 = 0;
		for(int i = 1 ; i <= N; i++) ans1 += dist[i], ans2 += nearest[i];

		cout << "Case #" << t << endl;
		cout << ans1 << endl << ans2 << endl;
	}
	return 0;
}
	