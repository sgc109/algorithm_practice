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

const int INF = 0x3a3a3a3a;
const long long INFL = 0x3a3a3a3a3a3a3a3a;
const int MAX_N = 50;
const int MAX_V = 2502;

int flow[MAX_V][MAX_V],cap[MAX_V][MAX_V];
int n,m;
char map[MAX_N][MAX_N];
vi adj[MAX_V];
int cntGaro,cntSero;
pii numMap[MAX_N][MAX_N];
int parent[MAX_V];
bool dfs(int here) {
	if(here == 1) return true;

	for(auto &there : adj[here]) {
		if(cap[here][there]-flow[here][there]>0 && parent[there] == -1) {
			parent[there] = here;
			if(dfs(there)) return true;
		}
	}
	return false;
}
int fordFulkerson() {
	int ret=0;
	while(true) {
		memset(parent,-1,sizeof(parent));
		parent[0] = 0;
		if(!dfs(0)) break;

		int minFlow = INF;
		for(int p = 1; p != parent[p]; p = parent[p]) {
			minFlow = min(minFlow, cap[parent[p]][p]-flow[parent[p]][p]);
		}
		for(int p = 1; p != parent[p]; p = parent[p]) {
			flow[parent[p]][p] += minFlow;
			flow[p][parent[p]] -= minFlow;
		}
		ret+=minFlow;
	}
	return ret;
}
int A(int x){return 2+x;}
int B(int x){return 2+1250+x;}
bool inRange(int i, int j) {
	if(0<=i&&i<n&&0<=j&&j<m) return true;
	return false;
}
int main() {
	inp2(n,m);
	FOR(i,n)FOR(j,m)numMap[i][j]=mp(-1,-1);
	getchar();
	FOR(i,n){
		scanf("%s",map[i]);
	}
	FOR(i,n) {
		FOR(j,m){
			if(map[i][j]=='.') continue;
			if(numMap[i][j].first == -1) {
				int y=i,x=j;
				for(;inRange(y,x)&&map[y][x]!='.';--x){}
				++x;
				for(;inRange(y,x)&&map[y][x]!='.';++x){
					numMap[y][x].first = cntGaro;
					if(numMap[y][x].second != -1) {
						cap[A(numMap[y][x].first)][B(numMap[y][x].second)] = 1;
						adj[A(numMap[y][x].first)].pb(B(numMap[y][x].second));
						adj[B(numMap[y][x].second)].pb(A(numMap[y][x].first));
					}
				}
				++cntGaro;
			}
			if(numMap[i][j].second == -1) {
				int y=i,x=j;
				for(;inRange(y,x)&&map[y][x]!='.';--y){}
				++y;
				for(;inRange(y,x)&&map[y][x]!='.';++y){
					numMap[y][x].second = cntSero;
					if(numMap[y][x].first != -1) {
						cap[A(numMap[y][x].first)][B(numMap[y][x].second)] = 1;
						adj[A(numMap[y][x].first)].pb(B(numMap[y][x].second));
						adj[B(numMap[y][x].second)].pb(A(numMap[y][x].first));
					}
				}
				++cntSero;
			}
		}
	}

	FOR(i,cntGaro) {
		cap[0][A(i)] = 1;
		adj[0].pb(A(i));
		adj[A(i)].pb(0);
	}
	FOR(i,cntSero) {
		cap[B(i)][1] = 1;
		adj[B(i)].pb(1);
		adj[1].pb(B(i));
	}

	int maxFlow = fordFulkerson();
	printf("%d",maxFlow);
	return 0;
}