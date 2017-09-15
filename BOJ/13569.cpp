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

struct Dinic{
	struct edge{
		int to, cap, rev;
	};
	int size, src, sink;
	vector<vector<edge> > G;
	vector<int> level, iter;
	Dinic(){}
	Dinic(int size, int src, int sink) {
		this->size = size;
		this->src = src;
		this->sink = sink;
		G = vector<vector<edge> >(size);
		level = vector<int>(size, -1);
		iter = vector<int>(size, 0);
	}
	void addEdge(int from, int to, int cap){
		G[from].push_back({to, cap, (int)G[to].size()});
		G[to].push_back({from, 0, (int)G[from].size()-1});
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
};

struct LRMaxFlow{
	Dinic dinic;
	int size, src, sink, fsrc, fsink;
	vector<int> inSum, outSum;
	LRMaxFlow(int size, int src, int sink){
		this->size = size;
		this->src = src;
		this->sink = sink;
		fsrc = size;
		fsink = size + 1;
		dinic = Dinic(size + 2, fsrc, fsink);
		inSum = vector<int>(size, 0);
		outSum = vector<int>(size, 0);
	}
	void addEdge(int from, int to, int cap, int lower){
		dinic.addEdge(from, to, cap);
		inSum[to] += lower;
		outSum[from] += lower;
	}
	int getMaxflow(){
		for(int i = 0 ; i < size; i++) if(inSum[i]) dinic.addEdge(fsrc, i, inSum[i]);
		for(int i = 0 ; i < size; i++) if(outSum[i]) dinic.addEdge(i, fsink, outSum[i]);
		dinic.addEdge(sink, src, INF);
		return dinic.getMaxflow();
	}
};

double d;
int N, M;
int ansCell[200][200];
int ansCol[200], ansRow[200];
int maxCell[200][200];
int maxCol[200], maxRow[200];
int demCell[200][200];
int demCol[200], demRow[200];
int ROW(int x){
	return 2 + N + x;
}
int COL(int x){
	return 2 + x;
}
bool isRow(int x){
	return 2 + N <= x && x < 2 + N + M;
}
bool isCol(int x){
	return 2 <= x && x < 2 + N;
}
using edge = Dinic::edge;
int main() {
	fastio();
	int src = 0, sink = 1;
	cin >> M >> N;
	int size = 2 + N + M;
	LRMaxFlow lrFlow(size, src, sink);
	for(int i = 0 ; i < M; i++) {
		for(int j = 0 ; j < N; j++){
			cin >> d;
			int l = (int)floor(d);
			int r = (int)ceil(d);
			demCell[i][j] = l;
			maxCell[i][j] = r;
			lrFlow.addEdge(COL(j), ROW(i), r - l, l);
		}
		cin >> d;
		int l = (int)floor(d);
		int r = (int)ceil(d);
		demRow[i] = l;
		maxRow[i] = r;
		lrFlow.addEdge(ROW(i), sink, r - l, l);
	}
	for(int i = 0 ; i < N; i++) {
		cin >> d;
		int l = (int)floor(d);
		int r = (int)ceil(d);
		demCol[i] = l;
		maxCol[i] = r;
		lrFlow.addEdge(src, COL(i), r - l, l);
	}

	lrFlow.getMaxflow();

	vector<vector<edge> > G = lrFlow.dinic.G;

	for(auto e : G[src]){
		if(!isCol(e.to)) continue;
		int id = e.to - 2;
		ansCol[id] = maxCol[id] - e.cap;
	}

	for(auto e : G[sink]){
		if(!isRow(e.to)) continue;
		int id = e.to - 2 - N;
		ansRow[id] = maxRow[id] - G[e.to][e.rev].cap;
	}

	for(int i = 0 ; i < N; i++){
		for(auto e : G[COL(i)]){
			if(isRow(e.to)){
				int j = e.to - 2 - N;
				ansCell[j][i] = maxCell[j][i] - e.cap;
			}
		}
	}
	for(int i = 0 ; i < M; i++) {
		for(int j = 0 ; j < N; j++){
			cout << ansCell[i][j] << " ";
		}
		cout << ansRow[i] << endl;
	}
	for(int i = 0 ; i < N; i++) cout << ansCol[i] << " ";
	return 0;
}