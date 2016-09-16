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
const int MAX_N = 40002;

int order[MAX_N];
int depth[MAX_N];
int cntOrder,dep,dist;
vector<pii> adj[MAX_N];
vi v;
int n,m;
int distFromAnc[MAX_N];

void preorder(int here) {
	// printf("here : %d\n",here);
	order[here] = cntOrder;
	depth[here] = dep;
	distFromAnc[here] = dist;
	v.pb(here);
	++cntOrder;

	for(auto &p : adj[here]) {
		int there = p.first;
		int thereDist = p.second;
		if(order[there] == -1) {
			++dep;
			dist += thereDist;
			preorder(there);
			dist -= thereDist;
			--dep;
			v.pb(here);
			++cntOrder;	
		}
		
	}
}

struct RMQ{
	int size;
	vi rangeMinIdx;
	RMQ(vi &v) {
		size = v.size();
		rangeMinIdx.resize(4*size);
		init(0,size-1,1,v);
	}

	int init(int nodeLeft, int nodeRight, int node, vi &v) {
		if(nodeLeft == nodeRight) return rangeMinIdx[node] = v[nodeLeft];

		int nodeMid = (nodeLeft + nodeRight) >> 1;

		int leftRange = init(nodeLeft, nodeMid, 2*node, v);
		int rightRange = init(nodeMid+1, nodeRight, 2*node+1, v);

		return rangeMinIdx[node] = depth[leftRange] < depth[rightRange] ? leftRange : rightRange;
	}

	int query(int nodeLeft, int nodeRight, int left, int right, int node) {
		if(left <= nodeLeft && nodeRight <= right) return rangeMinIdx[node];
		if(right < nodeLeft || nodeRight < left) return 0;

		int nodeMid = (nodeLeft + nodeRight) >> 1;

		int leftRange = query(nodeLeft, nodeMid, left, right, 2*node);
		int rightRange = query(nodeMid+1, nodeRight, left, right, 2*node+1);

		return depth[leftRange] < depth[rightRange] ? leftRange : rightRange;
	}

	int query(int left, int right) {
		return query(0,size-1,left,right,1);
	}
};
int main() {
	memset(order,-1,sizeof(order));
	inp1(n);
	FOR(i,n-1) {
		int a,b,c;
		inp3(a,b,c);
		adj[a].pb(mp(b,c));
		adj[b].pb(mp(a,c));
	}

	depth[0] = INF;
	preorder(1);
	RMQ rmq(v);
	// REP(i,1,n+1) {
	// 	printf("%d ",order[i]);
	// }

	inp1(m);
	FOR(i,m) {
		int a,b;
		inp2(a,b);
		int l = order[a] < order[b] ? order[a] : order[b];
		int r = order[a] < order[b] ? order[b] : order[a];
		int lca = rmq.query(l,r);
		// printf("%d %d lca:%d\n",l,r,lca);
		int ans = distFromAnc[a]+distFromAnc[b]-2*distFromAnc[lca];
		printf("%d\n",ans);
	}
	return 0;
}