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

int N;
int u,v,c;
vii G[10003];
int size[10003];
ll pSum[10003];
ll pSumR[10003];
void dfs1(int here, int dad){
	for(auto p : G[here]){
		int there = p.first;
		int cost = p.second;
		if(there==dad) continue;
		dfs1(there, here);
		size[here] += size[there];
		pSum[here] +=  pSum[there] + size[there] * cost;
	}
	size[here]++;
}
void dfs2(int here, int dad){
	for(auto p : G[here]){
		int there = p.first;
		int cost = p.second;
		if(there==dad) continue;
		pSumR[there] += pSumR[here] + (size[0]-size[there]) * cost + pSum[here] - (pSum[there] + size[there] * cost);
		dfs2(there,here);
	}
}
int main() {
	while(1){
		FOR(i,10003) G[i].clear();
		memset(size,0,sizeof(size));
		memset(pSum,0,sizeof(pSum));
		memset(pSumR,0,sizeof(pSumR));
		inp1(N);
		if(!N) break;
		FOR(i,N-1){
			inp3(u,v,c);
			G[u].pb({v,c});
			G[v].pb({u,c});
		}
		dfs1(0,-1);
		dfs2(0,-1);
		ll ans = INFL;
		FOR(i,N) ans = min(ans, pSum[i] + pSumR[i]);
		printf("%lld\n",ans);
	}
	return 0;
}
