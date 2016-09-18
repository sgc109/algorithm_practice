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

using namespace std;

typedef pair<long long, long long> pll;
typedef vector<int> vi;
typedef vector<vector<int> > vvi;
typedef pair<int,int> pii;
typedef pair<int,pair<int,int> > piii;

const int INF = 0x3c3c3c3c;
// const long long INFL = 0x3c3c3c3c3c3c3c3c;
const int MAX_N = 1000000;

struct SegTree{
	int size;
	vvi range3nK;
	vi lazy;
	SegTree(int _size) {
		size = _size;
		range3nK.resize(4*size);
		lazy.resize(4*size);
		init(0,size-1,1);
	}
	vi init(int nodeLeft, int nodeRight, int node) {
		if(nodeLeft == nodeRight) {
			vi ret;
			ret.pb(1);
			ret.pb(0);
			ret.pb(0);
			return range3nK[node] = ret;
		}

		int nodeMid = (nodeLeft + nodeRight) >> 1;

		vi l = init(nodeLeft, nodeMid, 2*node);
		vi r = init(nodeMid+1, nodeRight, 2*node+1);

		vi ret(3);
		ret[0] = l[0]+r[0];
		ret[1] = l[1]+r[1];
		ret[2] = l[2]+r[2];

		return range3nK[node] = ret;
	}
	int query(int nodeLeft, int nodeRight, int left, int right, int node) {
		if(lazy[node] != 0) {
			int rest = lazy[node]%3;	
			if(rest==1) {
				int tmp = range3nK[node][2];
				range3nK[node][2] = range3nK[node][1];
				range3nK[node][1] = range3nK[node][0];
				range3nK[node][0] = tmp;
			}
			if(rest==2) {
				int tmp = range3nK[node][2];
				range3nK[node][2] = range3nK[node][0];
				range3nK[node][0] = range3nK[node][1];
				range3nK[node][1] = tmp;
			}

			if(nodeLeft != nodeRight) {
				lazy[2*node]+=lazy[node];
				lazy[2*node+1]+=lazy[node];
			}
			lazy[node] = 0;
		}

		if(left <= nodeLeft && nodeRight <= right) return range3nK[node][0];
		if(right < nodeLeft || nodeRight < left) return 0;

		int nodeMid = (nodeLeft + nodeRight) >> 1;

		int leftRange = query(nodeLeft, nodeMid, left, right, 2*node);
		int rightRange = query(nodeMid+1, nodeRight, left, right, 2*node+1);

		return leftRange+rightRange;
	}

	vi update(int nodeLeft, int nodeRight, int left, int right, int node) {
		if(lazy[node] != 0) {
			int rest = lazy[node]%3;	
			if(rest==1) {
				int tmp = range3nK[node][2];
				range3nK[node][2] = range3nK[node][1];
				range3nK[node][1] = range3nK[node][0];
				range3nK[node][0] = tmp;
			}
			if(rest==2) {
				int tmp = range3nK[node][2];
				range3nK[node][2] = range3nK[node][0];
				range3nK[node][0] = range3nK[node][1];
				range3nK[node][1] = tmp;
			}

			if(nodeLeft != nodeRight) {
				lazy[2*node]+=lazy[node];
				lazy[2*node+1]+=lazy[node];
			}
			lazy[node] = 0;
		}

		if(left <= nodeLeft && nodeRight <= right) {
			int tmp = range3nK[node][2];
			range3nK[node][2] = range3nK[node][1];
			range3nK[node][1] = range3nK[node][0];
			range3nK[node][0] = tmp;
			if(nodeLeft != nodeRight) {
				lazy[2*node] += 1;
				lazy[2*node+1] += 1;
			}
			return range3nK[node];
		}
		if(right < nodeLeft || nodeRight < left) return range3nK[node];

		int nodeMid = (nodeLeft + nodeRight) >> 1;

		vi l=update(nodeLeft,nodeMid,left,right,2*node);
		vi r=update(nodeMid+1,nodeRight,left,right,2*node+1);

		vi ret(3);
		ret[0] = l[0]+r[0];
		ret[1] = l[1]+r[1];
		ret[2] = l[2]+r[2];

		return range3nK[node] = ret;
	}

	int query(int left, int right) {
		return query(0,size-1,left,right,1);
	}
	vi update(int left, int right) {
		return update(0,size-1,left,right,1);
	}
};

int main() {
	int n,m;
	inp2(n,m);
	SegTree segTree(n);
	FOR(i,m){

		int a,b,c;
		inp3(a,b,c);
		if(a==0) {
			segTree.update(b,c);
		}
		else {
			printf("%d\n",segTree.query(b,c));
		}
	}
	return 0;
}