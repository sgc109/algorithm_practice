#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod = 1e9+7;
const int INF = 0x3c3c3c3c;
const long long INFL = 0x3c3c3c3c3c3c3c3c;

struct edge{int to, cap, rev;};

class Dinic{
	int size, src, sink;
	vector<vector<edge> > G;
	vector<int> level, iter;
public:
	Dinic(){}
	Dinic(vector<edge>* graph, int size, int src, int sink) {
		this->size = size;
		this->src = src;
		this->sink = sink;
		G = vector<vector<edge> >(size);
		level = vector<int>(size, -1);
		iter = vector<int>(size, 0);
		for(int i = 0 ; i < size; i++) G[i] = graph[i];
	}
	bool bfs(int src, int sink){
		queue<int> q;
		q.push(src);
		level[src] = 0;
		while(!q.empty() && level[sink] == -1){
			int here = q.front();
			q.pop();
			for(auto e : G[here]){
				if(e.cap <= 0 || level[e.to] != -1) continue;
				level[e.to] = level[here] + 1;
				q.push(e.to);
			}
		}
		return level[sink] != -1;
	}

	int dfs(int here, int minFlow, int sink){
		if(here == sink) return minFlow;
		for(int& i = iter[here]; i < (int)G[here].size(); i++){
			auto& e = G[here][i];
			if(e.cap == 0 || level[e.to] != level[here] + 1) continue;
			int f = dfs(e.to, min(minFlow, e.cap), sink);
			if(f > 0){
				e.cap -= f;
				G[e.to][e.rev].cap += f;
				return f;
			}
		}
		return 0;
	}
	int getMaxflow(){
		int ret = 0;
		while(1){
			level = vector<int>(size, -1);
			iter = vector<int>(size, 0);
			if(!bfs(src, sink)) break;
			while(int f = dfs(src, INF, sink)) ret += f;
		}
		return ret;
	}
	vector<vector<edge> > getGraph(){
		return G;
	}
};

int N;
int IN(int x){
	return x;
}
int OUT(int x){
	return x + 1;
}
int CELL(int i, int j){
	return 2 + 2 * N + 2 * (i * N + j);
}
int ROWSUM(int i){
	return 2 + i;
}
int COLSUM(int j){
	return 2 + N + j;
}
vector<edge> G[5200];
void connect(int from, int to, int cap){
	G[from].push_back(edge{to, cap, (int)G[to].size()});
	G[to].push_back(edge{from, 0, (int)G[from].size()-1});
}

int a, sum;
int rowsum[5200], colsum[5200];
int ans[53][53];

void makeGraph(int src, int sink, int limit){
	for(int i = 0 ; i < 5200; i++) G[i].clear();
	for(int i = 0 ; i < N; i++){
		for(int j = 0 ; j < N; j++){
			connect(IN(CELL(i, j)), OUT(CELL(i, j)), limit);
		}
	}
	for(int i = 0 ; i < N; i++){
		for(int j = 0 ; j < N; j++){
			connect(OUT(CELL(i, j)), ROWSUM(i), INF);
		}
	}
	for(int j = 0 ; j < N; j++){
		for(int i = 0 ; i < N; i++){
			connect(COLSUM(j), IN(CELL(i, j)), INF);
		}
	}
	for(int i = 0 ; i < N; i++) connect(src, COLSUM(i), colsum[i]);
	for(int i = 0 ; i < N; i++) connect(ROWSUM(i), sink, rowsum[i]);
}
int main() {
	int src = 0, sink = 1;

	cin >> N;
	for(int i = 0 ; i < N; i++) cin >> rowsum[i];
	for(int i = 0 ; i < N; i++) cin >> colsum[i];
	for(int i = 0 ; i < N; i++) sum += rowsum[i];

	int lo = 0, hi = 10001;
	while(lo < hi){
		int mid = (lo + hi)/2;
		makeGraph(src, sink, mid);
		Dinic d(G, 5200, src, sink);
		int maxflow = d.getMaxflow();
		if(maxflow == sum) hi = mid;
		else lo = mid + 1;
	}
	cout << lo << endl;

	makeGraph(src, sink, lo);
	Dinic dinic(G, 5200, src, sink);
	dinic.getMaxflow();
	vector<vector<edge> > graph = dinic.getGraph();

	for(int i = 0 ; i < 5200; i++){
		for(auto e : graph[i]){
			int j = e.to;
			if(i == src || i == sink || j == src || j == sink) continue;
			if(i + 1 != j) continue;
			int num = (i - 2 - 2*N)/2;
			ans[num/N][num%N] = lo - e.cap;
		}
	}

	for(int i = 0 ; i < N; i++){
		for(int j = 0 ; j < N; j++){
			cout << ans[i][j] << " ";
		}
		cout << endl;
	}

	return 0;
}	