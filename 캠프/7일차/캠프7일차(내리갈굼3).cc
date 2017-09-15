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

struct LR{int l,r;};


LR lr[100003];
int N,M,a,b,c,id,n;
vi adj[100003];
ll up[200003];
int parent[100003];
void dfs(int here){
	lr[here].l=id++;
	for(int there:adj[here]){
		dfs(there);
	}
	lr[here].r=id++;
}
ll query(int p){
	ll ret=0;
	while(p>0){
		ret+=up[p];
		p-=p&-p;
	}
	return ret;
}
void update(int p,int add){
	while(p<=id){
		up[p]+=add;
		p+=p&-p;
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N >> M;
	REP(i,1,N){
		cin >> a;
		if(!i) continue;
		parent[i]=a;
		adj[a].pb(i);
	}
	dfs(1);
	while(M--){
		cin >> a >> b;
		if(a==2) printf("%lld\n",query(lr[b].r)-query(lr[b].l-1));
		else {
			cin >> c;
			update(lr[b].r,c);
		}
	}
	return 0;
}
