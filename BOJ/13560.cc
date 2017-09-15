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
#define all(v) (v).begin(),(v).end()
#define inp1(a) scanf("%d",&a)
#define inp2(a,b) scanf("%d%d",&a,&b)
#define inp3(a,b,c) scanf("%d%d%d",&a,&b,&c)
#define inp4(a,b,c,d) scanf("%d%d%d%d",&a,&b,&c,&d)

using namespace std;

typedef long long ll;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<vector<int> > vvi;
typedef pair<int,int> pii;
typedef pair<int,pair<int,int> > piii;
typedef queue<int> QU;

const int MOD = 1000000007;
const int INF = 0x3c3c3c3c;
const long long INFL = 0x3c3c3c3c3c3c3c3c;
const int MAX_N = 102;

int cap[10002][10002];
vi adj[10002];
int score[10002];
int level[10002];
int iter[10002];
int parent[10002];
int n;
int A(int x){return x+2;}
int B(int x){return x+n+2;}
bool dfs(int here){
	// printf("here:%d\n",here);
	if(here==1) return true;
	for(int& i = iter[here]; i < adj[here].size(); i++){
		int there = adj[here][i];
		if(level[there]<=level[here] || cap[here][there]<=0) continue;
		parent[there] = here;
		if(dfs(there)) return true;
	}
	return false;
}
int dinic(){
	int ret=0;
	while(1){
		memset(level,-1,sizeof(level));
		memset(iter,0,sizeof(iter));
		queue<int> q;
		q.push(0);
		level[0] = 0;
		while(!q.empty() && level[1] == -1){
			int here = q.front();
			// printf("here:%d\n",here);
			q.pop();
			for(int& there : adj[here]){
				// printf("there:%d\n",there);
				if(level[there]!=-1 || cap[here][there] <= 0) continue;
				level[there] = level[here]+1;
				q.push(there);
			}
		}
		if(level[1]==-1) break;
		while(1){
			memset(parent,-1,sizeof(parent));
			parent[0]=0;
			if(!dfs(0)) break;
			int minFlow=INF;
			for(int p = 1; parent[p] != p; p=parent[p]){
				minFlow=min(minFlow,cap[parent[p]][p]);
			}
			for(int p = 1; parent[p]!=p; p=parent[p]){
				cap[parent[p]][p]-=minFlow;
				cap[p][parent[p]]+=minFlow;
			}
			ret+=minFlow;
		}
	}
	return ret;
}
int main() {
	inp1(n);
	FOR(i,n) {
		inp1(score[i]);
		FOR(j,n){
			if(i==j) continue;
			adj[A(i)].pb(B(j));
			cap[A(i)][B(j)] = 1;
		}
		adj[0].pb(A(i));
		cap[0][A(i)] = score[i];
		adj[B(i)].pb(1);
		cap[B(i)][1] = n-1-score[i];
	}
	int maxFlow = dinic();
	if(maxFlow < n*(n-1)/2) printf("-1");
	else printf("1");

	return 0;
}
