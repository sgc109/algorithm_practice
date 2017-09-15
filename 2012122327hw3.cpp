#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod = 1e9+7;
const int inf = 0x3c3c3c3c;
const long long infl = 0x3c3c3c3c3c3c3c3c;

int N,D,K,S,T,a;
vector<int> G[330];
int cap[330][330];
int level[330];
int iter[330];
int MAN(int x){return 2+x;}
int DISH(int x){return 2+200+x;}
void connect(int a, int b, int c){
	G[a].push_back(b);
	G[b].push_back(a);
	cap[a][b] = c;
}
int dfs(int here, int minF){
	if(here == T) return minF;
	for(int& i = iter[here] ; i < G[here].size(); i++){
		int there = G[here][i];
		if(level[there] != level[here] + 1 || cap[here][there] <= 0) continue;
		int f = dfs(there, min(minF, cap[here][there]));
		if(!f) continue;
		cap[here][there] -= f, cap[there][here] += f;
		return f;
	}
	return 0;
}
int bfs(){
	memset(level,-1,sizeof(level));
	queue<int> q;
	q.push(S);
	level[S] = 0;
	while(!q.empty() && level[T] == -1){
		int here = q.front();
		q.pop();
		for(int there : G[here]){
			if(level[there] != -1 || cap[here][there] <= 0) continue;
			level[there] = level[here] + 1;
			q.push(there);
		}
	}
	return level[T] != -1;
}
int dinic(){
	int ret = 0;
	while(1){		
		if(!bfs()) break;
		memset(iter,0,sizeof(iter));
		while(int f = dfs(S, inf)) ret += f;
	}
	return ret;
}
int main() {
	S = 0, T = 1;
	cin >> N >> K >> D;
	for(int i = 0 ; i < D; i++) {
		cin >> a;
		connect(DISH(i), T, a);
	}
	for(int i = 0 ; i < N; i++) {
		int n;
		cin >> n;
		for(int j = 0 ; j < n; j++){
			cin >> a;
			a--;
			connect(MAN(i), DISH(a), 1);
		}
	}
	for(int i = 0 ; i < N; i++) connect(S, MAN(i), K);
	cout << dinic();
	return 0;
}