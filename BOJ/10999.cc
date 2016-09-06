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

const int INF = 0x3a3a3a3a;
const long long INFL = 0x3a3a3a3a3a3a3a3a;
const int MAX_N = 1000000;

int n,m,k;

struct SegTree{
	vector<long long> rangeSum;
	vector<long long> lazy;
	int size;
	SegTree(vector<int>& v) {
		size = v.size();
		rangeSum.resize(4*size);
		lazy = vector<long long>(4*size,0);
		init(0,size-1,1,v);
	}

	long long init(int nodeLeft, int nodeRight, int node, vector<int>& v) {
		if(nodeLeft == nodeRight) return rangeSum[node] = v[nodeLeft];

		int nodeMid = (nodeLeft + nodeRight) >> 1;

		long long leftRange = init(nodeLeft, nodeMid, 2*node, v);
		long long rightRange = init(nodeMid+1, nodeRight, 2*node+1, v);

		return rangeSum[node] = leftRange + rightRange;
	}

	long long query(int nodeLeft, int nodeRight, int left, int right, int node) {
		if(lazy[node] != 0) {
			rangeSum[node] += lazy[node]*(nodeRight-nodeLeft+1);
			if(nodeLeft != nodeRight) {
				lazy[2*node] += lazy[node];
				lazy[2*node+1] += lazy[node];
			}
			lazy[node] = 0;
		}

		if(right < nodeLeft || nodeRight < left) return 0;
		if(left <= nodeLeft && nodeRight <= right) return rangeSum[node];

		int nodeMid = (nodeLeft + nodeRight) >> 1;

		long long leftRange = query(nodeLeft, nodeMid, left, right, 2*node);
		long long rightRange = query(nodeMid+1, nodeRight, left, right, 2*node+1);

		return leftRange + rightRange;
	}

	long long update(int nodeLeft, int nodeRight, int left, int right, int node, int val) {
		if(lazy[node] != 0) {
			rangeSum[node] += lazy[node]*(nodeRight-nodeLeft+1);
			if(nodeLeft != nodeRight) {
				lazy[2*node] += lazy[node];
				lazy[2*node+1] += lazy[node];
			}
			lazy[node] = 0;
		}

		if(right < nodeLeft || nodeRight < left) return rangeSum[node];
		if(left <= nodeLeft && nodeRight <= right) {
			if(nodeLeft != nodeRight) {
				lazy[2*node] += val;
				lazy[2*node+1] += val;
			}
			return rangeSum[node] += (long long)val*(nodeRight-nodeLeft+1);
		}

		int nodeMid = (nodeLeft + nodeRight) >> 1;

		long long leftRange = update(nodeLeft, nodeMid, left, right, 2*node, val);
		long long rightRange = update(nodeMid+1, nodeRight, left, right, 2*node+1, val);

		return rangeSum[node] = leftRange + rightRange;
	}
	long long query(int left, int right) {
		return query(0,size-1,left,right,1);
	}
	long long update(int left, int right, int val) {
		return update(0,size-1,left,right,1,val);
	}
};

int main() {
	inp3(n,m,k);

	vector<int> v(n);
	FOR(i,n) {
		scanf("%d",&v[i]);
	}
	SegTree segTree(v);
	FOR(i,m+k) {
		int a,b,c,d;
		inp3(a,b,c);
		--b;--c;
		if(a==1) {
			inp1(d);
			segTree.update(b,c,d);
		}
		else if(a==2) {
			printf("%lld\n",segTree.query(b,c));
		}
	}
	return 0;
}