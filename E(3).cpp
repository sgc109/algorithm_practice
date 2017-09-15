#include <bits/stdc++.h>
#define fastio() ios_base::sync_with_stdio(false),cin.tie(NULL)
using namespace std;
typedef long long ll;
const int mod = 1e9+7;
const int INF = 0x3c3c3c3c;
const long long INFL = 0x3c3c3c3c3c3c3c3c;

int n,m;
vector<int> G[100003], Gr[100003];
int lowest[100003];
int deg[100003], rdeg[100003];
priority_queue<pair<int,int> > pq;
queue<int> q;
int ans[100003];
int cnt;
int main() {
	memset(lowest,0x3c,sizeof(lowest));
	fastio();
	cin >> n >> m;
	for(int i = 0 ; i < m; i++){
		int a, b;
		cin >> a >> b;
		G[a].push_back(b);
		Gr[b].push_back(a);
		deg[b]++;
		rdeg[a]++;
	}
	for(int i = 1 ; i <= n; i++) if(!rdeg[i]) q.push(i);
	while(!q.empty()){
		int cur = q.front();
		q.pop();
		lowest[cur] = min(lowest[cur], cur);
		for(int next : Gr[cur]){
			lowest[next] = min(lowest[next], lowest[cur]);
			rdeg[next]--;
			if(!rdeg[next]) q.push(next);
		}
	}

	for(int i = 1; i <= n; i++) if(!deg[i]) pq.push({-lowest[i], -i});
	while(!pq.empty()){
		auto p = pq.top();
		pq.pop();
		int cur = -p.second;
		ans[cur] = ++cnt;
		for(int next : G[cur]){
			deg[next]--;
			if(!deg[next]) pq.push({-lowest[next], -next});
		}
	}

	for(int i = 1; i <= n; i++) cout << ans[i] << " ";
	return 0;
}