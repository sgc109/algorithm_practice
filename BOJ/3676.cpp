#include <bits/stdc++.h>
#define pb push_back
#define sz(v) ((int)(v).size())
#define all(v) (v).begin(), (v).end()
using namespace std;
typedef long long ll;
const int mod = 1e9+7;
const int inf = 0x3c3c3c3c;
const long long infl = 0x3c3c3c3c3c3c3c3c;

int T, N, M;
vector<pair<int,int> > G[50003];
int freq[50003];
ll fsum[50003];
ll dist[50003];
int root;
ll ans;
vector<int> ansv;
int dfs(int cur, int dad){
	fsum[cur] = freq[cur];
	for(auto p : G[cur]){
		int nxt = p.first;
		if(nxt == dad) continue;
		dist[nxt] = dist[cur] + p.second;
		fsum[cur] += dfs(nxt, cur);
	}
	return fsum[cur];
}
void go(int cur, ll an, int dad){
	ans = min(ans, an);
	for(auto p : G[cur]){
		int nxt = p.first;
		int cst = p.second;
		if(nxt == dad) continue;
		go(nxt, an + (fsum[root] - 2 * fsum[nxt]) * 2 * cst, cur);
	}
}
void trace(int cur, ll an, int dad){
	if(an == ans) ansv.pb(cur);
	for(auto p : G[cur]){
		int nxt = p.first;
		int cst = p.second;
		if(nxt == dad) continue;
		trace(nxt, an + (fsum[root] - 2 * fsum[nxt]) * 2 * cst, cur);
	}
}
int main() {
	root = 1;
	scanf("%d", &T);
	while(T--){
		ansv.clear();
		ans = 1e18;
		memset(freq,0,sizeof(freq));
		memset(fsum,0,sizeof(fsum));
		memset(dist,0,sizeof(dist));
		for(int i = 0 ; i < 50003; i++) G[i].clear();
		scanf("%d", &N);
		for(int i = 0 ; i < N - 1; i++){
			int a, b, c;
			scanf("%d %d %d\n", &a, &b, &c);
			G[a].pb({b, c});
			G[b].pb({a, c});
		}
		scanf("%d", &M);
		for(int i = 0 ; i < M; i++){
			int a, b;
			scanf("%d %d\n", &a, &b);
			freq[a] = b;
		}
		dist[root] = 0;
		dfs(root, 0);
		ll fir = 0;
		for(int i = 1 ; i <= N; i++) fir += 2 * dist[i] * freq[i];
		go(root, fir, 0);
		trace(root, fir, 0);
		printf("%lld\n", ans);
		sort(all(ansv));
		for(int i = 0 ; i < sz(ansv); i++) printf("%d ", ansv[i]);
		printf("\n");
	}
	return 0;
}