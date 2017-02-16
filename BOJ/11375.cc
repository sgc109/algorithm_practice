// #include <bits/stdc++.h>
#include <vector>
#include <cstdio>
#include <iostream>
#include <cstring>
#include <queue>
#include <set>
#include <map>
#include <cmath>
#include <algorithm>
#include <utility>
#define REP(i,a,b) for(int i=a;i<=b;++i)
#define FOR(i,n) for(int i=0;i<n;++i)
#define pb push_back
#define all(v) (v).begin(),(v).end()
#define sz(v) ((int)(v).size())
#define inp1(a) scanf("%d",&a)
#define inp2(a,b) scanf("%d%d",&a,&b)
#define inp3(a,b,c) scanf("%d%d%d",&a,&b,&c)
#define inp4(a,b,c,d) scanf("%d%d%d%d",&a,&b,&c,&d)
#define inp5(a,b,c,d,e) scanf("%d%d%d%d%d",&a,&b,&c,&d,&e)
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef pair<int, int> pii;
typedef vector<pii> vii;
typedef vector<pll> vll;
typedef vector<vector<int> > vvi;
typedef pair<int, pair<int, int> > piii;
typedef vector<piii> viii;
const double EPSILON = 1e-9;
const double PI = acos(0.0) * 2;
const int MOD = 1000000007;
const int INF = 0x3c3c3c3c;
const long long INFL = 0x3c3c3c3c3c3c3c3c;
const int MAX_N = 102;

struct edge { int u, v, c, r; };
int N, M, s, t;
int pa[2003], pr[2003], visited[2003];
vector<edge> G[2003];
void connect(int a, int b, int c) {
	G[a].pb(edge{ a,b,c,sz(G[b]) });
	G[b].pb(edge{ b,a,0,sz(G[a]) - 1 });
}
int A(int x) { return 2 + x; }
int B(int x) { return 2 + N + x; }
bool dfs(int here) {
	if (here == t) return true;
	visited[here] = 1;
	int p = 0;
	for (auto e : G[here]) {
		if (!visited[e.v] && e.c > 0) {
			pa[e.v] = here, pr[e.v] = p;
			if (dfs(e.v)) return true;
		}
		p++;
	}
	return false;
}
int ford() {
	int ret = 0;
	while (1) {
		memset(pa, -1, sizeof(pa));
		memset(pr, -1, sizeof(pr));
		memset(visited, 0, sizeof(visited));
		pa[s] = s;
		if (!dfs(s)) break;
		int minFlow = INF;
		for (int p = t; pa[p] != p; p = pa[p]) {
			auto e1 = G[pa[p]][pr[p]];
			minFlow = min(minFlow, e1.c);
		}
		printf("minFlow:%d\n", minFlow);
		for (int p = t; pa[p] != p; p = pa[p]) {
			auto e1 = G[pa[p]][pr[p]];
			auto e2 = G[e1.v][e1.r];
			e1.c -= minFlow, e2.c += minFlow;
		}
		ret += minFlow;
	}
	return ret;
}
int main() {
	s = 0, t = 1;
	inp2(N, M);
	FOR(i, N) {
		int k;
		inp1(k);
		FOR(j, k) {
			int a;
			inp1(a);
			a--;
			connect(A(i), B(a), 1);
		}
	}
	FOR(i, N) connect(s, A(i), 1);
	FOR(i, M) connect(B(i), t, 1);
	printf("%d", ford());

	return 0;
}
