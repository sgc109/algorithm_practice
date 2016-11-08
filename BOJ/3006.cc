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
#include <cmath>
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
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)

using namespace std;

typedef pair<long long, long long> pll;
typedef vector<int> vi;
typedef vector<vector<int> > vvi;
typedef pair<int,int> pii;
typedef pair<int,pair<int,int> > piii;

const int INF = 0x3c3c3c3c;
const long long INFL = 0x3c3c3c3c3c3c3c3c;
const int MAX_N = 100002;

int n;
vi rangeSum;
int size;
int firstPos[MAX_N];

void update(int nodeLeft, int nodeRight, int node, int pos) {
	if(nodeLeft == nodeRight && nodeRight == pos) {
		rangeSum[node] = 1;
		return;
	}

	if(nodeRight < pos || pos < nodeLeft) return;

	int nodeMid = (nodeLeft + nodeRight) >> 1;

	update(nodeLeft, nodeMid, 2*node, pos);
	update(nodeMid+1, nodeRight, 2*node+1, pos);

	rangeSum[node] = rangeSum[2*node]+rangeSum[2*node+1];
}

int query(int nodeLeft, int nodeRight, int left, int right, int node) {
	if(left <= nodeLeft && nodeRight <= right) return rangeSum[node];
	if(right < nodeLeft || nodeRight < left) return 0;

	int nodeMid = (nodeLeft+nodeRight) >> 1;

	return query(nodeLeft,nodeMid,left,right,2*node) + query(nodeMid+1,nodeRight,left,right,2*node+1);
}

void update(int pos) {
	update(1,size-1,1,pos);
}

int query(int left, int right) {
	return query(1,size-1,left,right,1);
}

int main() {
	inp1(n);
	FOR(i,n) {
		int tmp;
		inp1(tmp);
		firstPos[tmp] = i+1;
	}
	size = n+1;
	rangeSum.resize(4*size);

	int a = 1;
	FOR(i,n) {
		if(a <= n/2) {
			printf("%d\n",firstPos[a] == 1 ? 0 : firstPos[a] - 1 - query(1,firstPos[a]-1));
			update(firstPos[a]);
			// FOR(i,4*size) printf("%d ",rangeSum[i]);
			// printf("\n");
			a = n-a+1;
		}
		else {
			printf("%d\n",firstPos[a] == n ? 0 : n - firstPos[a] - query(firstPos[a]+1,n));
			update(firstPos[a]);
			// FOR(i,4*size) printf("%d ",rangeSum[i]);
			// printf("\n");
			a = n-a+2;
		}
	}
	return 0;
}