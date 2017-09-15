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

int n,m;
int needs[MAX_N];
int books[MAX_N];
int maxBook[MAX_N][MAX_N];
int cost[MAX_N<<1][MAX_N<<1];
int cap[MAX_N<<1][MAX_N<<1];
int parent[MAX_N<<1];
int dist[MAX_N<<1];
vi adj[MAX_N<<1];
int inQ[MAX_N<<1];
pii mcmf(){
	int minCost=0;
	int maxFlow=0;
	while(1){
		memset(parent,-1,sizeof(parent));
		memset(dist,0x3c,sizeof(dist));
		memset(inQ,0,sizeof(inQ));
		dist[0]=0;
		parent[0]=0;
		queue<int> q;
		q.push(0);
		inQ[0]=1;
		while(!q.empty()){
			int here = q.front();
			q.pop();
			inQ[here] = 0;
			for(int& there : adj[here]){
				if(cap[here][there] <= 0) continue;
				if(dist[there] > dist[here]+cost[here][there]){
					dist[there] = dist[here]+cost[here][there];
					parent[there]=here;
					if(!inQ[there]){
						q.push(there);
						inQ[there]=1;
					}
				}
			}
		}
		if(parent[1]==-1) break;
		int minFlow=INF;
		int costSum=0;
		for(int p=1;p;p=parent[p]) minFlow=min(minFlow,cap[parent[p]][p]),costSum+=cost[parent[p]][p];
		for(int p=1;p;p=parent[p]) cap[parent[p]][p]-=minFlow, cap[p][parent[p]]+=minFlow;
		minCost+=minFlow*costSum;
		maxFlow+=minFlow;
	}

	return mp(minCost,maxFlow);
}
int MAN(int x){return 2+m+x;}
int STORE(int x){return 2+x;}
void connect(int a, int b, int c, int d){
	adj[a].pb(b);
	adj[b].pb(a);
	cap[a][b]=d;
	cost[a][b]=c;
	cost[b][a]=-c;
}
int main() {
	inp2(n,m);
	FOR(i,n) inp1(needs[i]);
	FOR(i,m) inp1(books[i]);
	FOR(i,m) FOR(j,n) inp1(maxBook[i][j]);
	FOR(i,m) FOR(j,n) inp1(cost[STORE(i)][MAN(j)]);
	FOR(i,m) connect(0,STORE(i),0,books[i]);
	FOR(i,m) FOR(j,n) connect(STORE(i),MAN(j),cost[STORE(i)][MAN(j)],maxBook[i][j]);
	FOR(i,n) connect(MAN(i),1,0,needs[i]);
	pii ans = mcmf();
	printf("%d\n%d",ans.second,ans.first);
	return 0;
}
