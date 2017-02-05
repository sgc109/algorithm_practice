#include <bits/stdc++.h>
#define REP(i,a,b) for(int i=a;i<=b;++i)
#define FOR(i,n) for(int i=0;i<n;++i)
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
typedef vector<pair<int,int> > vii;
typedef vector<vector<int> > vvi;
typedef pair<int,int> pii;
typedef pair<int,pair<int,int> > piii;
const double EPSILON = 1e-9;
const double PI = acos(0.0)*2;
const int MOD = 1000000007;
const int INF = 0x3c3c3c3c;
const long long INFL = 0x3c3c3c3c3c3c3c3c;
const int MAX_N = 100002;

int N,M;
vi G[MAX_N];
vi Gr[MAX_N];
int visited[MAX_N];
stack<int> s;
int sccId[MAX_N];
int idCnt;
int T;
int memberCnt[MAX_N];
void dfs1(int here){
	visited[here]=1;
	for(int there : G[here]){
		if(visited[there]) continue;
		dfs1(there);
	}
	s.push(here);
}
void dfs2(int here){
	sccId[here]=idCnt;
	memberCnt[idCnt]++;
	for(int there : Gr[here]){
		if(sccId[there]!=-1) continue;
		dfs2(there);
	}
}
int main() {
	for(inp1(T);T--;){
		memset(sccId,-1,sizeof(sccId));
		memset(visited,0,sizeof(visited));
		memset(memberCnt,0,sizeof(memberCnt));
		FOR(i,MAX_N) G[i].clear();
		FOR(i,MAX_N) Gr[i].clear();
		idCnt=0;
		inp1(N);
		FOR(i,N){
			int a;
			inp1(a);
			a--;
			G[i].pb(a);
			Gr[a].pb(i);
		}
		FOR(i,N) {
			if(visited[i]) continue;
			dfs1(i);
		}
		while(!s.empty()){
			int here = s.top();
			s.pop();
			if(sccId[here]!=-1) continue;
			dfs2(here);
			idCnt++;
		}
		int ans=0;
		FOR(i,idCnt) if(memberCnt[i]==1) ans++;
		FOR(i,N) if(G[i][0]==i) ans--;
		printf("%d\n",ans);
	}
	return 0;
}
