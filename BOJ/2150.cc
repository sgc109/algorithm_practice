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
typedef vector<vector<int> > vvi;
typedef vector<int> vi;

const int INF = 0x3a3a3a3a;
const long long INFL = 0x3a3a3a3a3a3a3a3a;
const int MAX_N = 10002;


stack<int> component;
int sccId[MAX_N];
int findOrder[MAX_N];
vvi adj;
int V,E;

int sccCnt=0, findCnt=0;
int scc(int here) {
	int ret = findOrder[here] = findCnt++;
	component.push(here);

	FOR(i,adj[here].size()) {
		int there = adj[here][i];

		if(findOrder[there] == -1) {
			ret = min(ret,scc(there));
		}
		else if(sccId[there] == -1) {
			ret = min(ret, findOrder[there]);
		}
	}

	if(ret >= findOrder[here]) {
		int p=-1;
		while(p != here) {
			p = component.top();
			component.pop();
			sccId[p] = sccCnt;
		}
		++sccCnt;
	}

	return ret;
}
int main() {
	inp2(V,E);
	adj = vvi(V,vi());
	memset(sccId,-1,sizeof(sccId));
	memset(findOrder,-1,sizeof(findOrder));
	FOR(i,E) {
		int a,b;
		inp2(a,b);
		--a;--b;
		adj[a].pb(b);
	}
	FOR(i,V) {
		if(findOrder[i] == -1) scc(i);
	}

	// FOR(i,V) {
	// 	printf("%d ",sccId[i]);
	// }
	// printf("\n");

	int cnt=0;
	vector<int> ans[MAX_N];
	int check[MAX_N];
	memset(check,-1,sizeof(check));
	FOR(i,V) {
		if(check[sccId[i]] == -1) {
			check[sccId[i]] = cnt++;
			ans[check[sccId[i]]].pb(i+1);
		}
		else {
			ans[check[sccId[i]]].pb(i+1);
		}
	}

	printf("%d\n",cnt);
	FOR(i,cnt) {
		FOR(j,ans[i].size()) {
			printf("%d ",ans[i][j]);
		}
		printf("-1\n");
	}


	return 0;
}