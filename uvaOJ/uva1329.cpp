#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9+7;
const int INF = 0x3c3c3c3c;
const long long INFL = 0x3c3c3c3c3c3c3c3c;

int parent[20003];
int dist[20003];
int T,N;

pair<int, int> find(int p, int acc){
	if(p==parent[p]) return {p, acc};
	auto ret = find(parent[p], acc + dist[p]);
	parent[p] = ret.first;
	dist[p] = ret.second - acc;
	return ret;
}
int merge(int a, int b){
	parent[a] = b;
	dist[a] = abs(a-b) % 1000;
	return b;
}
int main() {
	scanf("%d", &T);
	while(T--){
		scanf("%d", &N);
		for(int i = 1; i <= N; i++) parent[i] = i, dist[i] = 0;
		while(1){
			char op;
			scanf("%c ", &op);
			if(op == 'O') break;

			if(op == 'E'){
				int I;
				scanf("%d", &I);
				find(I,0);
				printf("%d\n", dist[I]);
			}
			else if(op == 'I'){
				int I,J;
				scanf("%d%d", &I, &J);
				merge(I, J);
			}
		}
	}
	return 0;
}
