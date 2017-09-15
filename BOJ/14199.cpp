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

struct MCMF{
	struct edge{
		int to, cap; 
		ll cost;
		int rev;
	};
	int size, src, sink;
	vector<vector<edge> > G;
	vector<ll> dist;
	vector<int> par, edgeIdx;
	MCMF(int size, int src, int sink){
		G = vector<vector<edge> >(size);
		par = vector<int>(size);
		edgeIdx = vector<int>(size);
		this->size = size;
		this->src = src;
		this->sink = sink;
	}
	bool spfa(){
		dist = vector<ll>(size, infl);
		vector<bool> inQ = vector<bool>(size, false);
		queue<int> q;
		q.push(src);
		inQ[src] = true;
		dist[src] = 0;
		while(!q.empty()){
			int here = q.front();
			q.pop();
			inQ[here] = false;
			for(int i = 0 ; i < (int)G[here].size(); i++){
				auto e = G[here][i];
				if(e.cap > 0 && dist[here] + e.cost < dist[e.to]) {
					dist[e.to] = dist[here] + e.cost;
					par[e.to] = here;
					edgeIdx[e.to] = i;
					if(!inQ[e.to]) q.push(e.to), inQ[e.to] = true;
				}
			}
		}
		return dist[sink] != infl;
	}
	pair<int,ll> getMCMF(){
		int maxFlow = 0;
		ll minCost = 0;
		while(1){
			if(!spfa()) break;
			int minFlow = inf;
			ll costSum = 0;
			for(int p = sink; p != src; p = par[p]){
				auto& e = G[par[p]][edgeIdx[p]];
				minFlow = min(minFlow, e.cap);
				costSum += e.cost;
			}
			for(int p = sink; p != src; p = par[p]){
				auto& e = G[par[p]][edgeIdx[p]];
				e.cap -= minFlow;
				G[e.to][e.rev].cap += minFlow;
			}
			maxFlow += minFlow;
			minCost += costSum * minFlow;
		}

		return {maxFlow, minCost};
	}
	void addEdge(int from, int to, int cap, ll cost){
		G[from].push_back({to, cap, cost, (int)G[to].size()});
		G[to].push_back({from, 0, -cost, (int)G[from].size()-1});
	}
};

int T, N, M;
int dist[130][130];
int s[130], n[130];
void floyd(){
	for(int k = 0 ; k < N; k++){
		for(int i = 0 ; i < N; i++){
			for(int j = 0 ; j < N; j++){
				dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
			}
		}
	}
}
int main() {
	fastio();
	cin >> T;
	while(T--){
		memset(dist,0x3c,sizeof(dist));
		cin >> N >> M;
		int src = N, sink = N + 1;
		MCMF mcmf(N + 2, src, sink);
		int sum1 = 0, sum2 = 0;
		for(int i = 0 ; i < N; i++) {
			cin >> s[i] >> n[i];
			sum1 += s[i], sum2 += n[i];
		}
		while(M--){
			int a, b;
			cin >> a >> b;
			a--, b--;
			dist[a][b] = dist[b][a] = 1;
		}
		if(sum1 != sum2){
			cout << -1 << '\n';
			continue;
		}
		floyd();
		int cntNd = 0, cntR = 0;
		int sum = 0;
		for(int i = 0 ; i < N; i++){
			if(s[i] < n[i]) mcmf.addEdge(i, sink, n[i] - s[i], 0);
			else if(s[i] > n[i]) sum += s[i] - n[i], mcmf.addEdge(src, i, s[i] - n[i], 0);
		}
		for(int i = 0 ; i < N; i++){
			for(int j = 0 ; j < N; j++){
				if(s[i] > n[i] && s[j] < n[j] && dist[i][j] < inf) mcmf.addEdge(i, j, inf, dist[i][j]);
			}
		}
		auto ans = mcmf.getMCMF();
		cout << (ans.first != sum || ans.second >= inf ? -1 : ans.second) << '\n';
	}
	return 0;
}