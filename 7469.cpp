#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
#define REP(i,a,b) for(int i = a; i < b; ++i)
#define FOR(i,n) REP(i,0,n)
#define pb push_back

using namespace std;

struct SegTree{
	vector<vector<int> > rangeSeq;
	int size;
	SegTree(vector<int> &v) {
		size = v.size();
		rangeSeq.resize(4*size);
		init(0,size-1,1,v);
	}
	vector<int> init(int nodeLeft, int nodeRight, int node, vector<int> &v) {
		vector<int> ret;
		if(nodeLeft == nodeRight) {
			ret.pb(v[nodeLeft]);
			return rangeSeq[node] = ret;
		}

		int nodeMid = (nodeLeft + nodeRight) >> 1;
		
		vector<int> seqLeft = init(nodeLeft, nodeMid, 2*node, v);
		vector<int> seqRight = init(nodeMid+1, nodeRight, 2*node+1, v);
		int posLeft = 0;
		int posRight = 0;
		while(posLeft < seqLeft.size() && posRight < seqRight.size()) {
			if(seqLeft[posLeft] < seqRight[posRight]) {
				ret.pb(seqLeft[posLeft]);
				++posLeft;
			}
			else {
				ret.pb(seqRight[posRight]);
				++posRight;
			}
		}
		if(posLeft == seqLeft.size()) {
			while(posRight < seqRight.size()) {
				ret.pb(seqRight[posRight]);
				++posRight;
			}
		}
		else if(posRight == seqRight.size()) {
			while(posLeft < seqLeft.size()) {
				ret.pb(seqLeft[posLeft]);
				++posLeft;
			}
		}

		return rangeSeq[node] = ret;
	}
	vector<int> query(int nodeLeft, int nodeRight, int left, int right, int node, int pos) {
		vector<int> ret;
		if(left <= nodeLeft && nodeRight <= right) return rangeSeq[node];
		if(nodeRight < left || right < nodeLeft) return ret;

		int nodeMid = (nodeLeft + nodeRight) >> 1;

		vector<int> seqLeft = query(nodeLeft, nodeMid, left, right, 2*node, pos);
		vector<int> seqRight = query(nodeMid+1, nodeRight, left, right, 2*node+1, pos);

		int posLeft = 0;
		int posRight = 0;
		while(posLeft < seqLeft.size() && posRight < seqRight.size()) {
			if(seqLeft[posLeft] < seqRight[posRight]) {
				ret.pb(seqLeft[posLeft]);
				++posLeft;
			}
			else {
				ret.pb(seqRight[posRight]);
				++posRight;
			}
		}
		if(posLeft == seqLeft.size()) {
			while(posRight < seqRight.size()) {
				ret.pb(seqRight[posRight]);
				++posRight;
			}
		}
		else if(posRight == seqRight.size()) {
			while(posLeft < seqLeft.size()) {
				ret.pb(seqLeft[posLeft]);
				++posLeft;
			}
		}

		return ret;
	}
	vector<int> query(int left, int right, int pos) {
		return query(0,size-1,left,right,1,pos);
	}
};

int N, Q;

int main() {
	scanf("%d%d",&N,&Q);
	vector<int> v(N);
	FOR(i,N) {
		scanf("%d",&v[i]);
	}
	SegTree segTree(v);
	FOR(i,Q) {
		int a,b,c;
		scanf("%d%d%d",&a,&b,&c);
		--a;--b;
		vector<int> ans = segTree.query(a,b,c);
		printf("%d\n", ans[c-1]);
	}
	return 0;
}