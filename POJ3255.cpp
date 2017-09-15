// #include <bits/stdc++.h>
#include <set>
#include <map>
#include <cmath>
#include <stack>
#include <queue>
#include <cstdio>
#include <vector>
#include <cstring>
#include <utility>
#include <iostream>
#include <algorithm>
#define pb push_back
#define sz(v) ((int)(v).size())
#define all(v) (v).begin(), (v).end()
using namespace std;
typedef long long ll;
const int mod = 1e9+7;
const int inf = 0x3c3c3c3c;
const long long infl = 0x3c3c3c3c3c3c3c3c;
vector<int> dist[5003];
int V, E;
vector<pair<int,int> > G[5003];
priority_queue<pair<int,int> > pq;

int push(int node, int d){
	for(int i = 0 ; i < sz(dist[node]); i++) if(dist[node][i] == d) return 0;
	if(sz(dist[node]) == 2 && dist[node][1] < d) return 0;
	dist[node].pb(d);
	sort(all(dist[node]));
	dist[node] = vector<int>(dist[node].begin(), dist[node].begin() + min(sz(dist[node]), 2));
	return 1;
}
void dijkstra(int s, int e){
	dist[s].pb(0);
	pq.push(make_pair(0, s));
	while(!pq.empty()){
		pair<int,int> p = pq.top();
		pq.pop();
		int curD = -p.first;
		int cur = p.second;
		if(dist[cur].back() < curD) continue;
		for(int i = 0 ; i < sz(G[cur]); i++){
			pair<int,int> pp = G[cur][i];
			int next = pp.first;
			int cost = curD + pp.second;
			if(!push(next, cost)) continue;

			pq.push(make_pair(-cost, next));
		}
	}
}
int main() {
	scanf("%d %d", &V, &E);
	while(E--){
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		G[a].pb(make_pair(b, c));
		G[b].pb(make_pair(a, c));
	}
	dijkstra(1, V);
	printf("%d", dist[V][1]);
	return 0;
}