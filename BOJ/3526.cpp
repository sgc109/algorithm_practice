#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9+7;
const int INF = 0x3c3c3c3c;
const long long INFL = 0x3c3c3c3c3c3c3c3c;

int N,M;
vector<pair<int,int> > G[100003];
queue<int> q;
vector<int> ans;
vector<pair<int,int> > v;
set<int> st;
int dist[100003];
int rdist[100003];
int parent[100003];
void bfs(int S, int* d){
	while(!q.empty()) q.pop();
	q.push(S);
	d[S] = 0;
	while(!q.empty()){
		int here = q.front();
		q.pop();
		for(auto p : G[here]){
			int there = p.second;
			if(d[there] != -1) continue;
			d[there] = d[here] + 1;
			q.push(there);
		}
	}
}
int main() {
	scanf("%d%d",&N,&M);
	memset(dist,-1,sizeof(dist));
	memset(rdist,-1,sizeof(rdist));
	for(int i = 0 ; i < 100003; i++) G[i].clear();
	
	ans.clear();
	v.clear();
	st.clear();

	for(int i = 0 ; i < M; i++){
		int a,b,c;
		scanf("%d%d%d",&a,&b,&c);
		G[a].push_back({c,b});
		G[b].push_back({c,a});
	}

	bfs(1,dist);
	bfs(N,rdist);

	q.push(1);
	while(!q.empty()){
		if(q.front() == N) break;
		v.clear();
		while(!q.empty()) {
			int here = q.front();
			q.pop();
			for(auto p : G[here]) {
				int there = p.second;
				if(dist[here]+1 != dist[there] || dist[there] + rdist[there] != dist[N]) continue;
				v.push_back(p);
			}
		}
		if(v.size()==0) break;
		sort(v.begin(), v.end());
		int col = v[0].first;
		ans.push_back(col);
		st.clear();
		for(int i = 0 ; i < v.size(); i++) {
			if(v[i].first > col) break;
			st.insert(v[i].second);
		}
		for(auto x : st) q.push(x);
	}

	printf("%d\n",ans.size());
	for(int i = 0 ; i < ans.size(); i++) {
		printf("%d ",ans[i]);
	}
	return 0;
}
