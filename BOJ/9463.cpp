#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
#define REP(i,a,b) for(int i = a; i < b; ++i)
#define FOR(i,n) REP(i,0,n)

using namespace std;

struct SegTree{
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
		if(left <= nodeLeft && nodeRight <= right) return rangeSum[node];
		if(right < nodeLeft || nodeRight < left) return 0;

		int nodeMid = (nodeLeft + nodeRight) / 2;
		long long sumLeft = query(left, right, nodeLeft, nodeMid, 2*node);
		long long sumRight = query(left, right, nodeMid+1, nodeRight, 2*node+1);

		return sumLeft + sumRight;
	}
	long long update(int nodeLeft, int nodeRight, int node, int pos) {
		if(nodeLeft == nodeRight && nodeRight == pos) return rangeSum[node] = 1;
		if(pos < nodeLeft || nodeRight < pos) return rangeSum[node];

		int nodeMid = (nodeLeft + nodeRight) / 2;
		long long sumLeft = update(nodeLeft, nodeMid, 2*node, pos);
		long long sumRight = update(nodeMid+1, nodeRight, 2*node+1, pos);

		return rangeSum[node] = sumLeft + sumRight;
	}
	long long query(int left, int right) {
		return query(left, right, 0, size-1, 1);
	}
	long long update(int pos) {
		return update(0, size-1, 1, pos);
	}
};

int main() {
	int T;
	scanf("%d",&T);
	FOR(t,T) {
		long long cnt = 0;
		int n;
		scanf("%d",&n);
		vector<int> match(n);
		FOR(i,n) {
			int tmp;
			scanf("%d",&tmp);
			--tmp;
			match[tmp] = i;
		}
		vector<int> v(n,0);
		SegTree segTree(v);
		FOR(i,n) {
			int tmp;
			scanf("%d",&tmp);
			--tmp;
			long long cross = segTree.query(match[tmp]+1,n-1);
			cnt += cross;
			segTree.update(match[tmp]);
			/*FOR(j,4*segTree.size) {
				printf("%d ",segTree.rangeSum[j]);
			}
			printf("\n");
			printf("pos : %d, cross : %d\n",match[tmp], cross);*/
		}
		printf("%lld\n",cnt);
	}

	return 0;
}