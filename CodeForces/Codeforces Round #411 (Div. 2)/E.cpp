#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9+7;
const int INF = 0x3c3c3c3c;
const long long INFL = 0x3c3c3c3c3c3c3c3c;

int N,M;
int par[300003];
int numCnt[300003];
int size[300003];
int arr[500003];
int find(int u){
	if(par[u] == u) return u;
	return par[u] = find(par[u]);
}
void merge(int u , int v){
	u = find(u), v = find(v);
	if(u==v) return;
	par[u] = v;
	size[v] += size[u];
}
int main() {
	for(int i = 0 ; i < 300003; i++) par[i] = i, size[i] = 1;
	scanf("%d%d",&N,&M);
	for(int i = 0 ; i < N; i++){
		int a;
		scanf("%d",&a);
		for(int j = 0 ; j < a; j++) scanf("%d", &arr[j]);
		for(int j = 0 ; j < a-1; j++) merge(arr[j], arr[j+1]);
	}
	int tmp;
	for(int i = 0 ; i < N-1; i++) scanf("%d",&tmp);
	int cnt = -1;
	for(int i = 1; i <= M; i++) cnt = max(cnt, size[find(i)]);

	printf("%d\n",cnt);
	for(int i = 1; i <= M; i++){
		printf("%d ",1+(numCnt[find(i)]++));
	}
	return 0;
}
