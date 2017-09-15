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
const int MAX_V = 400;

int n,m;
set<int> capReal[MAX_V][MAX_V];
vi adj[MAX_V];
int cap[MAX_V][MAX_V];
int flow[MAX_V][MAX_V];
int parent[MAX_V];

int ford() {
	int ret=0;
	while(1){
		memset(parent,-1,sizeof(parent));
		QU q;
		q.push(1);
		parent[1] = 1;
		while(!q.empty() && parent[n] == -1){
			int here = q.front();
			q.pop();
			for(int there : adj[here]){
				if(cap[here][there]-flow[here][there]>0 && parent[there]==-1){
					parent[there] = here;
					q.push(there);
				}
			}
		}

		if(parent[n]==-1) break;

		int minFlow = INF;
		for(int p = n; p != parent[p]; p = parent[p]){
			minFlow = min(minFlow, cap[parent[p]][p]-flow[parent[p]][p]);
		}
		for(int p = n; p != parent[p]; p = parent[p]){
			flow[parent[p]][p] += minFlow;
			flow[p][parent[p]] -= minFlow;
		}

		ret += minFlow;
	}
	return ret;
}

int main() {
	int T;
	inp1(T);
	while(T--){
		memset(cap,0,sizeof(cap));
		memset(flow,0,sizeof(flow));
		REP(i,1,MAX_V)REP(j,1,MAX_V) capReal[i][j].clear();
		inp2(n,m);
		FOR(i,m){
			int a,b,c;
			inp3(a,b,c);
			cap[a][b]+=c;
			capReal[a][b].insert(c);
			adj[a].pb(b);
			adj[b].pb(a);
		}
		ford();

		int ans=0;
		REP(i,1,n+1){
			REP(j,1,n+1){
				if(flow[i][j]>0 && !(i!=1&&j==n)){
					for(auto it = capReal[i][j].begin(); it != capReal[i][j].end(); ++it){
						if(*it<=flow[i][j]) {
							
							++ans;
							flow[i][j]-=*it;
						}
						else continue;
					}
				}
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}