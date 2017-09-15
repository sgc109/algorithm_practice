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
typedef vector<pair<int,int> > vii;
typedef vector<vector<int> > vvi;
typedef pair<int,int> pii;
typedef pair<int,pair<int,int> > piii;
const double EPSILON = 1e-9;
const double PI = acos(0.0)*2;
const int MOD = 1000000007;
const int INF = 0x3c3c3c3c;
const long long INFL = 0x3c3c3c3c3c3c3c3c;
const int MAX_N = 102;

int N,M,a,b,c,S,T;
vii adj[5003];
int dist[5003];
priority_queue<pii> pq;
int main() {
	inp2(N,M);
	FOR(i,M){
		inp3(a,b,c);
		adj[a].pb({b,c});
		adj[b].pb({a,c});
	}
	inp2(S,T);
	memset(dist,0x3c,sizeof(dist));
	dist[S]=0;
	pq.push({0,S});
	while(!pq.empty()){
		int here =pq.top().second;
		int hereD =-pq.top().first;
		pq.pop();
		if(hereD>dist[here]) continue;
		for(auto p:adj[here]){
			int there = p.first;
			int cost = p.second;
			int thereD=hereD+cost;
			if(dist[there]>thereD){
				dist[there]=thereD;
				pq.push({-thereD,there});
			}
		}
	}
	printf("%d",dist[T]);
	return 0;
}
