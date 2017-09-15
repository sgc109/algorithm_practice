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
#include <unordered_set>
#include <set>
// #include <map>
#define REP(i,a,b) for(int i = a; i < b;++i) 
#define FOR(i,n) REP(i,0,n)
#define mp make_pair
#define pb push_back
#define inp1(a) scanf("%d",&a)
#define inp2(a,b) scanf("%d%d",&a,&b)
#define inp3(a,b,c) scanf("%d%d%d",&a,&b,&c)
#define inp4(a,b,c,d) scanf("%d%d%d%d",&a,&b,&c,&d)

using namespace std;

typedef pair<long long, long long> pll;
typedef vector<int> vi;
typedef vector<vector<int> > vvi;
typedef pair<int,int> pii;

const int INF = 0x3a3a3a3a;
const long long INFL = 0x3a3a3a3a3a3a3a3a;
const int MAX_N = 50;
const int MAX_V = 2602;

int cap[MAX_V][MAX_V],flow[MAX_V][MAX_V];
vi adj[MAX_V];
int parent[MAX_V];
int n;

int edmonds() {
	int ret=0;
	while(true) {
		memset(parent,-1,sizeof(parent));
		parent[0] = 0;
		queue<int> q;
		q.push(0);
		while(!q.empty() && parent[1] == -1) {
			int here = q.front();
			q.pop();
			for(auto &there : adj[here]) {
				if(cap[here][there]-flow[here][there]>0 && parent[there] == -1) {
					parent[there] = here;
					q.push(there);
				}
			}
		}
		if(parent[1] == -1) break;

		int minFlow=INF;
		for(int p=1; p != parent[p]; p = parent[p]) {
			// printf("%d ",p);
			minFlow = min(minFlow, cap[parent[p]][p]-flow[parent[p]][p]);
		}
		// printf("\n");
		for(int p=1; p != parent[p]; p = parent[p]) {
			flow[parent[p]][p] += minFlow;
			flow[p][parent[p]] -= minFlow;
		}

		ret += minFlow;

	}

	return ret;
}

int A(int x) {return 2+x;};
int B(int x) {return 2+n*n+x;};

int main() {
	inp1(n);
	FOR(i,n) {
		FOR(j,n) {
			adj[A(i*n+j)].pb(B(i));
			adj[B(i)].pb(A(i*n+j));
			
			adj[A(i*n+j)].pb(B(n+j));
			adj[B(n+j)].pb(A(i*n+j));
			
			adj[0].pb(A(i*n+j));
			adj[A(i*n+j)].pb(0);
		}
	}

	int gijunFlow = 0;
	FOR(i,2*n) {
		int sum;
		inp1(sum);
		gijunFlow += sum;
		cap[B(i)][1] = sum;
		adj[B(i)].pb(1);
		adj[1].pb(B(i));
	}

	int l=0,r=10001;
	while(l<r) {
		memset(flow,0,sizeof(flow));
		int mid = (l+r)>>1;
		FOR(i,n) {
			FOR(j,n) {
				cap[A(i*n+j)][B(i)] = mid;
				cap[A(i*n+j)][B(n+j)] = mid;
				cap[0][A(i*n+j)] = 2*mid;
			}
		}		
		int maxFlow = edmonds();
		if(gijunFlow > maxFlow) l = mid+1;
		else r=mid;
	}
	printf("%d\n",l);
	FOR(i,n) {
		FOR(j,n) {
			printf("%d ",flow[A(i*n+j)][adj[A(i*n+j)][1]]);
		}
		printf("\n");
	}
	return 0;
}