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
const int MAX_N = 200002;
const int MOD = 1e9+7;

vector<pii> rangeSum;
int size;
int n;
int pos[MAX_N];

pii init(int nodeLeft, int nodeRight, int node) {
	if(nodeLeft == nodeRight) return rangeSum[node] = mp(0,0);
	int nodeMid = (nodeLeft+nodeRight) >> 1;
	pii leftRange = init(nodeLeft,nodeMid,2*node);
	pii rightRange = init(nodeMid+1,nodeRight,2*node+1);
	return rangeSum[node] = mp(leftRange.first+rightRange.first,leftRange.second+rightRange.second);
}

pii query(int nodeLeft, int nodeRight, int left, int right, int node) {
	if(left <= nodeLeft && nodeRight <= right) return rangeSum[node];
	if(right < nodeLeft || nodeRight < left) return mp(0,0);
	int nodeMid=(nodeLeft+nodeRight)>>1;
	pii leftRange = query(nodeLeft,nodeMid,left,right,2*node);
	pii rightRange = query(nodeMid+1,nodeRight,left,right,2*node+1);
	return mp(leftRange.first+rightRange.first,(leftRange.second+rightRange.second)%MOD);
}

pii update(int nodeLeft, int nodeRight, int node, int pos, pii val) {
	if(nodeLeft == nodeRight && nodeRight == pos) return rangeSum[node] = mp(rangeSum[node].first+val.first,(rangeSum[node].second+val.second)%MOD);
	if(nodeRight < pos || pos < nodeLeft) return rangeSum[node];
	int nodeMid=(nodeLeft+nodeRight)>>1;
	pii leftRange = update(nodeLeft,nodeMid,2*node,pos,val);
	pii rightRange = update(nodeMid+1,nodeRight,2*node+1,pos,val);
	return rangeSum[node] = mp(leftRange.first+rightRange.first,(leftRange.second+rightRange.second)%MOD);
}

pii query(int left, int right){
	return query(0,size-1,left,right,1);
}

pii update(int pos, pii val) {
	return update(0,size-1,1,pos,val);
}

int main() {
	// FILE *fp = fopen("output.txt","wb");
	FILE *fp = stdout;
	inp1(n);
	FOR(i,n){
		inp1(pos[i]);
	}
	size = 200000;
	rangeSum.resize(4*size);
	init(0,size-1,1);
	long long ans=1;
	FOR(i,n) {
		pii left = pos[i] == 0 ? mp(0,0) : query(0,pos[i]-1);
		pii right = pos[i] == size-1 ? mp(0,0) : query(pos[i]+1,size-1);

		if(i!=0) {
			ans *= ((long long)(right.second-left.second+MOD) + (long long)(left.first-right.first+MOD)*pos[i]) % MOD;
			ans %= MOD;
		}
		// fprintf(fp,"adfs:%lld\n",((long long)(right.second-left.second+MOD) + (long long)(left.first-right.first+MOD)*pos[i])%MOD);

		update(pos[i],mp(1,pos[i]));
		// FOR(i,28) {
		// 	fprintf(fp,"(%d,%d) ",rangeSum[i].first,rangeSum[i].second);
		// }
		// fprintf(fp,"\n");
	}

	fprintf(fp,"%lld",ans);


	return 0;
}