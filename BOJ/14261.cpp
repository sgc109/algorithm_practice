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

struct Edge{
	int u,v,rev,cap;
};
int n,m,k;
vector<Edge> G[203];
int w[103], par[203], paridx[203];
void connect(int a, int b, int c){
	Edge uv = Edge{a,b,(int)G[b].size(),c};
	Edge vu = Edge{b,a,(int)G[a].size(),0};
	G[a].push_back(uv);
	G[b].push_back(vu);
}
int IN(int x){return x;}
int OUT(int x){return 100+x;}
int maxflow(int src, int sink){
	int ret = 0;
	while(1){
		memset(par,-1,sizeof(par));
		queue<int> q;
		q.push(src);
		while(!q.empty()){
			int here = q.front();
			q.pop();
			for(int i = 0 ; i < (int)G[here].size(); i++){
				auto e = G[here][i];
				if(e.cap <= 0 || par[e.v] != -1) continue;
				par[e.v] = here;
				paridx[e.v] = i;
				q.push(e.v);
			}
		}
		if(par[sink] == -1) break;
		int minFlow = inf;
		for(int p = sink; p != src; p = par[p]) minFlow = min(minFlow, G[par[p]][paridx[p]].cap);
		for(int p = sink; p != src; p = par[p]) G[par[p]][paridx[p]].cap -= minFlow, G[p][G[par[p]][paridx[p]].rev].cap += minFlow;
		ret += minFlow;
	}
	return ret;
}
int main() {
	cin >> n >> m >> k;
	for(int i = 1 ; i <= n; i++) cin >> w[i];
	for(int i = 0 ; i < m; i++){
		int a,b;
		cin >> a >> b;
		connect(OUT(a), IN(b), inf);
		connect(OUT(b), IN(a), inf);
	}
	for(int i = 1 ; i <= n; i++) connect(IN(i), OUT(i), w[i] == -1 ? inf : w[i]);
	int ret = maxflow(IN(1), OUT(n));
	if(ret >= inf || ret > k) cout << "NO";
	else cout << "YES";

	return 0;
}