#include <bits/stdc++.h>
using namespace std;

class Hopcroft{
	int aSize, bSize;
	vector<vector<int> > G;
	vector<int> level, iter;
	vector<int> aMatch, bMatch;
public:
	Hopcroft(vector<int>* graph, int aSize, int bSize){
		this->aSize = aSize;
		this->bSize = bSize;
		G = vector<vector<int> >(aSize);
		level = vector<int>(aSize, -1);
		iter = vector<int>(aSize, 0);
		aMatch = vector<int>(aSize, -1);
		bMatch = vector<int>(bSize, -1);
		for(int i = 0 ; i < aSize; i++) G[i] = graph[i];
	}
	void bfs(){
		queue<int> q;
		for(int a = 0 ; a < aSize; a++) {
			if(aMatch[a] == -1) {
				level[a] = 0;
				q.push(a);
			}
		}
		while(!q.empty()) {
			int a = q.front();
			q.pop();
			for(int& i = iter[a]; i < (int)G[a].size(); i++){
				int b = G[a][i];
				if(bMatch[b] == -1 || level[bMatch[b]] != -1) continue;
				level[bMatch[b]] = level[a] + 1;
				q.push(bMatch[b]);	
			}
		}
	}
	bool dfs(int a){
		for(int b : G[a]){
			if(bMatch[b] == -1 || (level[bMatch[b]] == level[a] + 1 && dfs(bMatch[b]))) {
				aMatch[a] = b;
				bMatch[b] = a;
				return true;
			}
		}
		return false;
	}
	int getMaxMatch(){
		int ret = 0;
		while(1){
			level = vector<int>(aSize, -1);
			iter = vector<int>(aSize, 0);
			bfs();
			int add = 0;
			for(int a = 0 ; a < aSize; a++) {
				if(level[a] == 0 && dfs(a)) add++;
			}
			if(!add) break;
			ret += add;
		}
		return ret;
	}
};

struct Point{
	double x,y;
};
int N, M, S, V;
double x, y;
vector<Point> rats, holes;
double distSqr(Point a, Point b){
	return pow(a.x - b.x, 2) + pow(a.y - b.y, 2);
}
vector<int> G[103];
int main() {
	cin >> N >> M >> S >> V;
	for(int i = 0 ; i < N; i++){
		cin >> x >> y;
		rats.push_back({x, y});
	}
	for(int i = 0 ; i < M; i++){
		cin >> x >> y;
		holes.push_back({x, y});
	}
	for(int i = 0 ; i < N; i++){
		for(int j = 0 ; j < M; j++){
			if(distSqr(rats[i], holes[j]) <= S*S*V*V + 1e-9) G[i].push_back(j);
		}
	}
	Hopcroft hop(G, N, M);
	cout << N - hop.getMaxMatch();
	return 0;
}