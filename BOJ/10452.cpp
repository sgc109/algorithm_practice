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
#define fastio() ios_base::sync_with_stdio(false),cin.tie(NULL)
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

int N,T;
vi G[1003];
int visited[1003];
void dfs(int here){
	visited[here] = 1;
	for(int there : G[here]){
		if(visited[there]) continue;
		dfs(there);
	}
}
int main() {
	inp1(T);
	while(T--){
		memset(visited,0,sizeof(visited));
		inp1(N);
		FOR(i,N) G[i].clear();
		FOR(i,N){
			int a;
			inp1(a);
			a--;
			G[i].pb(a);
		}
		int ans=0;
		FOR(i,N) {
			if(visited[i]==0) {
				ans++;
				dfs(i);
			}
		}
		printf("%d\n",ans);
	}

	return 0;
}
