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

vector<edge> G[20003];
int N,M;
char pane[103][103];
int IN(int x){return 2*x;}
int OUT(int x){return 2*x+1;}
int CELL(int i, int j){return i*M+j;}
bool inRange(int i, int j){
	return 0 <= i && i < N && 0 <= j && j < M;
}

void connect(int from, int to, int cap){
	G[from].push_back({to, cap, (int)G[to].size()});
	G[to].push_back({from, 0, (int)G[from].size()-1});
}
int main() {
	// fastio();
	int src = 0, sink = 0;
	cin >> N >> M;
	for(int i = 0 ; i < N; i++){
		cin >> pane[i];
		for(int j = 0 ; j < M; j++){
			char c = pane[i][j];
			if(c == 'K') src = IN(CELL(i, j));
			else if(c == 'H') sink = OUT(CELL(i, j));
		}
	}
	for(int i = 0 ; i < N; i++){
		for(int j = 0 ; j < M; j++){
			if(pane[i][j] == 'K'){
				for(int k = 0 ; k < 4; k++){
					int ni = i + "2110"[k] - '1';
					int nj = j + "1201"[k] - '1';
					if(!inRange(ni, nj) || pane[ni][nj] != 'H') continue;
					return !printf("-1");
				}
			}
		}
	}
	for(int i = 0 ; i < N; i++){
		for(int j = 0 ; j < M; j++){
			for(int k = 0 ; k < 4; k++){
				int ni = i + "2110"[k] - '1';
				int nj = j + "1201"[k] - '1';
				if(!inRange(ni, nj)) continue;
				connect(OUT(CELL(i, j)), IN(CELL(ni, nj)), 1);
			}
			int cap = 0;
			char c = pane[i][j];
			if(c == '#') cap = 0;
			else if(c == 'H' || c == 'K') cap = INF;
			else if(c == '.') cap = 1;
			connect(IN(CELL(i, j)), OUT(CELL(i, j)), cap);
		}
	}

	Dinic dinic(G, 2*N*M, src, sink);

	cout << dinic.getMaxflow();
	return 0;
}