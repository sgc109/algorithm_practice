#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9+7;
const int INF = 0x3c3c3c3c;
const long long INFL = 0x3c3c3c3c3c3c3c3c;

int N, M;
int par[200003];
int size[200003];
int realNode[200003];
long long sum[200003];

int findReal(int u){
	if(realNode[u] == -1) return u;
	return realNode[u];
}
int find(int u){
	if(u == par[u]) return u;
	return par[u] = find(par[u]);
}
void merge(int u, int v){
	u = find(u), v = find(v);
	if(u == v) return;
	par[u] = v;
	size[v] += size[u];
	sum[v] += sum[u];
}

void migrate(int u, int v){
	v = find(v);
	if(find(u) == v) return;
	size[find(u)]--;
	sum[find(u)]-=u;
	size[v]++;
	sum[v]+=u;

	realNode[u] = N+1;
	par[N+1] = v;
	size[N+1] = 1;
	sum[N+1] = u;
	N++;
}
int main() {
	freopen("output.txt","w",stdout);
	while(scanf("%d%d",&N,&M) != -1){
		memset(realNode, -1, sizeof(realNode));
		for(int i = 0 ; i < 200003; i++) par[i] = i, size[i] = 1, sum[i] = i;
		for(int i = 0 ; i < M; i++){
			int op,a,b,c;
			scanf("%d",&op);
			if(op==1){
				scanf("%d%d",&a,&b);
				merge(findReal(a),findReal(b));
			}
			else if(op==2){
				scanf("%d%d",&a,&b);
				migrate(findReal(a),findReal(b));
			}
			else if(op==3){
				scanf("%d",&a);
				a = find(findReal(a));
				printf("%d %lld\n", size[a], sum[a]);
			}
		}
	}		
	return 0;
}
