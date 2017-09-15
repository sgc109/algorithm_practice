// #include <bits/stdc++.h>
#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
#include <vector>
#include <string>
#include <algorithm>
#include <utility>
#include <set>
#include <map>
using namespace std;
typedef long long ll;
const int mod = 1e9+7;
const int inf = 0x3c3c3c3c;
const long long infl = 0x3c3c3c3c3c3c3c3c;

struct Edge {int u,v,cap,rev;};
int N,M;
int pane[303][303];
vector<Edge> G[200003];
int level[200003],iter[200003];
int IN(int i, int j){return i*M+j;}
int OUT(int i, int j){return 90000+i*M+j;}
int inRange(int i, int j){return 0 <= i && i < N && 0 <= j && j < M;}
void connect(int u, int v, int c){
	Edge uv = Edge{u,v,c,(int)G[v].size()};
	Edge vu = Edge{v,u,0,(int)G[u].size()};
	G[u].push_back(uv);
	G[v].push_back(vu);
}
int dfs(int here, int sink, int minFlow){
	if(here == sink) return minFlow;
	for(int& i = iter[here] ; i < (int)G[here].size(); i++){
		auto& e = G[here][i];
		if(e.cap <= 0 || level[e.v] != level[here] + 1) continue;
		int f = dfs(e.v, sink, min(minFlow, e.cap));
		if(f) {
			e.cap -= f;
			G[e.v][e.rev].cap += f;
			return f;
		}
	}
	return 0;
}
bool bfs(int src, int sink){
	memset(level,-1,sizeof(level));
	queue<int> q;
	q.push(src);
	level[src] = 0;
	while(!q.empty()){
		int here = q.front();
		q.pop();
		for(int i = 0 ; i < (int)G[here].size(); i++){
			auto e = G[here][i];
			if(e.cap <= 0 || level[e.v] != -1) continue;
			level[e.v] = level[here] + 1;
			q.push(e.v);
		}
	}
	return level[sink] != -1;
}
ll dinic(int src, int sink){
	ll ret = 0;
	while(1){
		if(!bfs(src, sink)) break;
		memset(iter,0,sizeof(iter));
		while(int f = dfs(src,sink,inf)) ret += f;
	}
	return ret;
}
int main() {
	cin >> N >> M;
	for(int i = 0 ; i < N; i++){
		for(int j = 0 ; j < M; j++){
			cin >> pane[i][j];
			for(int k = 0 ; k < 4; k++){
				int ni = i + "2110"[k] - '1';
				int nj = j + "1201"[k] - '1';
				if(!inRange(ni,nj)) continue;
				connect(OUT(ni,nj),IN(i,j),inf);
			}
			int c = 0;	
			if(pane[i][j] == -2) c = 0;
			else if(pane[i][j] == -1) c = inf;
			else c = pane[i][j];
			connect(IN(i,j), OUT(i,j), c);
		}
	}
	ll ret = dinic(IN(0,0), OUT(N-1,M-1));
	if(ret >= inf) ret = -1;
	cout << ret;
	return 0;
}