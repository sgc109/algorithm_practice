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

int sccId[303], order[303],visited[303];
int T,N,cnt,sccCnt;
vi G[303];
int adj[303][303];
int newAdj[303][303];
stack<int> s;
vi sccMem[303];
vii ansV;
int tarjan(int here){
	order[here] = cnt++;
	s.push(here);
	int ret = order[here];
	for(int there : G[here]){
		if(sccId[there] != -1) continue;
		if(order[there] != -1) ret = min(ret, order[there]);
		else ret = min(ret, tarjan(there));
	}
	if(ret == order[here]){
		while(!s.empty()){
			int p = s.top();
			s.pop();
			sccId[p] = sccCnt;
			sccMem[sccCnt].pb(p);
			if(p==here) break;
		}
		sccCnt++;
	}
	return ret;
}
void dfs(int here){
	visited[here] = 1;
	for(int there : G[here]){
		if(visited[there]) continue;
		if(sccId[here] != sccId[there]) newAdj[sccId[here]][sccId[there]] = 1;
		dfs(there);
	}
}
int main() {
	inp1(T);
	while(T--){
		ansV.clear();
		FOR(i,303) G[i].clear();
		FOR(i,303) sccMem[i].clear();
		while(!s.empty()) s.pop();
		memset(sccId,-1,sizeof(sccId));
		memset(order,-1,sizeof(order));
		memset(adj,0,sizeof(adj));
		memset(visited,0,sizeof(visited));
		cnt = sccCnt = 0;
		getchar();
		inp1(N);
		FOR(i,N) FOR(j,N) scanf("%1d",&adj[i][j]), (adj[i][j]&&i!=j?G[i].pb(j),0:0);
		FOR(i,N) if(order[i] == -1) tarjan(i);
		int ans = 0;
		memset(newAdj,0,sizeof(newAdj));
		FOR(i,N) {
			memset(visited,0,sizeof(visited));
			dfs(i);
		}
		FOR(i,sccCnt){
			FOR(j,sccCnt){
				if(newAdj[i][j]) ans++, ansV.pb({sccMem[i][0]+1, sccMem[j][0]+1});
			}
		}

		FOR(i,sccCnt) {
			if(sz(sccMem[i])>1) {
				FOR(j,sz(sccMem[i])){
					ansV.pb({sccMem[i][j]+1, sccMem[i][(j+1)%sz(sccMem[i])]+1});
				}
			}
		}
		printf("%d\n",sz(ansV));
		FOR(i,sz(ansV)){
			printf("%d %d\n",ansV[i].first, ansV[i].second);
		}
		printf("\n");
	}
	return 0;
}
