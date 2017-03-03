#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <queue>
#include <utility>
#include <stack>
#include <cstring>
#include <cstdlib>
#include <string>
#include <set>
#include <cmath>
// #include <unordered_set>
// #include <map>
#define REP(i,a,b) for(int i = a; i < b;++i) 
#define FOR(i,n) REP(i,0,n)
#define mp make_pair
#define pb push_back
#define inp1(a) scanf("%d",&a)
#define inp2(a,b) scanf("%d%d",&a,&b)
#define inp3(a,b,c) scanf("%d%d%d",&a,&b,&c)
#define inp4(a,b,c,d) scanf("%d%d%d%d",&a,&b,&c,&d)
// #define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)

using namespace std;

typedef long long ll;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<vector<int> > vvi;
typedef pair<int,int> pii;
typedef pair<int,pair<int,int> > piii;
typedef queue<int> QU;

const int INF = 0x3c3c3c3c;
const long long INFL = 0x3c3c3c3c3c3c3c3c;
const int MAX_N = 10002;
const int MAX_M = 500002;

vector<pii> adj[MAX_N];
vector<pair<int,pii>> edges;
int n,m,q;
int parent[MAX_N];
int height[MAX_N];
int visited[MAX_N];
int cache[MAX_N][MAX_N];

int find(int x){
	if(parent[x]==x) return x;
	return parent[x] = find(parent[x]);
}
int merge(int a, int b){
	int parentA = find(a); int parentB = find(b);
	if(parentA==parentB) return -1;
	if(height[parentA] < height[parentB]) swap(parentA,parentB);
	parent[parentB] = parentA;
	if(height[parentA] == height[parentB]) ++height[parentA];
	return parentA;
}
int dfs(int here,int minBand, int dest){
	// printf("here:%d\n",here);
	if(here == dest) return minBand;
	visited[here] = 1;
	for(pii& p : adj[here]){
		int there = p.first;
		int cost = p.second;
		if(!visited[there]) {
			// printf("to %d\n",there);
			int tmp = dfs(there,min(minBand,cost),dest);
			if(tmp!=INF) return tmp;
		}
	}
	return INF;
}
void bfs(int start, int end){
	queue<pii> q;
	q.push(mp(start,INF));
	visited[start]=1;
	cache[start][start] = INF;
	while(!q.empty() && cache[start][end]==-1){
		int here = q.front().first;
		int minHere = q.front().second;
		q.pop();
		for(pii& p : adj[here]){
			int there = p.first;
			int minThere = min(minHere,p.second);
			if(!visited[there]){
				cache[start][there] = minThere;
				visited[there]=1;
				q.push(mp(there,minThere));
			}
		}
	}
}
int main() {
	FILE *fp = fopen("output.txt","wb");
	// FILE *fp = stdout;
	int T;
	inp1(T);
	printf("total case:%d\n",T);
	FOR(t,T){
		memset(cache,-1,sizeof(cache));
		printf("test:%d\n",t+1);
		edges.clear();
		FOR(i,MAX_N) adj[i].clear();
		memset(height,0,sizeof(height));
		inp2(n,m);
		FOR(i,n) parent[i]=i;
		FOR(i,m){
			int a,b,c;
			inp3(a,b,c);
			--a;--b;
			edges.pb(mp(-c,mp(a,b)));
		}
		sort(edges.begin(),edges.end());
		FOR(i,m){
			int u = edges[i].second.first;
			int v = edges[i].second.second;
			int cost = -edges[i].first;
			if(merge(u,v)==-1) continue;
			// printf("u:%d, v:%d, cost%d\n",u,v,cost);
			adj[u].pb(mp(v,cost));
			adj[v].pb(mp(u,cost));
		}
		inp1(q);
		ll ans=0;
		FOR(i,q){
			int a,b;
			inp2(a,b);
			--a;--b;
			if(a==b) continue;
			if(cache[a][b] != -1){
				ans+=cache[a][b];
			}
			else if(cache[b][a] != -1){
				ans+= cache[b][a];
			}
			else {
				memset(visited,0,sizeof(visited));
				bfs(a,b);
				ans+=cache[a][b];
			}
		}
		fprintf(fp,"%lld\n",ans);
	}
	return 0;
}