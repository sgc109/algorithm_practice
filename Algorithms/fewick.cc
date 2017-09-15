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
#include <unordered_set>
#include <set>
#include <map>
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
const int INF = 0x3a3a3a3a;
const long long INFL = 0x3a3a3a3a3a3a3a3a;
const int MAX_N = 1000000;

vi nodes;
int n;

int query(int pos) {
	++pos;
	int ret = 0;
	while(pos > 0) {
		ret += nodes[pos];
		pos = pos & pos-1;
	}
	return ret;
}

void update(int pos, int val) {
	++pos;
	while(pos < nodes.size()) {
		nodes[pos] += val;
		pos += (pos & -pos);
	}
}

int segSum(int l, int r) {
	return query(r) - query(l-1);
}

int main() {
	int a[5] = {6,1,2,11,7};
	n = 5;
	nodes = vi(n+1,0);

	FOR(i,n) {
		update(i,a[i]);
	}

	printf("%d\n",segSum(0,0));

	return 0;
}