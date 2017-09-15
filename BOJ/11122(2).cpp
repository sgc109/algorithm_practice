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
		int to, cap, cost, rev;
	};
	int size, src, sink;
	vector<vector<edge> > G;
	vector<int> dist, par, edgeIdx;
	MCMF(int size, int src, int sink){
		G = vector<vector<edge> >(size);
		par = vector<int>(size);
		edgeIdx = vector<int>(size);
		this->size = size;
		this->src = src;
		this->sink = sink;
	}
	bool spfa(){
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
		if(dist[sink] >= 0) return false;
		return dist[sink] != inf;
	}
	pair<int,int> getMCMF(){
		int maxFlow = 0;
		int minCost = 0;
		while(1){
			dist = vector<int>(size, inf);
			if(!spfa()) break;
			int minFlow = inf;
			int costSum = 0;
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
	void addEdge(int from, int to, int cap, int cost){
		G[from].push_back({to, cap, cost, (int)G[to].size()});
		G[to].push_back({from, 0, -cost, (int)G[from].size()-1});
	}
};


int T, N, P;
int lim[20][20], cst[20][20], dem[20][20];
int main() {
	fastio();
	cin >> T;
	while(T--){
		cin >> N >> P;
		int src = N, sink = N + 1;
		MCMF mcmf(N + 2, src, sink);
		for(int i = 0 ; i < N - 1; i++){
			for(int j = i + 1; j < N; j++){
				cin >> cst[i][j];
			}
		}
		for(int i = 0 ; i < N - 1; i++){
			for(int j = i + 1; j < N; j++){
				cin >> lim[i][j];
				mcmf.addEdge(i, j, lim[i][j], -cst[i][j]);
			}
		}
		int sum = 0;
		for(int i = 0 ; i < N - 1; i++){
			for(int j = i + 1; j < N; j++){
				cin >> dem[i][j];
				sum += dem[i][j];
				mcmf.addEdge(i, j, dem[i][j], -5000000);
			}
			mcmf.addEdge(i, i + 1, P, 0);
		}
		mcmf.addEdge(src, 0, P, 0);
		mcmf.addEdge(N - 1, sink, P, 0);
		auto ans = mcmf.getMCMF();
		cout << -ans.second - sum * 5000000 << '\n';
	}	
	return 0;
}