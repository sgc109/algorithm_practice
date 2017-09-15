#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod = 1e9+7;
const int inf = 0x3c3c3c3c;
const long long infl = 0x3c3c3c3c3c3c3c3c;

int N,M;
vector<int> G[1003];
int degree[1003];
int dist[1003];
int main() {
	while(cin >> N >> M){
		if(!N && !M) break;
		memset(dist,0x3c,sizeof(dist));
		memset(degree,0,sizeof(degree));
		for(int i = 0 ; i < 1003; i++) G[i].clear();
		for(int i = 0 ; i < M; i++){
			int u,v;
			cin >> u >> v;
			G[u].push_back(v);
			G[v].push_back(u);
			degree[u]++, degree[v]++;
		}
		int h1 = -1, h2 = -1;
		int ok = 1;
		for(int i = 1 ; i <= N; i++){
			if(!degree[i]) ok = 0;
			if(degree[i]%2) {
				if(h1 == -1) h1 = i;
				else h2 = i;
			}
		}
		if(!ok){
			cout << "Poor Koorosh" << endl;
			continue;
		}
		if(h1 == -1) {
			cout << 0 << endl;
			continue;
		}
		if(degree[h1] == 1 || degree[h2] == 1) {
			cout << "Poor Koorosh" << endl;
			continue;
		}
		dist[h1] = 0;
		queue<int> q;
		q.push(h1);
		while(!q.empty()){
			int here = q.front();
			q.pop();
			for(int there : G[here]){
				if(degree[there] == 2 || dist[there] != inf) continue;
				dist[there] = dist[here] + 1;
				q.push(there);
			}
		}
		if(dist[h2] == inf) cout << "Poor Koorosh" << endl;
		else cout << dist[h2] << endl;
	}
	return 0;
}