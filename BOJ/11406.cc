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
#define all(v) (v).begin(),(v).end()
#define inp1(a) scanf("%d",&a)
#define inp2(a,b) scanf("%d%d",&a,&b)
#define inp3(a,b,c) scanf("%d%d%d",&a,&b,&c)
#define inp4(a,b,c,d) scanf("%d%d%d%d",&a,&b,&c,&d)

using namespace std;

typedef long long ll;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<vector<int> > vvi;
typedef pair<int,int> pii;
typedef pair<int,pair<int,int> > piii;
typedef queue<int> QU;

const int MOD = 1000000007;
const int INF = 0x3c3c3c3c;
const long long INFL = 0x3c3c3c3c3c3c3c3c;
const int MAX_N = 102;

int n,m;
int cap[MAX_N<<1][MAX_N<<1];
int parent[MAX_N<<1];
int level[MAX_N<<1];
int cur[MAX_N<<1];
vi adj[MAX_N<<1];
bool dfs(int here){
	if(here==1) return true;
	for(int& i = cur[here]; i<adj[here].size(); i++){
		int there = adj[here][i];
		if(cap[here][there]<=0 || level[there] != level[here]+1) continue;
		parent[there]=here;
		if(dfs(there)) return true;
	}
	return false;
}
int dinic(){
	int maxFlow=0;
	while(1){
		memset(level,-1,sizeof(level));
		memset(cur,0,sizeof(cur));
		level[0]=0;
		queue<int> q;
		q.push(0);
		while(!q.empty()&&level[1]==-1){
			int here = q.front();
			q.pop();
			for(int& there : adj[here]){
				if(cap[here][there]<=0 || level[there]!=-1) continue;
				level[there]=level[here]+1;
				q.push(there);
			}
		}
		if(level[1]==-1) break;
		while(1){
			memset(parent,-1,sizeof(parent));
			if(!dfs(0)) break;
			int minFlow=INF;
			parent[0]=0;
			for(int p=1;p;p=parent[p]) minFlow=min(minFlow,cap[parent[p]][p]);
			for(int p=1;p;p=parent[p]) cap[parent[p]][p]-=minFlow, cap[p][parent[p]]+=minFlow;
			maxFlow+=minFlow;
		}
	}

	return maxFlow;
}
int MAN(int x){return 2+m+x;}
int STORE(int x){return 2+x;}
void connect(int a, int b, int c){
	adj[a].pb(b);
	adj[b].pb(a);
	cap[a][b]=c;
}
int main() {
	int tmp;
	inp2(n,m);
	FR(i,n) {
		inp1(tmp);
		connect(MAN(i),1,tmp);
	}
	FOR(i,m) {
		inp1(tmp);
		connect(0,STORE(i),tmp);
	}
	FOR(i,m) {
		FOR(j,n) {
			inp1(tmp);
			connect(STORE(i),MAN(j),tmp);
		}
	}
	int ans = dinic();
	printf("%d",ans);
	return 0;
}
