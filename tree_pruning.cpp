#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod = 1e9+7;
const int inf = 0x3c3c3c3c;
const long long infl = 0x3c3c3c3c3c3c3c3c;

int w[100003];
int ww[100003];
int size[100003];
ll sum[100003];
int id[100003];
ll dp[100003][203];
vector<int> G[100003];
int N, K, cnt;

void dfs(int u, int dad){
	ww[cnt] = w[u];
	id[u] = cnt++;
	for(int v : G[u]){
		if(v == dad) continue;
		dfs(v,u);
		size[id[u]] += size[id[v]];
		sum[id[u]] += sum[id[v]];
	}
	size[id[u]]++;
	sum[id[u]]+=w[u];
}

ll go(int pos, int k){
	if(pos == cnt) return 0;
	ll& cache = dp[pos][k];
	if(cache != -1) return cache;
	if(!k) return cache = go(pos+size[pos], k) + sum[pos];
	return cache = max(go(pos+size[pos], k-1), go(pos+1,k)+ww[pos]);
}

int main() {
	memset(dp,-1,sizeof(dp));
	scanf("%d%d",&N,&K);
	for(int i = 0 ; i < N; i++) scanf("%d",&w[i]);
	for(int i = 0 ; i < N-1; i++) {
		int a,b;
		scanf("%d%d",&a,&b);
		a--,b--;
		G[a].push_back(b);
		G[b].push_back(a);
	}
	dfs(0,-1);
	printf("%lld",go(0,K));
	return 0;
}
