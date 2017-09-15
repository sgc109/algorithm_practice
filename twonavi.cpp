#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod = 1e9+7;
const int inf = 0x3c3c3c3c;
const long long infl = 0x3c3c3c3c3c3c3c3c;

int T,N,M;
ll dp[10003];
vector<pair<int,ll> > G1[10003], G2[10003];
vector<pair<int,ll> > Gr1[10003], Gr2[10003];
set<ll> par1[10003], par2[10003];
ll dist[10003];

void dijkstra(vector<pair<int,ll> > G[], set<ll> par[]){
	memset(dist,0x3c,sizeof(dist));
	priority_queue<pair<ll,int> > pq;
	dist[N] = 0;
	pq.push({0,N});
	while(!pq.empty()){
		auto p = pq.top();
		pq.pop();
		int here = p.second;
		ll curD = -p.first;
		if(dist[here] < curD) continue;
		for(auto pp : G[here]){
			int there = pp.first;
			ll cost = pp.second;
			if(dist[there] < curD + cost) continue;
			if(dist[there] == curD + cost) {
				par[there].insert(here);
				continue;
			}	
			else par[there].clear(), par[there].insert(here);

			dist[there] = curD + cost;
			pq.push({-dist[there], there});
		}
	}
}
int main() {
	setbuf(stdout,NULL);
	// T = 1;
	cin >> T;
	for(int t = 1 ; t <= T; t++){
		for(int i = 0 ; i < 10003; i++) G1[i].clear(), G2[i].clear();
		for(int i = 0 ; i < 10003; i++) Gr1[i].clear(), Gr2[i].clear();
		for(int i = 0 ; i < 10003; i++) par1[i].clear(), par2[i].clear();
		memset(dp,0x3c,sizeof(dp));

		cin >> N >> M;
		for(int i = 0 ; i < M; i++){
			int a,b,c,d;
			cin >> a >> b >> c >> d;
			G1[a].push_back({b,c});
			G2[a].push_back({b,d});

			Gr1[b].push_back({a,c});
			Gr2[b].push_back({a,d});
		}
		dijkstra(Gr1, par1);
		dijkstra(Gr2, par2);

		priority_queue<pair<ll,int> > pq;
		pq.push({0,1});
		dp[1] = 0;
		while(!pq.empty()){
			auto p = pq.top();
			pq.pop();
			ll hereD = -p.first;
			int here = p.second;

			if(dp[here] < hereD) continue;

			for(auto pp : G1[here]){
				int there = pp.first;
				int addAlarm = !par1[here].count(there) + !par2[here].count(there);
				if(dp[there] <= hereD + addAlarm) continue;
				dp[there] = hereD + addAlarm;
				pq.push({-dp[there], there});
			}
		}

		cout << "#testcase" << t <<endl;
		cout << dp[N] << endl;
	}
	return 0;
}
	