#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
#define REP(i,a,b) for(int i = a; i < b; ++i)
#define FOR(i,n) REP(i,0,n)

const int MAX_N = 500000;

using namespace std;

struct SegTree{
	vector<int> rangeSum;
	int size;
	SegTree(vector<int> &v) {
		size = v.size();
		rangeSum.resize(4*size);
		init(0,size-1,1,v);
	}
	init(int nodeLeft, int nodeRight, int node, vector<int> &v) {
		if(nodeLeft == nodeRight) return rangeSum[node] = v[nodeRight];

		int nodeMid = (nodeLeft + nodeRight) / 2;
		int sumLeft = init(nodeLeft, nodeMid, 2*node, v);
		int sumRight = init(nodeMid+1, nodeRight, 2*node+1, v);

		return rangeSum[node] = sumLeft + sumRight;
	}
	update(int nodeLeft, int nodeRight, int node, int pos) {
		if(nodeLeft == nodeRight && nodeRight == pos) return rangeSum[node] = 1;
		if(pos < nodeLeft || nodeRight < pos) return rangeSum[node];

		int nodeMid = (nodeLeft + nodeRight) / 2;
		int sumLeft = update(nodeLeft, nodeMid, 2*node, pos);
		int sumRight = update(nodeMid+1, nodeRight, 2*node+1, pos);

		return rangeSum[node] = sumLeft + sumRight;
	}
	int query(int left, int right, int nodeLeft, int nodeRight, int node) {
		if(right < nodeLeft || nodeRight < left) return 0;
		if(left <= nodeLeft && nodeRight <= right) return rangeSum[node];

		int nodeMid = (nodeLeft + nodeRight) / 2;
		int sumLeft = query(left, right, nodeLeft, nodeMid, 2*node);
		int sumRight = query(left, right, nodeMid+1, nodeRight, 2*node+1);

		return sumLeft + sumRight;
	}
	int update(int pos) {
		return update(0, size-1, 1, pos);
	}
	int query(int left, int right) {
		return query(left, right, 0, size-1, 1);
	}

};

int main() {
	int N;

	scanf("%d",&N);
	vector<int> v(N);
	vector<int> sorted(N);
	vector<int> init(N,0);
	FOR(i,N) {
		scanf("%d",&v[i]);
		--v[i];
		sorted[i] = v[i];
	}

	sort(sorted.begin(), sorted.end());
	SegTree segTree(init);
	FOR(i,N) {
		int zipped = lower_bound(sorted.begin(),sorted.end(),v[i]) - sorted.begin();
		printf("%d\n",segTree.query(zipped+1,N-1)+1);
		segTree.update(zipped);
	}


	return 0;
}