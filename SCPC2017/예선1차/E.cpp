#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod = 1e9+7;
const int inf = 0x3c3c3c3c;
const long long infl = 0x3c3c3c3c3c3c3c3c;

int T,N,M;
vector<pair<int,int> > G[5003];
int dep[5003], par[5003], w[5003], check[5003];
int root;
void dfs(int here, int dad){
	for(auto p : G[here]){
		int there = p.first;
		if(there == dad) continue;
		par[there] = here;
		w[there] = p.second;
		dep[there] = dep[here] + 1;
		dfs(there, here);
	}
}
void up2lca(int a, int b){
	if(a == b) return;
	if(dep[a] > dep[b]) swap(a,b);
	while(dep[a] != dep[b]){
		check[b] = 1;
		b = par[b];
	}
	if(a == b) return;
	while(a != b){
		check[a] = check[b] = 1;
		a = par[a], b = par[b];
	}
}
int main() {
	setbuf(stdout,NULL);
	scanf("%d",&T);
	for(int t = 1; t <= T; t++){
		printf("Case #%d\n",t);
		scanf("%d%d",&N,&M);
		memset(par,0,sizeof(par));
		memset(w,0,sizeof(w));
		memset(dep,0,sizeof(dep));
		for(int i = 0 ; i < 5003; i++) G[i].clear();
		root = M;
		for(int i = 0 ; i < M-1; i++){
			int a,b,c;
			scanf("%d%d%d",&a,&b,&c);
			G[a].push_back({b,c});
			G[b].push_back({a,c});
		}
		dep[root] = 0;
		dfs(root, -1);
		ll ans = 0;
		for(int mask = 0 ; mask < (1<<N); mask++){
			memset(check,0,sizeof(check));
			vector<int> mlist;
			for(int i = 0 ; i < N; i++){
				if(mask & (1<<i)) mlist.push_back(i+1);
				else mlist.push_back(N+i+1);
			}
			for(int i = 0 ; i < (int)mlist.size(); i++){
				for(int j = i+1; j < (int)mlist.size(); j++){
					up2lca(mlist[i], mlist[j]);
				}
			}
			ll sum = 0;
			for(int i = 1 ; i <= M; i++) if(check[i]) sum += w[i];
			ans = max(ans, sum);
		}
		printf("%lld\n",ans);
	}
	return 0;
}