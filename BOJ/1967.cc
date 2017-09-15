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

int N,a,b,c;
vii G[10003];
int ans;
int dfs(int here, int dad){
	vi v;
	for(auto p : G[here]){
		int there = p.first;
		int cost = p.second;
		if(there==dad) continue;
		v.pb(dfs(there,here)+cost);
	}
	if(!sz(v)) return 0;
	sort(all(v));
	ans=max(ans,v.back());
	if(sz(v)>1) ans=max(ans,v.back()+v[sz(v)-2]);
	return v.back();
}
int main() {
	inp1(N);
	FOR(i,N-1){
		inp3(a,b,c);
		G[a].pb({b,c});
		G[b].pb({a,c});
	}
	dfs(1,0);
	printf("%d",ans);
	return 0;
}
