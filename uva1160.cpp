#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9+7;
const int INF = 0x3c3c3c3c;
const long long INFL = 0x3c3c3c3c3c3c3c3c;

int par[100003];
int size[100003];
int cntE[100003];
int find(int u){
	return par[u] == u ? u : par[u] = find(par[u]);
}
int merge(int u, int v){
	u = find(u), v = find(v);
	if(u == v) {
		if(cntE[u]+1 == size[u]) return 0;
		cntE[u]++;
		return 1;
	}

	if(size[v] + size[u] <= cntE[v] + cntE[u] + 1) return 0;
	par[u] = v;
	size[v] += size[u];
	cntE[v] += cntE[u]+1;

	return 1;
}
int main() {
	while(1){
		for(int i = 0 ; i < 100003; i++) par[i] = i, size[i] = 1, cntE[i] = 0;
		int a, b;
		int cnt = 0;
		bool exit = false;
		while(1){
			if(scanf("%d",&a)==-1) {
				exit = true;
				break;
			}
			if(a==-1) break;
			scanf("%d\n",&b);
			if(!merge(a, b)) cnt++;
		}
		if(exit) break;
		printf("%d\n",cnt);
		char blank;
		scanf("%c",&blank);
	}
	return 0;
}
