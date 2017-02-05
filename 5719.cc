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

vii G[503];
vi p[503];
int rm[503][503],dist[503];
int N,M,S,D,a,b,c;
void dijkstra(int start){
	memset(dist,0x3c,sizeof(dist));
	dist[start]=0;
	priority_queue<pii> pq;
	pq.push({0,start});
	while(!pq.empty()){
		int here = pq.top().second;
		int hereD = -pq.top().first;
		pq.pop();
		if(hereD>dist[here]) continue;
		for(auto pp : G[here]){
			int there = pp.first;
			int thereD = hereD+pp.second;
			if(rm[here][there]) continue;
			if(dist[there]==thereD) p[there].pb(here);
			else if(dist[there]>thereD){
				p[there].clear();
				dist[there]=thereD;
				p[there].pb(here);
				pq.push({-thereD,there});
			}
		}
	}
}
void go(int here){
	for(int prev : p[here]){
		rm[prev][here]=1;
		go(prev);
	}
}
int main() {
	while(1){
		inp2(N,M);
		FOR(i,N) G[i].clear(),p[i].clear();
		memset(rm,0,sizeof(rm));
		if(!N&&!M) break;
		inp2(S,D);
		while(M--){
			inp3(a,b,c);
			G[a].pb({b,c});
		}
		dijkstra(S);
		go(D);
		dijkstra(S);
		if(dist[D]==INF) dist[D]=-1;
		printf("%d\n",dist[D]);
	}
	return 0;
}
