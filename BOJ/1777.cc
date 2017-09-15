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
#include <map>
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
const int MAX_N = 100002;

struct SegTree{
	vector<int> rangeSum;
	int size;
	SegTree(int n) {
		size = n;
		rangeSum = vector<int>(4*size,0);
	}

	int query(int nodeLeft, int nodeRight, int left, int right, int node) {
		if(left <= nodeLeft && nodeRight <= right) return rangeSum[node];
		if(right < nodeLeft || nodeRight < left) return 0;

		int nodeMid = (nodeLeft + nodeRight) >> 1;

		int rangeLeft = query(nodeLeft, nodeMid, left, right, 2*node);
		int rangeRight = query(nodeMid+1, nodeRight, left, right, 2*node+1);

		return rangeLeft + rangeRight;
	}

	int update(int nodeLeft, int nodeRight, int node, int pos, int val) {
		if(nodeLeft == nodeRight && nodeRight == pos) return rangeSum[node] += val;
		if(nodeRight < pos || pos < nodeLeft) return rangeSum[node];

		int nodeMid = (nodeLeft + nodeRight) >> 1;

		int rangeLeft = update(nodeLeft, nodeMid, 2*node, pos, val);
		int rangeRight = update(nodeMid+1, nodeRight, 2*node+1, pos, val);

		return rangeSum[node] = rangeLeft+rangeRight;
	}
	int query(int left, int right) {
		return query(0,size-1,left,right,1);
	}
	int update(int pos, int val) {
		return update(0,size-1,1,pos,val);
	}
};

int sequence[MAX_N];
int ans[MAX_N];

int main() {
	int n;
	inp1(n);
	FOR(i,n) inp1(sequence[i]);
	SegTree segTree(n);
	for(int i = n; i >=1; --i) {
		int l=0,r=n;
		while(l < r) {
			int mid = (l+r)>>1;
			if(sequence[i-1] > mid-segTree.query(0,mid)) l=mid+1;
			else r=mid;
		}
		ans[r] = i;
		segTree.update(r,1);
	}

	for(int i=n-1;i>=0;--i) printf("%d ",ans[i]);
	return 0;
}