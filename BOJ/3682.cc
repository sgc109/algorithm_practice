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

vvi adj;
vvi zippedAdj;

vi discovered;
vi sccId;
stack<int> s;

int n,m;

int sccCnt=0,orderCnt=0;
int scc(int here) {
	int ret=discovered[here]=orderCnt++;
	s.push(here);

	FOR(i,adj[here].size()) {
		int there = adj[here][i];

		if(discovered[there] == -1) {
			ret = min(ret, scc(there));
		}
		else if(sccId[there] == -1) {
			ret = min(ret, discovered[there]);
		}
	}

	if(ret >= discovered[here]) {
		int v=-1;
		while(v != here) {
			v = s.top();
			s.pop();
			sccId[v]=sccCnt;
		}
		++sccCnt;
	}

	return ret;
}

vi visited;
vi in,out;
void dfs(int here) {
	visited[here] = 1;

	FOR(i,adj[here].size()) {
		int there = adj[here][i];

		if(sccId[here] != sccId[there]) {
			zippedAdj[sccId[here]].pb(sccId[there]);
			++in[sccId[there]];
			++out[sccId[here]];
		}
		if(visited[there] == 0) {
			dfs(there);
		}
	}
}
int main() {
	int T;
	inp1(T);
	while(T--) {
		inp2(n,m);

		adj = vvi(n,vi());
		zippedAdj = vvi(n,vi());
		sccId = vi(n,-1);
		discovered = vi(n,-1);
		sccCnt=orderCnt=0;
		
		FOR(i,m){
			int a,b;
			inp2(a,b);
			--a;--b;
			adj[a].pb(b);
		}

		// if(n==1&&m==0) {
		// 	printf("0\n");
		// 	continue;
		// }

		FOR(i,n) if(discovered[i] == -1) scc(i);

		int cntComp = 0;
		visited = vi(n,0);
		in = vi(n,0);
		out = vi(n,0);
		FOR(i,n) {
			if(visited[i] == 0) {
				++cntComp;
				dfs(i);
			}
		}
		int ans = 0;
		FOR(i,sccCnt) {
			if(in[i]==0) ++ans;
			if(out[i]==0) ++ans;
		}
		ans -= cntComp;
		// printf("cntComp:%d, sccCnt:%d\n",cntComp,sccCnt);
		if(sccCnt==1) --ans;
		printf("%d\n",ans);
	}
	return 0;
}