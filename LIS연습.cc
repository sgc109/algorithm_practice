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

int main() {
	int n;
	int a[201];
	int lis[201];
	int pos[201]={-1,};
	int size=0;
	int from[201];
	inp1(n);
	FOR(i,n) inp1(a[i]);

	FOR(i,n) {
		int lower = lower_bound(lis+1,lis+1+size,a[i]) - lis;
		if(size < lower) size = lower;
		lis[lower]=a[i];
		pos[lower]=i;
		from[i]=pos[lower-1];
	}

	int start=pos[size];

	stack<int> s;
	while(start!=-1) {
		s.push(a[start]);
		start = from[start];
	}
	while(!s.empty()) {
		printf("%d ",s.top());
		s.pop();
	}

	return 0;
}