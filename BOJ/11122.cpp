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
int out[20], in[20];
int IN(int x){
	return x;
}
int OUT(int x){
	return N + x;
}
int main() {
	fastio();
	cin >> T;
	while(T--){
		memset(out,0,sizeof(out));
		memset(in,0,sizeof(in));
		cin >> N >> P;
		int src = 2 * N, sink = 2 * N + 1;
		MCMF mcmf(2 * N + 2, src, sink);
		for(int i = 0 ; i < N - 1; i++){
			for(int j = i + 1; j < N; j++){
				cin >> cst[i][j];
			}
		}
		for(int i = 0 ; i < N - 1; i++){
			for(int j = i + 1; j < N; j++){
				cin >> lim[i][j];
				mcmf.addEdge(OUT(i), IN(j), lim[i][j], -cst[i][j]);
			}
		}
		int ok = 1;
		int cur = 0;
		in[0] = P;
		for(int i = 0 ; i < N - 1; i++){
			for(int j = i + 1; j < N; j++){
				cin >> dem[i][j];
				out[i] += dem[i][j];
				in[j] += dem[i][j];
				mcmf.addEdge(IN(i), IN(j), dem[i][j], 0);
			}
			if(P < out[i]) ok = 0;
			cur += in[i];
			cur -= out[i];
			mcmf.addEdge(IN(i), OUT(i), cur, 0);
		}
		mcmf.addEdge(IN(N - 1), OUT(N - 1), P, 0);
		if(!ok) {
			cout << "0\n";
			continue;
		}
		for(int i = 0 ; i < N - 1; i++) {
			mcmf.addEdge(OUT(i), IN(i + 1), P - out[i], 0);
		}
		mcmf.addEdge(src, IN(0), inf, 0);
		mcmf.addEdge(OUT(N - 1), sink, inf, 0);
		cout << -mcmf.getMCMF().second << '\n';
	}
	return 0;
}