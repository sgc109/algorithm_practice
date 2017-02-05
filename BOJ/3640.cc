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
const int MAX_N = 1002;

int n,m;
vi adj[MAX_N];
int cap[MAX_N][MAX_N];
int cost[MAX_N][MAX_N];
int parent[MAX_N];
int dist[MAX_N];
int inQ[MAX_N];
int mcmf(){
	int minCost=0;
	FOR(i,2){
		memset(dist,0x3c,sizeof(dist));
		memset(parent,-1,sizeof(parent));
		memset(inQ,0,sizeof(inQ));
		queue<int> q;
		q.push(0);
		parent[0]=0;
		dist[0]=0;
		inQ[0]=1;
		while(!q.empty()){
			int here = q.front();
			q.pop();
			inQ[here]=0;
			for(int& there : adj[here]){
				if(cap[here][there]<=0) continue;
				if(dist[there] > dist[here]+cost[here][there]){
					dist[there] = dist[here]+cost[here][there];
					parent[there] = here;
					if(!inQ[there]){
						q.push(there);
						inQ[there]=1;
					}
				}
			}
		}
		int totalCost=0;
		for(int p=n-1;p;p=parent[p]) {
			cap[parent[p]][p]-=1, cap[p][parent[p]]+=1, totalCost+=cost[parent[p]][p];
			printf("%d ",p+1);
		}
		printf("%d\n",totalCost);
		minCost+=totalCost;
	}
	return minCost;
}
void connect(int a,int b, int c){
	adj[a].pb(b);
	adj[b].pb(a);
	cap[a][b]+=1;
	cost[a][b]+=c;
	cost[b][a]-=c;
}
int main() {
	while(inp2(n,m)!=-1){
		memset(cap,0,sizeof(cap));
		memset(cost,0,sizeof(cost));
		FOR(i,n) adj[i].clear();
		FOR(i,m) {
			int a,b,c;
			inp3(a,b,c);
			a--;b--;
			connect(a,b,c);
		}
		int ans = mcmf();
		printf("%d\n",ans);
	}
	return 0;
}
