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
#include <set>
// #include <unordered_set>
// #include <map>
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
typedef vector<int> vi;
typedef vector<vector<int> > vvi;
typedef pair<int,int> pii;

const int INF = 0x3c3c3c3c;
const long long INFL = 0x3a3a3a3a3a3a3a3a;
const int MAX_N = 1000000;


int n,m;

int gcd(int a, int b) {
	if(a==-1) return b;
	if(b==-1) return a;
	while(a && b) {
		if(a < b) swap(a,b);
		a %= b;
	}
	return a+b;
}

struct SegTree{
	int size;
	vi rangeGcd;

	SegTree(vi &v) {
		size = v.size();
		rangeGcd.resize(4*size);
		init(0,size-1,1,v);
	}

	int init(int nodeLeft, int nodeRight, int node, vi &v) {
		if(nodeLeft == nodeRight) return rangeGcd[node] = v[nodeLeft];

		int nodeMid = (nodeLeft + nodeRight) >> 1;

		int leftRange = init(nodeLeft, nodeMid, 2*node, v);
		int rightRange = init(nodeMid+1, nodeRight, 2*node+1, v);

		return rangeGcd[node] = gcd(leftRange, rightRange);
	}

	int query(int nodeLeft, int nodeRight, int left, int right, int node) {
		if(left <= nodeLeft && nodeRight <= right) return rangeGcd[node];
		if(right < nodeLeft || nodeRight < left) return -1;

		int nodeMid = (nodeLeft + nodeRight) >> 1;

		int leftRange = query(nodeLeft, nodeMid, left, right, 2*node);
		int rightRange = query(nodeMid+1, nodeRight, left, right, 2*node+1);

		return gcd(leftRange, rightRange);
	}

	int query(int left, int right) {
		return query(0,size-1,left,right,1);
	}
};

struct SegTree2{
	int size;
	vector<pii> rangeMinFreq;
	SegTree2(vi &v) {
		size = v.size();
		rangeMinFreq.resize(4*size);
		init(0,size-1,1,v);
	}
	pii init(int nodeLeft, int nodeRight, int node, vi &v) {
		if(nodeLeft == nodeRight) return rangeMinFreq[node] = mp(v[nodeLeft],1);

		int nodeMid = (nodeLeft + nodeRight) >> 1;

		pii leftRange = init(nodeLeft, nodeMid, 2*node, v);
		pii rightRange = init(nodeMid+1, nodeRight, 2*node+1, v);

		pii ret;
		ret.first = (leftRange.first <= rightRange.first) ? leftRange.first : rightRange.first;
		if(leftRange.first == rightRange.first) ret.second = leftRange.second+rightRange.second;
		else ret.second = (leftRange.first < rightRange.first) ? leftRange.second : rightRange.second;

		return rangeMinFreq[node] = ret;
	}

	pii query(int nodeLeft, int nodeRight, int left, int right, int node){
		if(left <= nodeLeft && nodeRight <= right) return rangeMinFreq[node];
		if(right < nodeLeft || nodeRight < left) return mp(INF,1);

		int nodeMid = (nodeLeft + nodeRight) >> 1;

		pii leftRange = query(nodeLeft, nodeMid, left, right, 2*node);
		pii rightRange = query(nodeMid+1, nodeRight, left, right, 2*node+1);

		pii ret;
		ret.first = (leftRange.first <= rightRange.first) ? leftRange.first : rightRange.first;
		if(leftRange.first == rightRange.first) ret.second = leftRange.second+rightRange.second;
		else ret.second = (leftRange.first < rightRange.first) ? leftRange.second : rightRange.second;

		return ret;
	}

	pii query(int left, int right) {
		return query(0,size-1,left,right,1);
	}
};

int main() {
	inp1(n);
	vi v(n);
	FOR(i,n){
		inp1(v[i]);
	}
	SegTree segTree(v);
	SegTree2 segTree2(v);
	inp1(m);
	FOR(i,m){
		int l,r;
		inp2(l,r);
		--l;--r;
		int sub = 0;
		pii minPair = segTree2.query(l,r);
		int rangeGcd = segTree.query(l,r);

		if(rangeGcd == minPair.first) {
			sub = minPair.second;
		}
		printf("%d\n",r-l+1-sub);

	}
	return 0;
}