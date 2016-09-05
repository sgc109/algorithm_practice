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
const int MAX_N = 100000;

const long long Hash[2] = {1000000007,1000000009};

struct SegTree {
	vector<pll> rangeHash;
	vector<int> lazy;
	int size;
	long long f[220];
	long long g[MAX_N][2];
	long long l[MAX_N][2];
	SegTree(string &s) {
		size = s.size();
		rangeHash.resize(4*size);
		lazy = vector<int>(4*size,0);
		FOR(i,10) f['0'+i] = i+1;
		g[0][0] = g[0][1] = 1;
		l[0][0] = l[0][1] = 1;
		REP(i,1,size) {
			FOR(k,2) {
				g[i][k] = (g[i-1][k] * 257) % Hash[k];
				l[i][k] = (g[i][k] + l[i-1][k]) % Hash[k];
			}
		}
		
		init(0,size-1,1,s);
	} 
	pll init(int nodeLeft, int nodeRight, int node, string &s) {
		if(nodeLeft == nodeRight) {
			return rangeHash[node] = mp(f[s[nodeLeft]], f[s[nodeLeft]]);
		}

		int nodeMid = (nodeLeft + nodeRight) >> 1;

		pll leftRange = init(nodeLeft, nodeMid, 2*node, s);
		pll rightRange = init(nodeMid+1, nodeRight, 2*node+1, s);

		int gI  = nodeRight-nodeMid;
		return rangeHash[node] = mp((leftRange.first*g[gI][0]+rightRange.first)%Hash[0],(leftRange.second*g[gI][1]+rightRange.second)%Hash[1]);
	}

	pll query(int nodeLeft, int nodeRight, int left, int right, int node) {
		if(lazy[node] != 0) {
			rangeHash[node] = mp(l[nodeRight-nodeLeft][0]*lazy[node]%Hash[0],l[nodeRight-nodeLeft][1]*lazy[node]%Hash[1]);
			if(nodeLeft != nodeRight) {
				lazy[2*node] = lazy[node];
				lazy[2*node+1] = lazy[node];
			}
			lazy[node] = 0;
		}
		if(nodeRight < left || right < nodeLeft) return mp(0,0);
		if(left <= nodeLeft && nodeRight <= right) return rangeHash[node];

		int nodeMid = (nodeLeft + nodeRight) >> 1;
		pll leftRange = query(nodeLeft, nodeMid, left, right, 2*node);
		pll rightRange = query(nodeMid+1, nodeRight, left, right, 2*node+1);

		int gI  = (nodeRight<=right?nodeRight:right)-nodeMid;
		gI = gI < 0 ? 0 : gI;
		return mp((leftRange.first*g[gI][0]+rightRange.first)%Hash[0],(leftRange.second*g[gI][1]+rightRange.second)%Hash[1]);
	}

	pll update(int nodeLeft, int nodeRight, int left, int right, int node, char val) {
		if(lazy[node] != 0) {
			rangeHash[node] = mp(l[nodeRight-nodeLeft][0]*lazy[node]%Hash[0],l[nodeRight-nodeLeft][1]*lazy[node]%Hash[1]);
			if(nodeLeft != nodeRight) {
				lazy[2*node] = lazy[node];
				lazy[2*node+1] = lazy[node];
			}
			lazy[node] = 0;
		}
		if(right < nodeLeft || nodeRight < left) return rangeHash[node];
		if(left <= nodeLeft && nodeRight <= right) {
			if(nodeLeft != nodeRight) {
				lazy[2*node] = f[val];
				lazy[2*node+1] = f[val];
			}
			return rangeHash[node] = mp(l[nodeRight-nodeLeft][0]*f[val]%Hash[0],l[nodeRight-nodeLeft][1]*f[val]%Hash[1]);
		}

		int nodeMid = (nodeLeft + nodeRight) >> 1;
		pll leftRange = update(nodeLeft, nodeMid, left, right, 2*node, val);
		pll rightRange = update(nodeMid+1, nodeRight, left, right, 2*node+1, val);

		int gI  = nodeRight-nodeMid;
		return rangeHash[node] = mp((leftRange.first*g[gI][0]+rightRange.first)%Hash[0],(leftRange.second*g[gI][1]+rightRange.second)%Hash[1]);	
	}
	pll query(int left, int right) {
		return query(0,size-1,left,right,1);
	}
	pll update(int left, int right, char val) {
		return update(0,size-1,left,right,1,val);
	}
};

int main() {
	setbuf(stdout,NULL);
	int n,m,k;
	inp3(n,m,k);
	string s;
	cin >> s;
	SegTree segTree(s);
	FOR(t,m+k) {
		int x,l,r,d;
		inp4(x,l,r,d);
		--l;--r;
		if(x==1) {
			segTree.update(l,r,'0'+d);
		}
		else if(x==2) {
			pll p1 = segTree.query(l,r-d);
			pll p2 = segTree.query(l+d,r);
			if(p1.first*Hash[1]+p1.second == p2.first*Hash[1]+p2.second) printf("YES\n");
			else printf("NO\n");
		}
	}
	return 0;
}