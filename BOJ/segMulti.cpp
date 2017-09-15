#include <stdio.h>
#include <vector>
#define REP(i,a,b) for(int i = a; i < b; ++i)
#define FOR(i,n) REP(i,0,n)

using namespace std;

const int MOD = 1000000007;

int N,M,K;
vector<int> v;

struct SegTree{
	vector<int> rangeMult;
	int size;
	SegTree(vector<int> &v) {
		size = v.size();
		rangeMult.resize(4*size);
		init(0,size-1,1,v);
	}
	int init(int nodeLeft, int nodeRight, int node, vector<int> &v) {
		if(nodeLeft == nodeRight) return rangeMult[node] = v[nodeLeft];

		int nodeMid = (nodeLeft + nodeRight) / 2;

		int leftMult = init(nodeLeft, nodeMid, 2*node, v);
		int rightMult = init(nodeMid+1, nodeRight, 2*node+1, v);

		return rangeMult[node] = ((long long)leftMult * rightMult) % MOD;
	}
	int query(int nodeLeft, int nodeRight, int left, int right, int node) {
		if(right < nodeLeft || nodeRight < left) return 1;
		if(left <= nodeLeft && nodeRight <= right) return rangeMult[node];

		int nodeMid = (nodeLeft + nodeRight) / 2;

		int leftMult = query(nodeLeft, nodeMid, left, right, 2*node);
		int rightMult = query(nodeMid+1, nodeRight, left, right, 2*node+1);


		return ((long long)leftMult * rightMult) % MOD;
	}
	int update(int nodeLeft, int nodeRight, int node, int pos, int value) {
		if(pos < nodeLeft || nodeRight < pos) return rangeMult[node];
		if(nodeLeft == nodeRight && nodeLeft == pos) return rangeMult[node] = value;

		int nodeMid = (nodeLeft + nodeRight) / 2;

		int leftMult = update(nodeLeft, nodeMid, 2*node, pos, value);
		int rightMult = update(nodeMid+1, nodeRight, 2*node+1, pos, value);


		return rangeMult[node] = ((long long)leftMult * rightMult) % MOD;
	}
	int query(int left, int right) {
		return query(0, size-1, left, right, 1);
	}
	int update(int pos, int value) {
		return update(0, size-1, 1, pos, value);
	}
};

int main() {
	scanf("%d%d%d",&N,&M,&K);
	v.resize(N);
	FOR(i,N) {
		scanf("%d",&v[i]);
	}
	SegTree segTree(v);
	FOR(i,M+K) {
		int a,b,c;
		scanf("%d%d%d",&a,&b,&c);
		if(a == 1) {
			segTree.update(b-1,c);
		}
		else {
			printf("%d\n",segTree.query(b-1,c-1));
		}
	}

	return 0;
}