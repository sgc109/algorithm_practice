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

int cango[303][303];
int sccId[303];
int N,T,sccCnt;
int adj[303][303];
vi sccMem[303];
int main() {
	inp1(T);
	while(T--){
		sccCnt=0;
		memset(sccId,-1,sizeof(sccId));
		memset(cango,0,sizeof(cango));
		memset(adj,0,sizeof(adj));
		FOR(i,303) sccMem[i].clear();
		getchar();
		inp1(N);
		FOR(i,N) FOR(j,N) scanf("%1d",&cango[i][j]);
		FOR(i,N){
			if(sccId[i]==-1) sccId[i] = sccCnt++, sccMem[sccId[i]].pb(i);
			for(int j = i+1; j < N; j++){
				if(sccId[j]!=-1) continue;
				if(cango[i][j] && cango[j][i]) sccId[j] = sccId[i], sccMem[sccId[j]].pb(j);
			}
		}
		
		FOR(i,N) FOR(j,N) if(cango[i][j] && sccId[i] != sccId[j]) adj[sccId[i]][sccId[j]] = 1;
		FOR(k,sccCnt){
			FOR(i,sccCnt){
				FOR(j,sccCnt){
					if(adj[i][j] && adj[i][k] && adj[k][j]) adj[i][j]=0;
				}
			}
		}
		vii ans;
		FOR(i,sccCnt){
			if(sz(sccMem[i])<=1) continue;
			FOR(j,sz(sccMem[i])){
				ans.pb({sccMem[i][j],sccMem[i][(j+1)%sz(sccMem[i])]});
			}
		}
		FOR(i,sccCnt){
			FOR(j,sccCnt){
				if(adj[i][j]) ans.pb({sccMem[i][0],sccMem[j][0]});
			}
		}
		printf("%d\n",sz(ans));
		for(auto p : ans){
			printf("%d %d\n",p.first+1, p.second+1);
		}
		printf("\n");
	}
	return 0;
}
