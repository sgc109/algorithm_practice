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

int N, M;
int ans[20003];
int id[203][203];
int upper[20003];
int main() {
	freopen("cooling.in", "r", stdin);
	freopen("cooling.out", "w", stdout);
	fastio();
	for(int i = 0 ; i < 203; i++) for(int j = 0 ; j < 203; j++) id[i][j] = 20000;
	cin >> N >> M;
	LRMaxFlow lr(N, 0, 0);
	for(int i = 0 ; i < M; i++) {
		int a, b, l, r;
		cin >> a >> b >> l >> r;
		a--, b--;
		id[a][b] = i;
		lr.addEdge(a, b, r - l, l);
		upper[i] = r;
	}

	int ret = lr.getMaxflow();
	int sum = 0;
	for(int i = 0 ; i < N; i++) sum += lr.inSum[i];
	if(sum != ret) return !printf("NO");
	for(int i = 0 ; i < N; i++){
		for(auto e : lr.dinic.G[i]){
			int num = id[i][e.to];
			ans[num] = upper[num] - e.cap;
		}
	}
	cout << "YES\n";
	for(int i = 0 ; i < M; i++) cout << ans[i] << "\n";
	return 0;
}