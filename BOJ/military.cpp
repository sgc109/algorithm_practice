#include <stdio.h>
#include <iostream>
#include <vector>
#define REP(i,a,b) for(int i = a; i < b; ++i)
#define FOR(i,n) REP(i,0,n)

using namespace std;

int corp;

struct SegTree {
	vector<int> rangeSum;
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
	int find(int nodeLeft, int nodeRight, int node, int id) {
		if(rangeSum[node] == id) {
			corp = nodeRight;
			return -1;
		}
		if(rangeSum[node] < id) return rangeSum[node];
		if(nodeLeft == nodeRight) {
			corp = nodeLeft;
			return -1;
		}

		int nodeMid = (nodeLeft + nodeRight) / 2;
		int sumLeft = find(nodeLeft, nodeMid, 2*node, id);
		if(sumLeft == -1) return -1;
		id -= sumLeft;
		int sumRight = find(nodeMid+1, nodeRight, 2*node+1, id);

		return -1;
	}
	int update(int nodeLeft, int nodeRight, int node, int pos, int add) {
		if(nodeLeft == nodeRight && nodeRight == pos) {
			rangeSum[node] += add;
			return rangeSum[node];
		}
		if(nodeRight < pos || pos < nodeLeft) return rangeSum[node];

		int nodeMid = (nodeLeft + nodeRight) / 2;
		int sumLeft = update(nodeLeft, nodeMid, 2*node, pos, add);
		int sumRight = update(nodeMid+1, nodeRight, 2*node+1, pos, add);

		return rangeSum[node] = sumLeft + sumRight;
	}
	int find(int id) {
		return find(0,size-1,1,id);
	}
	int update(int pos, int add) {
		return update(0,size-1,1,pos,add);
	}
};

int main() {
	int n, m;
	vector<int> v;
	scanf("%d",&n);
	v.resize(n);
	FOR(i,n) {
		scanf("%d",&v[i]);
	}
	SegTree segTree(v);
	scanf("%d",&m);
	FOR(i,m) {
		/*FOR(j,4*segTree.size) {
			printf("%d ",segTree.rangeSum[j]);
		}
		printf("\n");*/
		int a,b,c;
		scanf("%d",&a);
		if(a==1) {
			scanf("%d%d",&b,&c);
			--b;
			segTree.update(b,c);
		}
		else {
			scanf("%d",&b);
			segTree.find(b);
			printf("%d\n",corp+1);
		}
	}

	return 0;
}	