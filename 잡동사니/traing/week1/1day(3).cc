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

typedef long long ll;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<vector<int> > vvi;
typedef pair<int,int> pii;
typedef pair<int,pair<int,int> > piii;
typedef queue<int> QU;

const int INF = 0x3c3c3c3c;
const long long INFL = 0x3c3c3c3c3c3c3c3c;
const int MAX_N = 100001;

struct qur{
	int l,r,k;
} queries[MAX_N];

int rangeAnd[4*MAX_N];
int lazy[4*MAX_N];
int size;
int n,m;

void update(int nodeLeft, int nodeRight, int left, int right, int node, int val){
	if(lazy[node]!=0){
		rangeAnd[node]|=lazy[node];
		if(nodeLeft!=nodeRight) {
			lazy[2*node] |= lazy[node];
			lazy[2*node+1] |= lazy[node];
		}
		lazy[node] = 0;
	}
	if(left <= nodeLeft && nodeRight <= right) {
		rangeAnd[node]|=val;
		if(nodeLeft!=nodeRight) {
			lazy[2*node] |= val;
			lazy[2*node+1] |= val;
		}
		return;
	}
	if(right < nodeLeft || nodeRight < left) return;
	int nodeMid = (nodeLeft+nodeRight) >> 1;
	update(nodeLeft, nodeMid, left, right, 2*node, val);
	update(nodeMid+1, nodeRight, left, right, 2*node+1, val);
	rangeAnd[node] = rangeAnd[2*node]&rangeAnd[2*node+1];
}
void update(int left, int right, int val){
	update(0,size-1,left,right,1,val);
}
int query(int nodeLeft, int nodeRight, int left, int right, int node){
	if(lazy[node]!=0){
		rangeAnd[node]|=lazy[node];
		if(nodeLeft!=nodeRight) {
			lazy[2*node] |= lazy[node];
			lazy[2*node+1] |= lazy[node];
		}
		lazy[node] = 0;
	}
	if(left <= nodeLeft && nodeRight <= right) return rangeAnd[node];
	if(right < nodeLeft || nodeRight < left) return (unsigned int)-1;
	int nodeMid = (nodeLeft + nodeRight) >>1;
	return query(nodeLeft,nodeMid,left,right,2*node)&query(nodeMid+1,nodeRight,left,right,2*node+1);
}
int query(int left, int right){
	return query(0,size-1,left,right,1);
}
int main() {
	bool noAns=false;
	inp2(n,m);
	size = n;
	FOR(i,m){
		int l,r,k;
		inp3(l,r,k);
		--l;--r;
		queries[i].l=l;
		queries[i].r=r;
		queries[i].k=k;
		
		update(l,r,k);
	}
	FOR(i,m){
		int q = query(queries[i].l,queries[i].r);
		if(q!=queries[i].k) {
			printf("NO");
			return 0;
		}
	}
	printf("YES\n");
	FOR(i,n){
		printf("%d ",query(i,i));
	}
	return 0;
}