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
			while(int f = dfs(src, inf, sink)) ret += f;
		}
		return ret;
	}
};

struct point{
	int y, x;
};
int N, M;
int CELL(int i, int j){
	return i * M + j;	
}
int IN(int x){
	return 2 * x;
}
int OUT(int x){
	return 2 * x + 1;
}
bool inRange(int i, int j){
	return 0 <= i && i < N && 0 <= j && j < M;
}
point ps[7];
vector<int> cherry, straw;
point candle;
vector<int> vX, vY;
vector<int> tX, tY;
int main() {
	fastio();
	for(int i = 1; i <= 3; i++) cherry.pb(i);
	for(int i = 4; i <= 6; i++) straw.pb(i);
	cin >> N >> M;
	for(int i = 0 ; i < 7; i++) {
		cin >> ps[i].y >> ps[i].x;
		ps[i].y--, ps[i].x--;
		vY.pb(ps[i].y), vX.pb(ps[i].x);
	}
	sort(all(vY)), sort(all(vX));
	vY.erase(unique(all(vY)), vY.end());
	vX.erase(unique(all(vX)), vX.end());
	if(vY[0] >= 3) tY.pb(3);
	else tY.pb(vY[0]);
	for(int i = 1; i < sz(vY); i++){
		int diff = vY[i] - vY[i - 1];
		if(diff >= 4) tY.pb(tY.back() + 4);
		else tY.pb(tY.back() + diff);
	}
	if(vX[0] >= 3) tX.pb(3);
	else tX.pb(vX[0]);
	for(int i = 1; i < sz(vX); i++){
		int diff = vX[i] - vX[i - 1];
		if(diff >= 4) tX.pb(tX.back() + 4);
		else tX.pb(tX.back() + diff);
	}
	N = tY.back() + (N - vY.back() > 3 ? 4 : N - vY.back());
	M = tX.back() + (M - vX.back() > 3 ? 4 : M - vX.back());
	
	for(int i = 0 ; i < 7; i++){
		ps[i].y = tY[lower_bound(all(vY), ps[i].y) - vY.begin()];
		ps[i].x = tX[lower_bound(all(vX), ps[i].x) - vX.begin()];
	}

	int src = 2 * N * M, sink = 2 * N * M + 1;
	Dinic dinic(2 * N * M + 2, src, sink);
	for(int i = 0 ; i < N; i++){
		for(int j = 0 ; j < M; j++){
			if(ps[0].y == i && ps[0].x == j) continue;
			dinic.addEdge(IN(CELL(i, j)), OUT(CELL(i, j)), 1);
		}
	}
	for(int i = 0 ; i < N; i++){
		for(int j = 0 ; j < M; j++){
			for(int k = 0 ; k < 4; k++){
				int ni = i + "2110"[k] - '1';
				int nj = j + "1021"[k] - '1';
				if(!inRange(ni, nj)) continue;
				dinic.addEdge(OUT(CELL(i, j)), IN(CELL(ni, nj)), 1);
			}
		}
	}
	for(auto id : cherry) dinic.addEdge(src, IN(CELL(ps[id].y, ps[id].x)), 1);
	for(auto id : straw) dinic.addEdge(OUT(CELL(ps[id].y, ps[id].x)), sink, 1);

	int ans = dinic.getMaxflow();
	if(ans == 3) cout << "Yes";
	else cout << "No";
	return 0;
}