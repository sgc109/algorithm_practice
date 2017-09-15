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
const int MAX_N = 804;

vi adj[MAX_N];
int cap[MAX_N][MAX_N];
int cost[MAX_N][MAX_N];
int parent[MAX_N];
int dist[MAX_N];
int inQueue[MAX_N];
int n,m;
pii mcmf(){
	int minCost=0;
	int maxFlow=0;
	while(true){
		memset(parent,-1,sizeof(parent));
		memset(inQueue,0,sizeof(inQueue));
		memset(dist,0x3c,sizeof(dist));
		parent[0]=0;
		dist[0]=0;
		queue<int> q;
		q.push(0);
		inQueue[0]=1;
		while(!q.empty()){
			int here = q.front();
			q.pop();
			inQueue[here] = 0;
			for(int& there : adj[here]){
				if(cap[here][there]<=0) continue;
				if(dist[there] > dist[here]+cost[here][there]){
					dist[there] = dist[here]+cost[here][there];
					parent[there] = here;
					if(!inQueue[there]) {
						q.push(there);
						inQueue[there] = 1;
					}
				}
			}
		}
		if(parent[1]==-1) break;
		int totalCost=0;
		int minFlow=INF;
		for(int p = 1; p; p=parent[p]){
			minFlow=min(minFlow,cap[parent[p]][p]);
		}
		for(int p = 1; p; p=parent[p]){
			cap[parent[p]][p]-=minFlow;
			cap[p][parent[p]]+=minFlow;
			totalCost+=cost[parent[p]][p];
		}
		minCost+=totalCost*minFlow;
		maxFlow+=minFlow;
	}

	return mp(minCost,maxFlow);
}

int WORKER(int x){return 2+x;}
int JOB(int x){return 2+n+x;}
void connect(int a, int b, int c){
	adj[a].pb(b);
	adj[b].pb(a);
	cap[a][b]=1;
	cost[a][b]=c;
	cost[b][a]=-c;
}
int main() {
	inp2(n,m);
	FOR(i,n){
		int k;
		inp1(k);
		FOR(j,k){
			int a,b;
			inp2(a,b);
			a--;
			connect(WORKER(i),JOB(a),b);
		}
	}
	FOR(i,n) connect(0,WORKER(i),0);
	FOR(i,m) connect(JOB(i),1,0);
	pii ans = mcmf();
	printf("%d\n%d",ans.second,ans.first);
	return 0;
}
