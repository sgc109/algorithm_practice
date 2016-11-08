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

int rangeIsThere0[4*MAX_N];
int rangeSum[4*MAX_N];
int size;
int arr[MAX_N];

void initSum(int nodeLeft, int nodeRight, int node) {
	if(nodeLeft == nodeRight) {
		rangeSum[node] = arr[nodeLeft] >= 0 ? 0 : 1;
		return;
	}
	int nodeMid=(nodeLeft+nodeRight)>>1;
	initSum(nodeLeft,nodeMid,2*node);
	initSum(nodeMid+1,nodeRight,2*node+1);
	rangeSum[node]=rangeSum[2*node]+rangeSum[2*node+1];
}
int querySum(int nodeLeft, int nodeRight, int left, int right, int node){
	if(left <= nodeLeft && nodeRight <= right) return rangeSum[node];
	if(right < nodeLeft || nodeRight < left) return 0;
	int nodeMid=(nodeLeft+nodeRight)>>1;
	return querySum(nodeLeft,nodeMid,left,right,2*node)+querySum(nodeMid+1,nodeRight,left,right,2*node+1);
}
void updateSum(int nodeLeft, int nodeRight, int node, int pos, int val) {
	if(nodeLeft==nodeRight&&nodeRight==pos) {
		rangeSum[node] = val >= 0 ? 0 : 1;
		return;
	}
	if(pos < nodeLeft || nodeRight < pos) return;
	int nodeMid=(nodeLeft+nodeRight)>>1;
	updateSum(nodeLeft,nodeMid,2*node,pos,val);
	updateSum(nodeMid+1,nodeRight,2*node+1,pos,val);
	rangeSum[node]=rangeSum[2*node]+rangeSum[2*node+1];
}
int querySum(int left, int right) {
	return querySum(0,size-1,left,right,1);
}
void updateSum(int pos, int val){
	updateSum(0,size-1,1,pos,val);
}

void init0(int nodeLeft, int nodeRight, int node) {
	if(nodeLeft == nodeRight) {
		rangeIsThere0[node] = arr[nodeLeft] == 0 ? 1 : 0;
		return;
	}
	int nodeMid=(nodeLeft+nodeRight)>>1;
	init0(nodeLeft,nodeMid,2*node);
	init0(nodeMid+1,nodeRight,2*node+1);
	rangeIsThere0[node]=rangeIsThere0[2*node]|rangeIsThere0[2*node+1];
}
int query0(int nodeLeft, int nodeRight, int left, int right, int node){
	if(left <= nodeLeft && nodeRight <= right) return rangeIsThere0[node];
	if(right < nodeLeft || nodeRight < left) return 0;
	int nodeMid=(nodeLeft+nodeRight)>>1;
	return query0(nodeLeft,nodeMid,left,right,2*node)|query0(nodeMid+1,nodeRight,left,right,2*node+1);
}
void update0(int nodeLeft, int nodeRight, int node, int pos, int val) {
	if(nodeLeft==nodeRight&&nodeRight==pos) {
		rangeIsThere0[node] = val == 0 ? 1 : 0;
		return;
	}
	if(pos < nodeLeft || nodeRight < pos) return;
	int nodeMid=(nodeLeft+nodeRight)>>1;
	update0(nodeLeft,nodeMid,2*node,pos,val);
	update0(nodeMid+1,nodeRight,2*node+1,pos,val);
	rangeIsThere0[node]=rangeIsThere0[2*node]|rangeIsThere0[2*node+1];
}
int query0(int left, int right) {
	return query0(0,size-1,left,right,1);
}
void update0(int pos, int val){
	update0(0,size-1,1,pos,val);
}

int main() {
	int n,k;
	while(inp2(n,k) != -1){
		size=n;
		FOR(i,n) inp1(arr[i]);
		init0(0,size-1,1);
		initSum(0,size-1,1);
		char command;
		int a,b;
		FOR(i,k){
			scanf(" %c%d%d",&command,&a,&b);
			if(command == 'C') {
				--a;
				updateSum(a,b);
				update0(a,b);
			}
			else {
				--a;--b;
				if(query0(a,b)==1) printf("0");
				else {
					if(querySum(a,b)%2==0) printf("+");
					else printf("-");
				}
			}
		}
		printf("\n");
		memset(rangeSum,0,sizeof(rangeSum));
		memset(rangeIsThere0,0,sizeof(rangeIsThere0));
	}
	return 0;
}