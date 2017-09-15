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

using namespace std;

typedef pair<long long, long long> pll;
typedef vector<int> vi;
typedef vector<vector<int> > vvi;
typedef pair<int,int> pii;
typedef pair<int,pair<int,int> > piii;

const int INF = 0x3c3c3c3c;
const long long INFL = 0x3c3c3c3c3c3c3c3c;
const int MAX_N = 1000000;

vi rangeMin;
int size;
vi v;

int init(int nodeLeft, int nodeRight, int node){
	if(nodeLeft == nodeRight) return rangeMin[node] = nodeLeft;

	int nodeMid = (nodeLeft + nodeRight) >> 1;

	int leftRange = init(nodeLeft, nodeMid, 2*node);
	int rightRange = init(nodeMid+1, nodeRight, 2*node+1);

	return rangeMin[node] = (v[leftRange] >= v[rightRange] ? rightRange : leftRange);
}

int query(int nodeLeft, int nodeRight, int left, int right, int node) {
	if(left <= nodeLeft && nodeRight <= right) return rangeMin[node];
	if(right < nodeLeft || nodeRight < left) return size;

	int nodeMid = (nodeLeft + nodeRight) >> 1;

	int leftRange = query(nodeLeft, nodeMid, left, right, 2*node);
	int rightRange = query(nodeMid+1, nodeRight, left, right, 2*node+1);

	return (v[leftRange] >= v[rightRange] ? rightRange : leftRange);
}

int query(int left, int right) {
	return query(0, size-1, left, right, 1);
}

long long ans;
stack<int> s;

pii widthHeight(int isBlack, int left, int right) {
	if(left > right) return mp(0,0);
	if(left+1 == right) {
		if(isBlack) {
			ans += 1;
		}
		else {
			ans-=1;
		}
		return mp(1,1);
	}

	int mid = query(left,right-1);
	bool divided = (v[mid] == v[right]);
	pii leftRange, rightRange;
	if(divided) {
		leftRange = widthHeight(isBlack, left, mid);
		rightRange = widthHeight(isBlack, mid+1, right);
	}
	else {
		leftRange = widthHeight(!isBlack, left+1, right-1);
		rightRange = mp(0,0);
	}

	pii ret;

	// ret.first = (divided?leftRange.first+rightRange.first+1:leftRange.first + rightRange.first + 2);
	ret.first = right-left;
	ret.second = max(leftRange.second, rightRange.second) + (divided?0:1);
	if(!divided) {
		long long added = ((long long)ret.first * ret.second);
		if(isBlack) {
			ans += added;
		}
		else {
			ans -= added;
		}
	}

	return ret;
}

char S[350004];
int main() {
	int t;
	inp1(t);
	getchar();
	while(t--) {
		v.clear();
		int depth = 0;
		ans=0;
		getchar();
		gets(S);
		int len = strlen(S);
		FOR(i,len) {
			if(S[i] == '(') ++depth;
			else --depth;
			v.pb(depth);
		}
		int nodeCnt = 1 << (int)(ceil(log2(len))+1);
		rangeMin.resize(nodeCnt);
		size = v.size();
		v.pb(INF);
		init(0,size-1,1);

		widthHeight(1,0,strlen(S)-1);
		printf("%lld\n",ans);
	}
	return 0;
}