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
vector<edge> G[303];
void connect(int from, int to, int cap){
	G[from].push_back({to, cap, (int)G[to].size()});
	G[to].push_back({from, 0, (int)G[from].size()-1});
}
int N, M, T;
int think[303];
int main() {
	int src = 0, sink = 1;
	while(1){
		for(int i = 0 ; i < 303; i++) G[i].clear();
		cin >> N >> M;
		if(!N && !M) break;
		for(int i = 0 ; i < N; i++) cin >> think[i];
		for(int i = 0 ; i < M; i++){
			int a,b;
			cin >> a >> b;
			if(think[a-1] == think[b-1]) {
				connect(a + 1, b + 1, 1);
				connect(b + 1, a + 1, 1);
				continue;
			}
			if(think[a-1]) swap(a, b);
			connect(a + 1, b + 1, 1);
		}
		for(int i = 0 ; i < N; i++){
			if(think[i]) connect(i + 2, sink, 1);
			else connect(src, i + 2, 1);
		}
		Dinic dinic(G, 303, src, sink);
		cout << dinic.getMaxflow() << endl;
	}
	return 0;
}