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

int parent[10003], size[10003];
map<pair<int,int>,int> dp;
int N,M,type,u,v,n;
int enemy[10003];
vi V;
int find(int u){
	if(parent[u]==u) return u;
	return parent[u] = find(parent[u]);
}
int merge(int u, int v){
	if(u==-1 || v==-1) return max(u,v);
	u = find(u), v = find(v);
	if(u==v) return u;
	parent[u] = v;
	size[v] += size[u];
	return v;
}
bool beFriend(int u, int v){
	u = find(u), v = find(v);
	if(v == enemy[u] || u == enemy[v]) return false;
	int a = merge(u,v), b = merge(enemy[u],enemy[v]);
	enemy[a] = b;
	if(b!=-1) enemy[b] = a;
	return true;
}
bool beEnemy(int u, int v){
	u = find(u), v = find(v);
	if(u==v) return false;
	int a = merge(u,enemy[v]), b = merge(enemy[u],v);
	enemy[a] = b, enemy[b] = a;
	return true;
}
int go(int pos, int diff){
	diff = abs(diff);
	if(pos==n) return diff+1;
	if(dp[make_pair(pos,diff)]) return dp[make_pair(pos,diff)];

	int ret = min(go(pos+1,diff-V[pos])-1, go(pos+1,diff+V[pos])-1);
	dp[make_pair(pos,diff)] = ret+1;
	return dp[make_pair(pos,diff)];
}
int main() {
	fastio();
	FOR(t,5){
		dp.clear();
		memset(enemy,-1,sizeof(enemy));
		FOR(i,10003) parent[i] = i, size[i] = 1;
		cin >> N >> M;
		bool imposs = false;
		FOR(i,M){
			cin >> type >> u >> v;
			u--,v--;
			if(imposs) continue;
			if(type>0) {
				if(!beFriend(u,v)) {
					imposs = true;
					continue;
				}
			}
			else {
				if(!beEnemy(u,v)) {
					imposs = true;
					continue;
				}
			}
		}
		if(imposs) {
			cout << "-1\n";
			continue;
		}
		V.clear();
		FOR(i,N) {
			if(parent[i]==i) {
				int enem = enemy[i];
				int enemCnt = (enem==-1 ? 0 : size[enem]);
				if(enem!=-1) parent[enem] = -1;
				V.pb(size[i]-enemCnt);
				// cout << "added : " << size[i]-enemCnt << "\n";
			}
		}
		n = V.size();
		cout << go(0,0)-1 << "\n";
	}
	return 0;
}
