#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9+7;
const int INF = 0x3c3c3c3c;
const long long INFL = 0x3c3c3c3c3c3c3c3c;

int N,M;
int par[200003];
int size[200003];
long long sum[200003];

int op,a,b,c;

// find 와 merge는 일반적인 union-find와 완전히 똑같다.
int find(int u){
	return par[u] == u ? u : par[u] = find(par[u]);
}
void merge(int u, int v){
	u = find(u), v = find(v);
	if(u == v) return;
	par[u] = v;
	size[v] += size[u];
	sum[v] += sum[u];
}
void migrate(int u, int v){
	int ur = find(u);
	int vr = find(v);
	size[ur]--;
	sum[ur]-=u;
	size[vr]++;
	sum[vr]+=u;
	par[u] = vr; // 옮기려는 노드 하나만 똑 떼어 옮기려는 집합에 직접 톡 붙인다.
}
int main() {
	while(scanf("%d%d",&N, &M) != -1){
		for(int i = 1 ; i <= N; i++) {
			par[i] = i+N, size[i] = 1, sum[i] = i; // 맨처음에 각 집합(원소 i)의 관리자 노드는 i+N로 준다.
			par[i+N] = i+N, size[i+N] = size[i], sum[i+N] = sum[i]; // 관리자 노드의 크기와 번호는 0으로 보고 계산.
		}
		for(int i = 0 ; i < M; i++) {
			scanf("%d",&op);
			if(op == 1){
				scanf("%d%d",&a,&b);
				merge(a,b);
			}
			else if(op == 2){
				scanf("%d%d",&a,&b);
				migrate(a,b);
			}
			else if(op == 3){
				scanf("%d",&a);
				a = find(a);
				printf("%d %lld\n", size[a], sum[a]);
			}
		}
	}		
	return 0;
}
