// #include <bits/stdc++.h>
#include <iostream>
#include <cstdio>
#include <utility>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>
#include <set>
using namespace std;
const int mod = 1e9+7;
const int inf = 0x3c3c3c3c;
const long long infl = 0x3c3c3c3c3c3c3c3c;

int N,M;
vector<pair<int,int> > G[100003];
queue<int> q;
vector<int> ans;
vector<pair<int,int> > v;
set<int> st;
vector<pair<int,int> > par[100003];
int dist[100003];
int rdist[100003];
int parent[100003];
int main() {
	while(~scanf("%d%d",&N,&M)){
		memset(dist,-1,sizeof(dist));
		memset(rdist,-1,sizeof(rdist));
		for(int i = 0 ; i < 100003; i++) G[i].clear();
		while(!q.empty()) q.pop();
		while(!q.empty()) q.pop();
		ans.clear();
		v.clear();
		st.clear();

		for(int i = 0 ; i < M; i++){
			int a,b,c;
			scanf("%d%d%d",&a,&b,&c);
			G[a].push_back({c,b});
			G[b].push_back({c,a});
		}

		q.push(1);
		dist[1] = 0;
		while(!q.empty()){
			int here = q.front();
			q.pop();
			for(auto p : G[here]){
				int there = p.second;
				if(dist[there] != -1) continue;
				dist[there] = dist[here] + 1;
				q.push(there);
			}
		}

		p[here].push_back({here,0});
		q.push(1);
		while(!q.empty()){
			int here = q.front();
			q.pop();
			for(auto p : G[here]){
				int there = p.second;
				int color = p.first;
				if(dist[here] + 1 != dist[there]) continue;
				par[there].push_back({here, color});
				q.push(there);
			}
		}

		for(int p = N; par[p].first != p; p = par[p].frist){
			
		}

		reverse(ans.begin(), ans.end());

		printf("%d\n",ans.size());
		for(int i = 0 ; i < ans.size(); i++) {
			printf("%d",ans[i]);
			if(i<ans.size()-1) printf(" ");
		}
		printf("\n");
	}
	return 0;
}
