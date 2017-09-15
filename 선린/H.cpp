#include <bits/stdc++.h>
#define fastio() ios_base::sync_with_stdio(0),cin.tie(0)
using namespace std;
typedef long long ll;
const int mod = 1e9+7;
const int INF = 0x3c3c3c3c;
const long long INFL = 0x3c3c3c3c3c3c3c3c;

int N, T, a, b, c;
int dist[50003], par[50003];
vector<pair<int,int> > G[50003];
int findFarest(int start){
	memset(dist,-1,sizeof(dist));
	queue<int> q;
	q.push(start);
	dist[start] = 0;
	int farest = 0;
	int farD = 0;
	while(!q.empty()){
		int cur = q.front();
		q.pop();
		for(auto p : G[cur]){
			int next = p.first;
			if(dist[next] != -1) continue;
			dist[next] = dist[cur] + 1;
			par[next] = cur;
			q.push(next);
			if(farD < dist[next]) farest = next, farD = dist[next];
		}
	}
	return farest;
}

int dfs(int cur, int dad, int d, int goal){
	int ret = INF;
	for(auto p : G[cur]){
		int next = p.first;
		int cost = p.second;
		if(next == dad) continue;
		int r = dfs(next, cur, d + 1, goal);
		ret = min(ret, r + cost);
	}
	if(ret == INF && d == goal) ret = 0;
	return ret;
}
int main() {
	fastio();
	cin >> N >> T;
	int sum = 0;
	for(int i = 0; i < N - 1; i++){
		cin >> a >> b >> c;
		sum += c;
		a--, b--;
		G[a].push_back({b, c});
		G[b].push_back({a, c});
	}
	if(N <= 2) return !printf("%d", (sum + T - 1) / T);
	int f1 = findFarest(0);
	int f2 = findFarest(f1);
	vector<int> centers;
	int rad = INF;
	for(int cur = f2; cur != f1; cur = par[cur]){
		int r = max(dist[f2] - dist[cur], dist[cur]);
		rad = min(rad, r);
	}
	for(int cur = f2; cur != f1; cur = par[cur]){
		int r = max(dist[f2] - dist[cur], dist[cur]);
		if(r == rad) centers.push_back(cur);
	}

	int ans = 0;
	if((int)centers.size() == 2){
		int r1 = dfs(centers[0], centers[1], 0, dist[f2] / 2);
		int r2 = dfs(centers[1], centers[0], 0, dist[f2] / 2);
		ans = r1 + r2;
		for(auto p : G[centers[0]]){
			int next = p.first;
			int cost = p.second;
			if(next == centers[1]) {
				ans += cost;
				break;
			}
		}
	}
	else {
		vector<int> v;
		for(auto p : G[centers[0]]){
			int next = p.first;
			int cost = p.second;
			v.push_back(cost + dfs(next, centers[0], 0, dist[f2] / 2 - 1));
		}
		sort(v.begin(), v.end());
		ans = v[0] + v[1];
	}

	cout << (ans + T - 1) / T;

	return 0;
}