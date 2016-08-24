#include <iostream>
#include <stdio.h>
#include <vector>
#define REP(i,a,b) for(int i = a; i < b; ++i) 
#define FOR(i,n) REP(i,0,n)

using namespace std;

struct SegTree {
	vector<long long> rangeSum;
	int size;
	SegTree(vector<int> &v) {
		size = v.size();
		rangeSum.resize(4*size);
		init(0,size-1,1,v);
	}
	long long init(int nodeLeft, int nodeRight, int node, vector<int> &v) {
		if(nodeLeft == nodeRight) return rangeSum[node] = v[nodeLeft];

		int nodeMid = (nodeLeft + nodeRight) / 2;
		long long sumLeft = init(nodeLeft, nodeMid, 2*node, v);
		long long sumRight = init(nodeMid+1, nodeRight, 2*node+1, v);

		return rangeSum[node] = sumLeft + sumRight;
	}
	long long query(int left, int right, int nodeLeft, int nodeRight, int node) {
		if(nodeRight < left || right < nodeLeft) return 0;
		if(left <= nodeLeft && nodeRight <= right) return rangeSum[node];

		int nodeMid = (nodeLeft + nodeRight) / 2;
		long long sumLeft = query(left, right, nodeLeft, nodeMid, 2*node);
		long long sumRight = query(left, right, nodeMid+1, nodeRight, 2*node+1);

		return sumLeft + sumRight;
	}
	long long update(int nodeLeft, int nodeRight, int node, int pos, int value) {
		if(pos < nodeLeft || nodeRight < pos) return rangeSum[node];
		if(nodeLeft == nodeRight && nodeLeft == pos) return rangeSum[node] = value;

		int nodeMid = (nodeLeft + nodeRight) / 2;
		long long sumLeft = update(nodeLeft, nodeMid, 2*node, pos, value);
		long long sumRight = update(nodeMid+1, nodeRight, 2*node+1, pos, value);

		return rangeSum[node] = sumLeft + sumRight;
	}
	long long query(int left, int right) {
		return query(left, right, 0, size-1, 1);
	}
	long long update(int pos, int value) {
		return update(0, size-1, 1, pos, value);
	}
};

vector<int> v;

int main() {
	int N,Q;
	scanf("%d%d",&N,&Q);
	v.resize(N);
	FOR(i,N) {
		scanf("%d",&v[i]);
	}
	SegTree segTree(v);
	FOR(i,Q) {
		ㅑㅜㅅ  a,b,c,d;
		scanf("%d%d%d%d",&a,&b,&c,&d);
		if(a > b) swap(a,b);
		printf("%lld\n",segTree.query(a-1,b-1));
		segTree.update(c-1,d);
	}	

	return 0;
}