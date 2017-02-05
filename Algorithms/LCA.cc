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
const int MAX_V = 100002;

vi adj[MAX_V];
int order[MAX_V];
int depth[MAX_V];
vi v;
int n,m;

struct RMQ {
	vi rangeMinIdx;
	int size;
	RMQ(vi &v) {
		size = v.size();
		rangeMinIdx.resize(4*size);
		init(0,size-1,1,v);
	}

	int init(int nodeLeft, int nodeRight, int node, vi &v) {
		if(nodeLeft == nodeRight) return rangeMinIdx[node] = v[nodeLeft];

		int nodeMid = (nodeLeft + nodeRight) >> 1;

		int minIdxLeft = init(nodeLeft, nodeMid, 2*node, v);
		int minIdxRight = init(nodeMid+1, nodeRight, 2*node+1, v);

		return rangeMinIdx[node] = (depth[minIdxLeft] > depth[minIdxRight]) ? minIdxRight : minIdxLeft;
	}

	int query(int nodeLeft, int nodeRight, int left, int right, int node) {
		if(left <= nodeLeft && nodeRight <= right) return rangeMinIdx[node];
		if(right < nodeLeft || nodeRight < left) return 0;

		int nodeMid = (nodeLeft + nodeRight) >> 1;

		int minIdxLeft = query(nodeLeft, nodeMid, left, right, 2*node);
		int minIdxRight = query(nodeMid+1, nodeRight, left, right, 2*node+1);

		return (depth[minIdxLeft] > depth[minIdxRight]) ? minIdxRight : minIdxLeft;
	}

	int query(int left, int right) {
		return query(0,size-1,left,right,1);
	}
};

int orderCnt, dep;
void preorder(int here) {
	order[here] = orderCnt++;
	depth[here] = dep++;
	v.pb(here);
	for(auto &there : adj[here]) {
		if(order[there] == -1) {
			preorder(there);
			v.pb(here);
			++orderCnt;
		}
	}

	--dep;
}

int main() {
	memset(depth,-1,sizeof(depth));
	memset(order,-1,sizeof(order));	
	depth[0] = INF;
	inp1(n);
	FOR(i,n-1) {
		int a,b;
		inp2(a,b);
		adj[a].pb(b);
		adj[b].pb(a);
	}
	inp1(m);

	preorder(1);

	RMQ rmq(v);

	FOR(i,m) {
		int a,b;
		inp2(a,b);
		int l = order[a] > order[b] ? order[b] : order[a];
		int r = order[a] > order[b] ? order[a] : order[b];
		printf("%d\n",rmq.query(l,r));
	}
	
	return 0;
}