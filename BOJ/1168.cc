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

int rangeSum[4*MAX_N];
int size;
int n,m;
vi ans;

void init(int nodeLeft, int nodeRight, int node) {
	if(nodeLeft==nodeRight) {rangeSum[node]=1;return;}
	int nodeMid=(nodeLeft+nodeRight)>>1;
	init(nodeLeft,nodeMid,2*node);
	init(nodeMid+1,nodeRight,2*node+1);
	rangeSum[node]=rangeSum[2*node]+rangeSum[2*node+1];
}
int query(int nodeLeft, int nodeRight, int left, int right, int node){
	if(left<=nodeLeft&&nodeRight<=right) return rangeSum[node];
	if(right<nodeLeft||nodeRight<left) return 0;
	int nodeMid=(nodeLeft+nodeRight)>>1;
	int leftRange = query(nodeLeft,nodeMid,left,right,2*node);
	int rightRange = query(nodeMid+1,nodeRight,left,right,2*node+1);
	return leftRange+rightRange;
}
int query(int left, int right){
	return query(0,size-1,left,right,1);
}
void update(int nodeLeft, int nodeRight, int node, int pos, int val) {
	if(nodeLeft==nodeRight&&nodeRight==pos){rangeSum[node]+=val;return;}
	if(pos < nodeLeft || nodeRight < pos) return;
	int nodeMid=(nodeLeft+nodeRight)>>1;
	update(nodeLeft,nodeMid,2*node,pos,val);
	update(nodeMid+1,nodeRight,2*node+1,pos,val);
	rangeSum[node]=rangeSum[2*node]+rangeSum[2*node+1];
}
void update(int pos, int val) {
	update(0,size-1,1,pos,val);
}

int main() {
	FILE *fp = fopen("output.txt","wb");
	inp2(n,m);
	size = n;
	init(0,size-1,1);

	printf("<");

	int start = 0;
	int cnt = 0;
	while(1) {
		int l = start,r = size;
		if(cnt == n-1) break;
		
		int tmp = query(start,size-1) + (start == 0 ? 0 : query(0,start-1));
		int mm = (m-1)%tmp+1;
		int q = query(start,size-1);
		if(q < mm) {
			mm-=q;
			start=l=0;
		}

		while(l < r) {
			int mid = (l+r)>>1;
			int q = query(start,mid);
			if(q >= mm) r=mid;
			else l=mid+1;
		}
		printf("%d, ",l+1);
		++cnt;
		update(l,-1);
		r = size;
		start = l;
		if(query(start,size-1) == 0) {
			start=l=0;
		}
		while(l < r) {
			int mid = (l+r)>>1;
			int q = query(start,mid);
			if(q >= 1) r=mid;
			else l=mid+1;
		}
		start = l;
	}
	printf("%d>",start+1);

	return 0;
}