#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
#define REP(i,a,b) for(int i = a; i < b; ++i)
#define FOR(i,n) REP(i,0,n)
#define mp make_pair
#define pb push_back

using namespace std;

typedef pair<int, int> ii;
const int INF = 0x3a3a3a3a;

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

		vector<int> rangeLeft = init(nodeLeft, nodeMid, 2*node, v);
		vector<int> rangeRight = init(nodeMid+1, nodeRight, 2*node+1, v);
		int posLeft = 0;
		int posRight = 0;
		while(posLeft < rangeLeft.size() && posRight < rangeRight.size()) {
			if(rangeLeft[posLeft] <= rangeRight[posRight]) {
				ret.pb(rangeLeft[posLeft]);
				++posLeft;
			}
			else {
				ret.pb(rangeRight[posRight]);
				++posRight;	
			}
		}
		if(posLeft == rangeLeft.size()) {
			while(posRight < rangeRight.size()) {
				ret.pb(rangeRight[posRight]);
				++posRight;
			}
		}
		else if(posRight == rangeRight.size()) {
			while(posLeft < rangeLeft.size()) {
				ret.pb(rangeLeft[posLeft]);
				++posLeft;
			}
		}

		return rangeSeq[node]  = ret;
	}
	int query(int nodeLeft, int nodeRight, int left, int right, int node, int q) {
		if(right < nodeLeft || nodeRight < left) return 0;
		if(left <= nodeLeft && nodeRight <= right) return lower_bound(rangeSeq[node].begin(), rangeSeq[node].end(), q) - rangeSeq[node].begin();
		int nodeMid = (nodeLeft + nodeRight) >> 1;

		int smallerLeft = query(nodeLeft, nodeMid, left, right, 2*node, q);
		int smallerRight = query(nodeMid+1, nodeRight, left, right, 2*node+1, q);

		return smallerLeft + smallerRight;
	}
	int query(int left, int right, int q) {
		return query(0,size-1,left,right,1,q);
	}
};

int n,m;

int main() {
	scanf("%d%d",&n,&m);
	
	vector<int> raw(n);
	vector<int> sorted(n);
	vector<int> compressed(n);

	FOR(i,n) {
		scanf("%d",&raw[i]);
		sorted[i] = raw[i];
	}
	sort(sorted.begin(),sorted.end());
	
	FOR(i,n) {
		compressed[i] = lower_bound(sorted.begin(),sorted.end(),raw[i]) - sorted.begin();
	}
	SegTree segTree(compressed);
	FOR(i,m) {
		int l,r,k;
		scanf("%d%d%d",&l,&r,&k);
		--l;--r;
		int e = n;
		int s = 0;
		while(e - s > 1) {
			int m = (e + s) >> 1;
			if(segTree.query(l,r,m) <= k-1) {
				s = m;
			}
			else if(segTree.query(l,r,m) > k-1) {
				e = m;
			}
		}
		
		printf("%d\n",sorted[s]);
	}
	return 0;
}