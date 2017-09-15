#include <bits/stdc++.h>
#define pb push_back
#define sz(v) ((int)(v).size())
#define all(v) (v).begin(), (v).end()
#define fastio() ios_base::sync_with_stdio(0),cin.tie(0)
using namespace std;
typedef long long ll;
const int MOD = 1e9+7;
const int INF = 0x3c3c3c3c;
const long long INFL = 0x3c3c3c3c3c3c3c3c;

struct MCMF{
	struct edge{
		int to, cap;
		double cost;
		int rev;
	};
	int size, src, sink;
	vector<vector<edge> > G;
	vector<double> dist;
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
		return dist[sink] != INF;
	}
	pair<int,double> getMCMF(){
		int maxFlow = 0;
		double minCost = 0;
		while(1){
			dist = vector<double>(size, INF);
			if(!spfa()) break;
			int minFlow = INF;
			double costSum = 0;
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
	void addEdge(int from, int to, int cap, double cost){
		G[from].push_back({to, cap, cost, (int)G[to].size()});
		G[to].push_back({from, 0, -cost, (int)G[from].size()-1});
	}
};

struct point{int x, y;};
bool cmp(point& a, point& b) {
	return a.y > b.y;
}
vector<point> points;
int N;
int NODE(int x){return 2 + x;}
int IN(int x){return 2 * x;}
int OUT(int x){return 2 * x + 1;}
double dist(point& a, point& b){
	return sqrt((a.x - b.x)*(a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}
int main() {
	int src = 0, sink = 1;
	fastio();
	cin >> N;
	MCMF mcmf(2 * (N + 2), src, sink);
	for(int i = 0 ; i < N; i++){
		int x, y;
		cin >> x >> y;
		points.push_back(point{x, y});
	}
	sort(all(points), cmp);
	for(int i = 0 ; i < N; i++){
		for(int j = i + 1; j < N; j++){
			if(points[i].y == points[j].y) continue;
			mcmf.addEdge(OUT(NODE(i)), IN(NODE(j)), 1, dist(points[i], points[j]));
		}
		mcmf.addEdge(src, OUT(NODE(i)), 2, 0);
		mcmf.addEdge(IN(NODE(i)), sink, 1, 0);
	}
	auto ret = mcmf.getMCMF();
	if(ret.first != N - 1) return !printf("-1");

	cout.precision(17);
	cout << fixed << ret.second;
	

	return 0;
}