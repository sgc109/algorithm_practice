#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

struct Edge{
	int u,v,c;
	bool operator<(const Edge& rhs){
		return c<rhs.c;
	}
};
int parent[1003];
int N,M,K;
int a,b,c,d,core;
int find(int u){
	if(parent[u]==u) return u;
	return parent[u]=find(parent[u]);
}
void merge(int a, int b){
	a = find(a), b = find(b);
	if(a==b) return;
	parent[b]=a;
}
vector<Edge> edges;
int main() {
	for(int i = 0 ; i < 1000; i++) parent[i]=i;
	core=1001;
	scanf("%d%d%d",&N,&M,&K);
	for(int i = 0 ; i < K; i++){
		scanf("%d",&a);
		merge(core,a);
	}
	for(int i = 0 ; i < M; i++){
		scanf("%d%d%d",&a,&b,&c);
		edges.push_back(Edge{a,b,c});
	}
	sort(edges.begin(),edges.end());
	int ans=0;
	for(auto e : edges){
		if(find(e.u)==find(e.v)) continue;
		ans+=e.c;
		merge(e.u,e.v);
	}
	printf("%d",ans);
	return 0;
}
