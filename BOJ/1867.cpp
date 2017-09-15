#include <bits/stdc++.h>
#define fastio() ios_base::sync_with_stdio(0),cin.tie(0)
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

int N, K;
int check[503][503];
vector<edge> G[1002];
int ROW(int x){return 2 + x;}
int COL(int x){return 2 + N + x;}
void connect(int from, int to, int cap){
	G[from].push_back({to, cap, (int)G[to].size()});
	G[to].push_back({from, 0, (int)G[from].size()-1});
}
int main() {
	int src = 0, sink = 1;
	fastio();
	cin >> N >> K;
	for(int i = 0; i < K; i++){
		int a, b;
		cin >> a >> b;
		a--, b--;
		connect(ROW(a), COL(b), 1);
	}
	for(int i = 0 ; i < N; i++) connect(src, ROW(i), 1), connect(COL(i), sink, 1);
	Dinic dinic(G, 2 + 2 * N, src, sink);
	cout << dinic.getMaxflow();
	return 0;
}