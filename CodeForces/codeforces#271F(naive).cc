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
// #include <unordered_set>
#include <set>
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

const int INF = 0x3a3a3a3a;
const long long INFL = 0x3a3a3a3a3a3a3a3a;
const int MAX_N = 1000000;

struct SegTree{
	vvi rangeWinners;
	int size;
	vi vec;
	SegTree(vi &v) {
		size = v.size();
		rangeWinners.resize(4*size);
		vec = v;
		init(0,size-1,1,v);
	}
	vi init(int nodeLeft, int nodeRight, int node, vi &v) {
		if(nodeLeft == nodeRight) {
			vi tmp;
			tmp.push_back(v[nodeLeft]);
			return rangeWinners[node] = tmp;
		}

		int nodeMid = (nodeLeft+nodeRight)>>1;

		vi leftRange = init(nodeLeft, nodeMid, 2*node, v);
		vi rightRange = init(nodeMid+1, nodeRight, 2*node+1, v);

		vi ret;
		if(leftRange.size() == 0 && rightRange.size() == 0) {
			1+1;
		}
		else if(leftRange.size() == 0) {
			int rightTmp = rightRange[0];
			bool able=true;
			REP(i,nodeLeft,nodeRight+1) {
				if(vec[i]%rightTmp!=0) {
					able=false;
					break;
				}
			}
			if(able) {
				FOR(i,rightRange.size()) ret = rightRange;
			}
		}
		else if(rightRange.size() == 0) {
			int leftTmp = leftRange[0];
			bool able=true;
			REP(i,nodeLeft,nodeRight+1) {
				if(vec[i]%leftTmp!=0) {
					able=false;
					break;
				}
			}
			if(able) {
				FOR(i,leftRange.size()) ret = leftRange;
			}
		}
		else {
			int leftTmp = leftRange[0];
			int rightTmp = rightRange[0];
			if(leftTmp % rightTmp==0) {
				FOR(i,rightRange.size()) ret.pb(rightTmp);
			}
			if(rightTmp % leftTmp==0) {
				FOR(i,leftRange.size()) ret.pb(leftTmp);
			}
		}

		return rangeWinners[node] = ret;
	}

	vi query(int nodeLeft, int nodeRight, int left, int right, int node) {
		if(left <= nodeLeft && nodeRight <= right) return rangeWinners[node];
		if(right < nodeLeft || nodeRight < left) {
			vi tmp;
			tmp.pb(-1);
			return tmp;
		}

		int nodeMid = (nodeLeft+nodeRight) >> 1;

		vi leftRange = query(nodeLeft, nodeMid, left, right, 2*node);
		vi rightRange = query(nodeMid+1, nodeRight, left, right, 2*node+1);

		// printf("nodeLeft:%d, nodeRight:%d, leftRangeSize:%d(%d), rightRangeSize:%d(%d)\n",nodeLeft,nodeRight,leftRange.size(),leftRange[0],rightRange.size(),rightRange[0]);
		if(leftRange.size() != 0 && leftRange[0] == -1) {
			// printf("left Out of Range!\n");
			return rightRange;
		}
		if(rightRange.size() != 0 && rightRange[0] == -1) {
			// printf("right Out of Range!\n");
			return leftRange;
		}
		

		vi ret;
		if(leftRange.size() == 0 && rightRange.size() == 0) {
			// printf("nothing!\n");
			1+1;
		}
		else if(leftRange.size() == 0) {
			// printf("left nothing!\n");
			int rightTmp = rightRange[0];
			bool able=true;
			REP(i,(nodeLeft<=left?left:nodeLeft),(nodeRight>=right?right:nodeRight)+1) {
				if(vec[i]%rightTmp!=0) {
					able=false;
					break;
				}
			}
			if(able) {
				FOR(i,rightRange.size()) ret = rightRange;
			}
		}
		else if(rightRange.size() == 0) {
			// printf("right nothing!\n");
			int leftTmp = leftRange[0];
			bool able=true;
			REP(i,(nodeLeft<=left?left:nodeLeft),(nodeRight>=right?right:nodeRight)+1) {
				if(vec[i]%leftTmp!=0) {
					able=false;
					break;
				}
			}
			if(able) {
				FOR(i,leftRange.size()) ret = leftRange;
			}
		}
		else {
			// printf("both exist!\n");
			int leftTmp = leftRange[0];
			int rightTmp = rightRange[0];
			if(leftTmp % rightTmp == 0) {
				FOR(i,rightRange.size()) ret.pb(rightTmp);
			}
			if(rightTmp % leftTmp == 0) {
				FOR(i,leftRange.size()) ret.pb(leftTmp);
			}
		}
		return ret;
	}
	vi query(int left, int right) {
		return query(0,size-1,left,right,1);
	}
};
int main() {
	int n,m;
	inp1(n);
	vi v(n);
	FOR(i,n) inp1(v[i]);
	SegTree segTree(v);
	inp1(m);
	FOR(i,m){
		int l,r;
		inp2(l,r);
		--l;--r;
		printf("%d\n",r-l+1-segTree.query(l,r).size());
	}
	return 0;
}