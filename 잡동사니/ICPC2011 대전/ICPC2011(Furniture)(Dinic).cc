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
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)

using namespace std;

typedef long long ll;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<vector<int> > vvi;
typedef pair<int,int> pii;
typedef pair<int,pair<int,int> > piii;

const int INF = 0x3c3c3c3c;
const long long INFL = 0x3c3c3c3c3c3c3c3c;
const int MAX_V = 614;

int cap[MAX_V][MAX_V];
int flow[MAX_V][MAX_V];
vi adj[MAX_V];
int m,t,n;
int ans[100][500];
int parent[MAX_V];
int level[MAX_V];
int iter[MAX_V];

int dfs(int here){
	if(here==1) return 1;
	for(int& i = iter[here]; i < adj[here].size(); ++i){
		int there=adj[here][i];
		if(cap[here][there]-flow[here][there]>0 && level[here]+1 == level[there]){
			parent[there]=here;
			if(dfs(there)) return 1;
		}
	}
	return 0;
}

int dinic(){
	int ret=0;
	while(1) {
		memset(level,-1,sizeof(level));
		level[0]=0;
		queue<int> q;
		q.push(0);
		while(!q.empty() && level[1] == -1) {
			int here = q.front();
			q.pop();
			for(auto& there : adj[here]){
				if(cap[here][there]-flow[here][there]>0 && level[there] == -1){
					level[there]=level[here]+1;
					q.push(there);
				}
			}
		}
		if(level[1] == -1) break;

		memset(iter,0,sizeof(iter));

		while(1){
			memset(parent,-1,sizeof(parent));
			parent[0]=0;
			if(!dfs(0)) break;
			int minFlow=INF;
			for(int p = 1; p!=parent[p]; p = parent[p]){
				if(512 <= parent[p] && 12 <= p && p < 512) ans[parent[p]-512][p-12] = 0;
				if(512 <= p && 12 <= parent[p] && parent[p] < 512) ans[p-512][parent[p]-12] = 1;
				minFlow = min(minFlow, cap[parent[p]][p]-flow[parent[p]][p]);
			}

			for(int p = 1; p!=parent[p]; p = parent[p]){
				flow[parent[p]][p] += minFlow;
				flow[p][parent[p]] -= minFlow;
			}
			ret+=minFlow;
		}
	}
	return ret;
}

int WORKER(int x){
	return 2+x;
}
int TIME(int x){
	return 2+10+x;
}
int ORDER(int x){
	return 2+10+500+x;
}

void connect(int a, int b, int c){
	cap[a][b]=c;
	adj[a].pb(b);
	adj[b].pb(a);
}

int main() {
	int T;
	inp1(T);
	while(T--){
		int finishTime=0;
		FOR(i,MAX_V) adj[i].clear();
		memset(cap,0,sizeof(cap));
		memset(flow,0,sizeof(flow));
		memset(ans,0,sizeof(ans));
		inp2(m,n);
		FOR(i,m){
			connect(0,WORKER(i),INF);
			FOR(j,500){
				connect(WORKER(i),TIME(j),1);
			}
		}
		FOR(i,n){
			int s,e,w;
			inp3(s,w,e);
			finishTime+=w;
			REP(j,s-1,e-1){
				connect(TIME(j),ORDER(i),1);
			}
			connect(ORDER(i),1,w);
		}

		int maxFlow = dinic();

		if(maxFlow!=finishTime) {
			printf("0\n");
			continue;
		}

		FOR(i,n){
			vector<pii> v;
			int start=-1;
			FOR(j,500){
				if(ans[i][j]==1) {
					if(start==-1) start=j;
				}
				else {
					if(start!=-1) v.pb(mp(start+1,j+1));
					start=-1;
				}
			}
			printf("%d ",v.size());
			FOR(j,v.size()){
				printf("%d %d ",v[j].first,v[j].second);
			}
			printf("\n");
		}
	}
	return 0;
}