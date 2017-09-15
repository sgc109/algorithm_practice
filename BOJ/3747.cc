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

int n,m;
vvi adj;

vi findOrder;
vi sccId;
stack<int> s;
int sccCnt, orderCnt;
int scc(int here) {
	int ret = findOrder[here] = orderCnt++;
	s.push(here);

	FOR(i,adj[here].size()) {
		int there = adj[here][i];

		if(findOrder[there] == -1) {
			ret = min(ret, scc(there));
		}
		else if(sccId[there] == -1) {
			ret = min(ret, findOrder[there]);
		}
	}
	if(ret >= findOrder[here]) {
		int p=-1;
		while(p!=here){
			p=s.top();
			s.pop();
			sccId[p]=sccCnt;
		}
		++sccCnt;
	}

	return ret;
}

int convert(int x) {
	if(x<0) return 2*(abs(x)-1)+1;
	return 2*(x-1);
}

int NOT(int x) {
	return x^1;
}

int main() {
	while(inp2(n,m) == 2) {
		adj = vvi(2*n,vi());
		findOrder = vi(2*n,-1);
		sccId = vi(2*n,-1);

		char strA[20];
		char strB[20];
		FOR(i,m) {
			scanf("%s",strA);
			scanf("%s",strB);
			int a = atoi(strA);
			int b = atoi(strB);
			adj[NOT(convert(a))].pb(convert(b));
			adj[NOT(convert(b))].pb(convert(a));
		}
		sccCnt = orderCnt = 0;
		FOR(i,2*n) {
			if(findOrder[i] == -1) scc(i);
		}

		bool imposs=false;
		for(int i = 0; i < 2*n; i+=2) {
			if(sccId[i] == sccId[i+1]) {
				imposs=true;
				break;
			}
		}
		if(imposs) {
			printf("0\n");
			continue;
		}
		printf("1\n");
	}
	return 0;
}