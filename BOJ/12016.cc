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
int arr[MAX_N];
long long ans[MAX_N];
vector<pair<int,long long> > rangeCntSum;
int size;
vector<pii> sorted;

pair<int, long long> query(int nodeLeft, int nodeRight, int left, int right, int node) {
	if(left <= nodeLeft && nodeRight <= right) return rangeCntSum[node];
	if(right < nodeLeft || nodeRight < left) return mp(0,0);
	int nodeMid=(nodeLeft+nodeRight)>>1;
	pair<int, long long> leftRange = query(nodeLeft,nodeMid,left,right,2*node);
	pair<int, long long> rightRange = query(nodeMid+1,nodeRight,left,right,2*node+1);

	return mp(leftRange.first+rightRange.first,leftRange.second+rightRange.second);
}

void update(int nodeLeft, int nodeRight, int node, int pos, pair<int, long long> val) {
	if(nodeLeft == nodeRight && nodeRight == pos) {
		rangeCntSum[node] = val;
		return;
	}
	if(pos < nodeLeft || nodeRight < pos) return;
	int nodeMid=(nodeLeft+nodeRight)>>1;
	update(nodeLeft,nodeMid,2*node,pos,val);
	update(nodeMid+1,nodeRight,2*node+1,pos,val);
	rangeCntSum[node] = mp(rangeCntSum[2*node].first+rangeCntSum[2*node+1].first,rangeCntSum[2*node].second+rangeCntSum[2*node+1].second);
}

pair<int, long long> query(int left, int right) {
	return query(0,size-1,left,right,1);
}

void update(int pos, pii val){
	update(0,size-1,1,pos,val);
}

int main() {
	inp1(n);
	FOR(i,n) {
		inp1(arr[i]);
		sorted.pb(mp(arr[i],i));
	}
	size = n;
	rangeCntSum.resize(4*n);
	sort(sorted.begin(),sorted.end());
	FOR(i,n) {
		int pos = sorted[i].second;
		int val = sorted[i].first;

		long long tmp = (long long)n*(val-1) + pos + 1;
		pair<int,long long> left = pos == 0 ? mp(0,0ll) : query(0,pos-1);
		tmp -= (long long)left.first*val - left.second;
		pair<int,long long> right = pos == size-1 ? mp(0,0ll) : query(pos+1,size-1);
		tmp -= (long long)right.first*val - right.second - right.first;
		ans[pos] = tmp;
		update(pos,mp(1,(long long)val));
		// printf("left:%d %lld, right:%d %lld\n",left.first,left.second,right.first,right.second);
	}
	FOR(i,n) {
		printf("%lld\n",ans[i]);
	}

	return 0;
}