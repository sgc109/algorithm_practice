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
const int MAX_N = 1000000;

long long a[100002];
int rangeMin[400008];
int n;

int init(int nodeLeft, int nodeRight, int node) {
	if(nodeLeft == nodeRight) return rangeMin[node] = nodeLeft;

	int nodeMid = (nodeLeft + nodeRight) >> 1;

	int leftRange = init(nodeLeft, nodeMid, 2*node);
	int rightRange = init(nodeMid+1, nodeRight, 2*node+1);

	return rangeMin[node] = a[leftRange] <= a[rightRange] ? leftRange : rightRange;
}

int query(int nodeLeft, int nodeRight, int left, int right, int node) {
	if(left <= nodeLeft && nodeRight <= right) return rangeMin[node];
	if(right < nodeLeft || nodeRight < left) return n;

	int nodeMid = (nodeLeft + nodeRight) >> 1;

	int leftRange = query(nodeLeft, nodeMid, left, right, 2*node);
	int rightRange = query(nodeMid+1, nodeRight, left, right, 2*node+1);

	return a[leftRange] <= a[rightRange] ? leftRange : rightRange;
}

int query(int left, int right) {
	return query(0,n-1,left,right,1);
}

long long solve(int left, int right) {
	if(left > right) return -1;

	int mid = query(left,right);
	long long ret = (long long)a[mid] * (right-left+1);
	ret = max(ret, solve(left,mid-1));
	ret = max(ret, solve(mid+1,right));

	return ret;
}
int main() {
	while(1) {
		inp1(n);
		if(n==0) break;
		FOR(i,n) {
			scanf("%lld",a+i);
		}
		a[n] = INFL;
		init(0,n-1,1);
		printf("%lld\n",solve(0,n-1));
		memset(rangeMin,0,sizeof(rangeMin));
	}
	return 0;
}