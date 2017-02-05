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
int N,M,a,b,c,id,mode;
vi adj[100003];
ll up[200003],down[200003];
void dfs(int here){
	lr[here].l=id++;
	for(int there:adj[here]) dfs(there);
	lr[here].r=id++;
}
ll query(ll *t, int p){
	ll ret=0;
	while(p>0){
		ret+=t[p];
		p-=p&-p;
	}
	return ret;
}
void update(ll *t, int p,int add){
	while(p<=id){
		t[p]+=add;
		p+=p&-p;
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N >> M;
	REP(i,1,N){
		cin >> a;
		if(a!=-1) adj[a].pb(i);
	}
	id=1;
	dfs(1);
	id--;
	while(M--){
		cin >> a;
		if(a==2) {
			cin >> b;
			cout << query(up,lr[b].r)-query(up,lr[b].l-1)+query(down,lr[b].l) << "\n";
		}
		else if(a==1){
			cin >> b >> c;
			if(mode) update(up,lr[b].r,c);
			else update(down,lr[b].l,c),update(down,lr[b].r+1,-c);
		}
		else mode^=1;
	}
	return 0;
}
