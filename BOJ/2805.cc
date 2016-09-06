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

const int INF = 0x3a3a3a3a;
const long long INFL = 0x3a3a3a3a3a3a3a3a;
const int MAX_N = 1000001;

int tree[MAX_N];
int n;
long long m;

long long treeAmount(int h) {
	long long ret = 0;
	FOR(i,n) {
		if(tree[i] > h) {
			ret += tree[i] - h;
		}
	}

	return ret;
}

int main() {
	inp1(n);
	scanf("%lld",&m);
	FOR(i,n) inp1(tree[i]);

	int l = 0, r = 1000000000;
	while(l+1<r) {
		int mid = (l+r)/2;
		if(treeAmount(mid) >= m) l=mid;
		else r=mid;
	}

	printf("%d",l);
	return 0;
}