#include <bits/stdc++.h>
#define fastio() ios_base::sync_with_stdio(0),cin.tie(0)
using namespace std;
typedef long long ll;
const int mod = 1e9+7;
const int INF = 0x3c3c3c3c;
const long long INFL = 0x3c3c3c3c3c3c3c3c;

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

int N,M;
char pane[53][53];
vector<int> G[53];
int main() {
	fastio();
	cin >> N >> M;
	for(int i = 0 ; i < N; i++) cin >> pane[i];
	for(int i = 0 ; i < N; i++){
		for(int j = 0 ; j < M; j++){
			if(pane[i][j] == '.') continue;
			G[i].push_back(j);
		}
	}
	Hopcroft hop(G, N, M);
	cout << hop.getMaxMatch();
	return 0;
}