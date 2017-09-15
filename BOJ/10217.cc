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
const double PI = acos(0.0)*2;
const int MOD = 1000000007;
const int INF = 0x3c3c3c3c;
const long long INFL = 0x3c3c3c3c3c3c3c3c;
const int MAX_N = 102;

int T,N,M,K,u,v,x,d;
viii G[103];
int dist[103][10003];
void dijkstra(int start){
	priority_queue<piii> pq;
	pq.push({0,{0,start}});
	dist[start][0]=0;
	while(!pq.empty()){
		int here = pq.top().second.second;
		int hereD = -pq.top().first;
		int hereC = -pq.top().second.first;
		pq.pop();
		if(hereD > dist[here][hereC]) continue;
		for(auto p : G[here]){
			int there = p.first;
			int thereD = hereD+p.second.second;
			int thereC = hereC+p.second.first;
			if(thereC>M || dist[there][thereC]<=thereD) continue;
			dist[there][thereC]=thereD;
			pq.push({-thereD,{-thereC,there}});
		}
	}
}
int main() {
	for(inp1(T);T--;){
		inp3(N,M,K);
		REP(i,1,N) G[i].clear();
		memset(dist,0x3c,sizeof(dist));
		while(K--){
			inp4(u,v,x,d);
			G[u].pb({v,{x,d}});
		}
		dijkstra(1);
		int ans=INF;
		REP(i,0,M) ans=min(ans,dist[N][i]);
		if(ans==INF) printf("Poor KCM\n");
		else printf("%d\n",ans);
	}
	return 0;
}
