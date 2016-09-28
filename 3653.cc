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

int a[2*MAX_N];
int pos[MAX_N];
vi rangeSum;
int size;
int n,m;

int init(int nodeLeft, int nodeRight, int node) {
	if(nodeLeft == nodeRight) return rangeSum[node] = a[nodeLeft];

	int nodeMid = (nodeLeft + nodeRight) >> 1;

	int leftRange = init(nodeLeft, nodeMid, 2*node);
	int rightRange = init(nodeMid+1, nodeRight, 2*node+1);

	return rangeSum[node] = leftRange+rightRange;
}

int update(int nodeLeft, int nodeRight, int node, int pos, int val) {
	if(nodeLeft == nodeRight && nodeRight == pos) return rangeSum[node] += val;
	if(pos < nodeLeft || nodeRight < pos) return rangeSum[node];

	int nodeMid = (nodeLeft + nodeRight) >> 1;

	int leftRange = update(nodeLeft, nodeMid, 2*node, pos, val);
	int rightRange = update(nodeMid+1, nodeRight, 2*node+1, pos, val);

	return rangeSum[node] = leftRange+rightRange;
}

int query(int nodeLeft, int nodeRight, int left, int right, int node) {
	if(left <= nodeLeft && nodeRight <= right) return rangeSum[node];
	if(right < nodeLeft || nodeRight < left) return 0;

	int nodeMid = (nodeLeft + nodeRight) >> 1;

	int leftRange = query(nodeLeft, nodeMid, left, right, 2*node);
	int rightRange = query(nodeMid+1, nodeRight, left, right, 2*node+1);

	return leftRange+rightRange;
}

int update(int pos, int val){
	return update(0,size-1,1,pos,val);
}

int query(int left, int right) {
	return query(0,size-1,left,right,1);
}
int main() {
	int t;
	inp1(t);
	while(t--) {
		inp2(n,m);
		int front = m;
		size = n+m;
		rangeSum = vi(4*size,0);
		FOR(i,n) {
			pos[i+1] = m+i;
			a[m+i] = 1;
		}
		init(0,size-1,1);
		memset(a,0,sizeof(a));
		FOR(i,m){
			int tmp;
			inp1(tmp);
			printf("%d ",query(0,pos[tmp]-1));
			update(pos[tmp],-1);
			--front;
			pos[tmp] = front;
			update(pos[tmp],1);
		}
		printf("\n");
	}
	return 0;
}