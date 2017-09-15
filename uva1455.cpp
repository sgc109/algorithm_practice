#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9+7;
const int INF = 0x3c3c3c3c;
const long long INFL = 0x3c3c3c3c3c3c3c3c;

int T;
int N,M;
int par[100003];
int size[100003];
int t1[1000003]; // 노드수
int t2[1000003]; // states 수
int ymin[100003];
int ymax[100003];

void update(int x, int v, int *t){
	while(x < 100003){
		t[x] += v;
		x += x & -x;
	}
}
int query(int x, int *t){
	int ret = 0;
	while(x > 0){
		ret += t[x];
		x -= x & -x;
	}
	return ret;
}
void addrmv(int u, int addrm){
	update(ymin[u],addrm,t1);
	update(ymax[u],-addrm,t1);
	update(ymin[u],size[u]*addrm,t2);
	update(ymax[u],-size[u]*addrm,t2);
}
int find(int u){
	return u == par[u] ? u : par[u] = find(par[u]);
}
void merge(int u , int v){
	u = find(u), v = find(v);
	if(u==v) return;
	addrmv(u,-1);
	addrmv(v,-1);
	par[u] = v;
	size[v] += size[u];
	ymin[v] = min(ymin[v], ymin[u]);
	ymax[v] = max(ymax[v], ymax[u]);
	addrmv(v,1);
}
int main() {
	scanf("%d",&T);
	while(T--){
		memset(t1,0,sizeof(t1));
		memset(t2,0,sizeof(t2));
		for(int i = 0 ; i < 100003; i++) par[i] = i, size[i] = 1;

		set<int> st;
		scanf("%d",&N);
		for(int i = 0 ; i < N; i++){
			int yy;
			scanf("%*d%d",&yy);
			ymin[i] = ymax[i] = yy + 1;
		}

		scanf("%d",&M);
		for(int i = 0 ; i < M; i++){
			char str[10];
			scanf("%s",str);
			if(str[0] == 'r'){
				int a, b;
				scanf("%d%d",&a,&b);
				merge(a, b);
			}
			else if(str[0] == 'l'){
				double af;
				scanf("%lf",&af);
				int a = (int)(af - 0.5) + 1;
				int a1 = query(a, t1);
				int a2 = query(a, t2);
				printf("%d %d\n",a1, a2);
			}
		}
	}
	return 0;
}
