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
const double EPSILON = 1e-9;
const double PI = acos(0.0)*2;
const int MOD = 1000000007;
const int INF = 0x3c3c3c3c;
const long long INFL = 0x3c3c3c3c3c3c3c3c;
const int MAX_N = 102;

int distS[2003],distM1[2003],distM2[2003];
int T,n,m,s,t,g,h,a,b,d,e;
vector<pair<int,int> > G[2003];
void dijkstra(int start, int *dist){
	memset(dist,0x3c,sizeof(dist));
	priority_queue<pair<int,int> > pq;
	pq.push({0,start});
	dist[start]=0;
	while(!pq.empty()){
		int hereDist = -pq.top().first;
		int here = pq.top().second;
		pq.pop();
		if(hereDist > dist[here]) continue;
		for(auto p : G[here]){
			int there = p.first;
			int cost = p.second;
			int thereDist = hereDist+cost;
			if(dist[there]>thereDist){
				dist[there]=thereDist;
				pq.push({-thereDist,there});
			}
		}
	}
}
int main() {
	for(scanf("%d",&T);T--;){
		scanf("%d%d%d",&n,&m,&t);
		scanf("%d%d%d",&s,&g,&h);
		for(int i=1;i<=n;i++) G[i].clear();
		while(m--){
			scanf("%d%d%d",&a,&b,&d);
			G[a].push_back({b,d});
			G[b].push_back({a,d});
		}
		dijkstra(s,distS);
		dijkstra(g,distM1);
		dijkstra(h,distM2);
		vi ans;
		while(t--){
			scanf("%d",&e);
			if(distS[g]+distM1[h]+distM2[e]<=distS[e] || distS[h]+distM2[g]+distM1[e]<=distS[e]) ans.push_back(e);
		}
		sort(ans.begin(),ans.end());
		for(int i=0;i<ans.size();i++) {
			printf("%d ",ans[i]);
		}
		printf("\n");
	}
	return 0;
}
