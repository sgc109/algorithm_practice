#include <bits/stdc++.h>
#define pb push_back
#define sz(v) ((int)(v).size())
#define all(v) (v).begin(), (v).end()
#define fastio() ios_base::sync_with_stdio(false),cin.tie(NULL)
using namespace std;
typedef long long ll;
const int mod = 1e9+7;
const int inf = 0x3c3c3c3c;
const long long infl = 0x3c3c3c3c3c3c3c3c;

int N, K;
vector<pair<int,int> > G[200003];
int size[200003], vis[200003];
int dfs(int cur, int dad){
	size[cur] = 1;
	for(auto p : G[cur]){
		int nxt = p.first;
		int cost = p.second;
		if(nxt == dad) continue;
		size[cur] += dfs(nxt, cur);
	}
	return size[cur];
}
int getCentroid(int cur, int dad, int lim){
	for(auto p : G[cur]){
		int nxt = p.first;
		int cost = p.second;
		if(nxt == dad) continue;
		if(size[nxt] > lim) return getCentroid(nxt, cur, lim);
	}
	return cur;
}
void go(int cur, int dad){
	dfs(cur, dad);
	int cent = getCentroid(cur, dad, size[cur] / 2);
	vis[cent] = 1;
	map<int,ll> mp;
	for(auto p : G[cent]){
		int nxt = p.first;
		int cost = p.second;
		if(vis[nxt]) continue;
		go(nxt, cent);
	}
}

int main() {
	// fastio();
	cin >> N >> K;
	for(int i = 0 ; i < N - 1; i++){
		int a, b, c;
		cin >> a >> b >> c;
		G[a].pb({b, c});
		G[b].pb({a, c});
	}
	go(0, -1);
	return 0;
}