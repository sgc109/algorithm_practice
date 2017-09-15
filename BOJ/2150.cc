#include <bits/stdc++.h>
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
typedef pair<ll,ll> pll;
typedef vector<int> vi;	
typedef vector<ll> vl;
typedef pair<int,int> pii;
typedef vector<pii> vii;
typedef vector<pll> vll;
typedef vector<vector<int> > vvi;
typedef pair<int,pair<int,int> > piii;
typedef vector<piii> viii;
const double EPSILON = 1e-9;
const double PI = acos(-1);
const int MOD = 1e9+7;
const int INF = 0x3c3c3c3c;
const long long INFL = 0x3c3c3c3c3c3c3c3c;
const int MAX_N = 102;

int V,E;
int sccId[10003];
int id;
int a,b;
vi G[10003];
vi Gr[10003];
int visited[10003];
vi sccs[10003];
stack<int> s;
void dfs1(int here){
	if(visited[here]) return;
	visited[here] = 1;
	for(int there : G[here]){
		dfs1(there);
	}
	s.push(here);
}
int dfs2(int here){
	if(sccId[here]!=-1) return 0;
	sccId[here] = id;
	for(int there : Gr[here]){
		dfs2(there);
	}
	return 1;
}
int main() {
	inp2(V,E);
	FOR(i,E){
		inp2(a,b);
		G[a].pb(b);
		Gr[b].pb(a);
	}
	memset(visited,0,sizeof(visited));
	REP(i,1,V) dfs1(i);
	memset(sccId,-1,sizeof(sccId));
	while(!s.empty()){
		if(dfs2(s.top())) id++;
		s.pop();
	}
	REP(i,1,V) sccs[sccId[i]].pb(i);
	printf("%d\n",id);
	sort(sccs,sccs+id);
	FOR(i,id){
		FOR(j,sz(sccs[i])) printf("%d ",sccs[i][j]);
		printf("-1\n");
	}
	return 0;
}
