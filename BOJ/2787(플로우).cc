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
typedef queue<int> QU;

const int INF = 0x3c3c3c3c;
const long long INFL = 0x3c3c3c3c3c3c3c3c;
const int MAX_N = 402;

int n,m;
int cap[MAX_N][MAX_N],flow[MAX_N][MAX_N];
vi visited;
vi adj[MAX_N];
int ans[MAX_N];
vi parent;
int iter[MAX_N];
int level[MAX_N];

bool dfs(int here){
	if(here == 1) return true;
	for(int& i = iter[here]; i < adj[here].size(); ++i){
		int there = adj[here][i];
		if(cap[here][there]-flow[here][there]>0 && level[there] > level[here]){
			parent[there] = here;
			if(dfs(there)) return true;
		}
	}
	return false;
}

int ford(){
	int ret=0;
	while(1){
		
		QU q;
		q.push(0);
		memset(level,-1,sizeof(level));
		while(!q.empty() && level[1] == -1){
			int here = q.front();
			q.pop();
			for(auto& there : adj[here]){
				if(cap[here][there]-flow[here][there]>0 && level[there] == -1){
					level[there] = level[here]+1;
					q.push(there);
				}
			}
		}
		if(level[1] == -1) break;
		memset(iter,0,sizeof(iter));
		while(1){
			parent = vi(MAX_N,-1);
			parent[0] = 0;
			if(!dfs(0)) break;

			int minFlow=INF;
			int from=-1,to=-1;
			for(int p = 1; p != parent[p]; p = parent[p]){
				minFlow = min(minFlow, cap[parent[p]][p]-flow[parent[p]][p]);
				if(2<=parent[p]&&parent[p]<2+n&&2+n<=p){
					ans[p-n-2]=parent[p]-1;
				}

			}
			for(int p = 1; p != parent[p]; p = parent[p]){
				flow[parent[p]][p]+=minFlow;
				flow[p][parent[p]]-=minFlow;
			}
			ret+=minFlow;
		}
	}

	return ret;
}

int A(int x){
	return 2+x;
}
int B(int x){
	return 2+n+x;
}

void connect(int a, int b, int c){
	cap[a][b]=c;
	adj[a].pb(b);
	adj[b].pb(a);
}

int main() {
	
	inp2(n,m);
	FOR(i,n){
		connect(0,A(i),1);
		FOR(j,n){
			connect(A(i),B(j),1);
		}
		connect(B(i),1,1);
	}
	FOR(i,m){
		int o,x,y,v;
		inp4(o,x,y,v);
		--x;--y;--v;
		if(o==1){
			REP(j,v+1,n){
				REP(k,x,y+1){
					cap[A(j)][B(k)]=0;
				}
			}
		}
		else if(o==2){
			FOR(j,v){
				REP(k,x,y+1){
					cap[A(j)][B(k)]=0;
				}
			}
		}
		FOR(j,n){
			if(j < x || y < j) cap[A(v)][B(j)]=0;
		}
	}


	int cnt = ford();

	if(cnt!=n) {
		printf("-1");
		return 0;
	}

	FOR(i,n){
		printf("%d ",ans[i]);
	}



	return 0;
}