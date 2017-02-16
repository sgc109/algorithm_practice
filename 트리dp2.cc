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

ll dp[53][2][53][53];
vector<int> G[53];
int N;
int dfs(int here, int dad){

	for(int i=0;i<sz(G[here])){
		int there=G[here][i];
		if(there==dad) continue;
		
	}
}
vector<int> solve(vector<string> graph){
	FOR(i,53) G[i].clear();
	memset(dp,-1,sizeof(dp));
	N=sz(graph);
	for(int i=0;i<sz(graph);i++) for(int j=0;j<sz(graph[i]);j++) if(graph[i][j]=='Y') G[i].pb(j);
	dfs(0,-1);
	vi ret;
	int sum=0;
	
	return ret;
}

class TreeCount{
public:
	vector <int> count(vector <string> graph){
		return solve(graph);
	}
};
int main() {
	TreeCount test;
	vi ans = test.count(
	
	
{"NYY", "YNN", "YNN"}




		);

	FOR(i,sz(ans)) printf("%d ",ans[i]);
	return 0;
}
