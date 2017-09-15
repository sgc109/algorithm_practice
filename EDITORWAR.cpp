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
#define fastio() ios_base::sync_with_stdio(false)
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

int par[10003], size[10003];
int enemy[10003];
int counted[10003];
int N,M,T,u,v;
string sel;
int find(int u){
	if(par[u]==u) return u;
	return par[u] = find(par[u]);
}
bool merge(int u, int v){
	u = find(u), v = find(v);
	if(u==v) return true;
	if(enemy[u]==v || enemy[v]==u) return false;
	// cout << "merge " << u << " and " << v << "\n";
	par[u] = v;
	size[v]+=size[u];
	if(enemy[u]!=-1&&enemy[v]!=-1) merge(enemy[u],enemy[v]);
	if(enemy[u]!=-1) enemy[v] = enemy[u];
	return true;
}
int main() {
	fastio();
	cin >> T;
	while(T--){
		// printf("T:%d\n",T);
		memset(enemy,-1,sizeof(enemy));
		memset(counted,0,sizeof(counted));
		FOR(i,10003) par[i] = i, size[i] = 1;
		cin >> N >> M;
		bool imposs = false;
		FOR(i,M){
			cin >> sel >> u >> v;
			if(imposs) continue;
			u = find(u), v = find(v);
			if(sel=="ACK") {
				if(!merge(u,v)) {
					cout << "CONTRADICTION AT " << i+1 << "\n";
					// printf("CONTRADICTION AT %d\n",i+1);
					imposs = true;
					continue;
				}
			}
			else {
				if(u==v) {
					cout << "CONTRADICTION AT " << i+1 << "\n";
					// printf("CONTRADICTION AT %d\n",i+1);
					imposs = true;
					continue;
				}
				if(enemy[u]==-1) enemy[u]=v;
				else merge(enemy[u],v);
				if(enemy[v]==-1) enemy[v]=u;
				else merge(enemy[v],u);
			}
		}
		if(imposs) continue;
		int ans = 0;
		int tot = N;
		FOR(i,N){
			int u = i;
			u = find(u);
			if(counted[u]) continue;
			counted[u]=1;
			if(enemy[u]==-1) ans+=size[u], tot-=size[u];
			else {
				counted[enemy[u]]=1;
				if(size[u]>size[enemy[u]]) ans+=size[u];
				else ans+=size[enemy[u]];
				tot-=size[u]+size[enemy[u]];
			}
		}
		cout << "MAX PARTY SIZE IS " << ans+tot << "\n";
	}
	return 0;
}