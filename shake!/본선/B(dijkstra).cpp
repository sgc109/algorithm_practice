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

int N,M;
int pane[303][303];
ll dist[303][303];
int inRange(int i, int j){
	return 0 <= i && i < N && 0 <= j && j < M;
}
int main() {
	memset(dist,0x3c,sizeof(dist));
	cin >> N >> M;
	for(int i = 0 ; i < N; i++){
		for(int j = 0 ; j < M; j++){
			cin >> pane[i][j];
		}
	}
	priority_queue<pair<ll,pair<int,int> > > pq;
	vector<pair<int,int> > mlist;
	for(int i = 1; i < N; i++) mlist.push_back({i,0});
	for(int i = 1; i < M-1; i++) mlist.push_back({N-1,i});

	for(auto p : mlist){
		int i = p.first;
		int j = p.second;
		if(pane[i][j] == -2){
			dist[i][j] = 0;
			pq.push({0,{i,j}});
		}
		else if(pane[i][j] >= 0){
			dist[i][j] = pane[i][j];
			pq.push({-pane[i][j],{i,j}});
		}
	}
	while(!pq.empty()){
		auto p = pq.top();
		pq.pop();
		ll hereD = -p.first;
		int ci = p.second.first;
		int cj = p.second.second;
		if(dist[ci][cj] < hereD) continue;
		for(int k = 0 ; k < 8; k++){
			int ni = ci + "21100220"[k] - '1';
			int nj = cj + "12010202"[k] - '1';
			if(!inRange(ni,nj)) continue;
			ll c = 0;
			if(pane[ni][nj] == -1) c = infl;
			else if(pane[ni][nj] == -2) c = 0;
			else c = pane[ni][nj];
			if(dist[ni][nj] <= hereD + c) continue;
			dist[ni][nj] = hereD + c;
			pq.push({-dist[ni][nj], {ni,nj}});
		}
	}

	mlist.clear();
	for(int i = 1; i < M; i++) mlist.push_back({0,i});
	for(int i = 1; i < N-1; i++) mlist.push_back({i,M-1});
	ll ans = infl;
	for(auto p : mlist) ans = min(ans, dist[p.first][p.second]);
	if(ans == infl) ans = -1;
	cout << ans;
	return 0;
}