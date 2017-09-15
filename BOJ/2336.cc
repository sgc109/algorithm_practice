#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <utility>
#include <stack>
#include <set>
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
const int MAX_N = 500002;

struct Student {
	int score[3];
	bool operator<(const Student& b) const {
		return this->score[0] > b.score[0];
	}
};

Student students[MAX_N];
vector<int> rangeMax;
int size;
int n;

int update(int nodeLeft, int nodeRight, int node, int pos, int val) {
	if(nodeLeft == nodeRight && nodeRight == pos) return rangeMax[node] = val;
	if(nodeRight < pos || pos < nodeLeft) return rangeMax[node];

	int nodeMid = (nodeLeft + nodeRight) >> 1;

	int leftRange = update(nodeLeft, nodeMid, 2*node, pos, val);
	int rightRange = update(nodeMid+1, nodeRight, 2*node+1, pos, val);

	return rangeMax[node] = max(leftRange, rightRange);
}

int query(int nodeLeft, int nodeRight, int left, int right, int node) {
	if(left <= nodeLeft && nodeRight <= right) return rangeMax[node];
	if(right < nodeLeft || nodeRight < left) return -1;

	int nodeMid = (nodeLeft + nodeRight) >> 1;

	int leftRange = query(nodeLeft, nodeMid, left, right, 2*node);
	int rightRange = query(nodeMid+1, nodeRight, left, right, 2*node+1);

	return max(leftRange, rightRange);
}

int update(int pos, int val) {
	return update(0,size-1,1,pos,val);
}

int query(int left, int right) {
	return query(0,size-1,left,right,1);
}

int main() {
	inp1(n);
	FOR(k,3) {
		FOR(i,n) {
			int tmp;
			inp1(tmp);
			students[tmp-1].score[k] = n-i;
		}
	}

	sort(students,students+n);

	size = n+1;
	rangeMax.resize(4*size);
	int ans = 0;
	FOR(i,n) {
		if(students[i].score[1] != n && students[i].score[2] < query(students[i].score[1]+1,n)) {
			++ans;
		}
		update(students[i].score[1],students[i].score[2]);
	}

	printf("%d",n-ans);
	return 0;
}