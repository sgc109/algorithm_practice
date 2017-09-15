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

int N;
vector<pii> adj[2003];
int a,b,c;
ll dist[2003];
ll maxD;
int maxI;
int no1,no2;
void dfs(int here, int dad){
	for(auto p : adj[here]){
		int there = p.first;
		int cost = p.second;
		if(there==dad) continue;
		if((here==no1&&there==no2)||(here==no2&&there==no1)) continue;
		dist[there]=dist[here]+cost;
		if(maxD<dist[there]) maxD=dist[there],maxI=there;
		dfs(there,here);
	}
}
int main() {
	inp1(N);
	FOR(i,N-1) {
		inp3(a,b,c);
		adj[a].pb({b,c});
		adj[b].pb({a,c});
	}
	ll ans=0;
	FOR(u,N){
		for(auto p:adj[u]){
			int v=p.first;
			int cost=p.second;
			no1=u,no2=v;

			maxD=0,dist[u]=0,maxI=u;
			dfs(u,-1);
			maxD=0,dist[maxI]=0;
			dfs(maxI,-1);
			ll len1=maxD;
			maxD=0,dist[v]=0,maxI=v;
			dfs(v,-1);
			maxD=0,dist[maxI]=0;
			dfs(maxI,-1);
			ll len2=maxD;
			ans=max(ans,len1+len2+cost);
		}
	}
	printf("%lld",ans);

	return 0;
}
