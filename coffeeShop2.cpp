#include <iostream>
#include <stdio.h>
#include <vector>

using namespace std;

struct SegTree {
	int rangeSum;
	int size;
	SegTree(vector<int> &v) {
		size = v.size();
		rangeSum.resize(4*size);
		init(0,size-1,1,v);
	}
	int init(int nodeLeft, int nodeRight, int node, vector<int> &v) {
		if(nodeLeft == nodeRight) return rangeSum[node] = v[nodeLeft];

		int nodeMid = (nodeLeft + nodeRight) / 2;
		int sumLeft = init(nodeLeft, nodeMid, 2*node, v);
		int sumRight = init(nodeMid+1, nodeRight, 2*node+1, v);

		return rangeSum[node] = sumLeft + sumRight;
	}
	

};

int main() {
	

	return 0;
}