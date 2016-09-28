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
int n;
int arr[MAX_N];
int ans[MAX_N];

int query(int nodeLeft, int nodeRight, int left, int right, int node){
	if(left<=nodeLeft&&nodeRight<=right) return rangeSum[node];
	if(right<nodeLeft||nodeRight<left) return 0;
	int nodeMid=(nodeLeft+nodeRight)>>1;
	int leftRange=query(nodeLeft,nodeMid,left,right,2*node);
	int rightRange=query(nodeMid+1,nodeRight,left,right,2*node+1);
	return leftRange+rightRange;
}
int query(int left, int right){
	return query(0,size-1,left,right,1);
}
void update(int nodeLeft, int nodeRight, int node, int pos, int val) {
	if(nodeLeft==nodeRight&&nodeRight==pos) {rangeSum[node]+=val;return;}
	if(pos < nodeLeft || nodeRight < pos) return;
	int nodeMid=(nodeLeft+nodeRight)>>1;
	update(nodeLeft,nodeMid,2*node,pos,val);
	update(nodeMid+1,nodeRight,2*node+1,pos,val);
	rangeSum[node]=rangeSum[2*node]+rangeSum[2*node+1];
}

void update(int pos, int val){
	update(0,size-1,1,pos,val);
}

int main() {
	inp1(n);
	size = n;
	FOR(i,n) inp1(arr[i]);
	FOR(i,n){
		int l=0,r=size;
		while(l<r){
			int m=(l+r)>>1;
			if(m+1-query(0,m)>=arr[i]+1) r=m;
			else l=m+1;
		}
		ans[l]=i+1;
		update(l,1);
	}
	FOR(i,n){
		printf("%d\n",ans[i]);
	}
	return 0;
}