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

int N,M;
vector<int> G[100003];
int isGiven[100003];
int give[100003];
int visited[100003];
int r[100003];
vector<int> sorted;
void dfs(int here){
	if(visited[here]) return;
	visited[here] = 1;
	for(int there : G[here]){
		dfs(there);
	}
	sorted.push_back(here);
}
void dfs2(int here, int val){
	if(r[here]!=-1) return;
	r[here] = val;
	for(int there : G[here]){
		dfs2(there, val);
	}
}
int main() {
	fastio();
	cin >> N >> M;
	for(int i = 0 ; i < M; i++) {
		int a,b;
		cin >> a >> b;
		a--,b--;
		G[a].push_back(b);
	}
	for(int i = 0 ; i < N; i++){
		cin >> give[i];
		give[i]--;
		isGiven[give[i]]=1;
	}

	for(int i = 0 ; i < N; i++) 
		dfs(i);

	vector<int> ans;
	memset(r,-1,sizeof(r));
	for(int node : sorted){
		if(!isGiven[node]) continue;
		ans.push_back(node);
		dfs2(node, node);
	}

	for(int i = 0 ; i < N; i++) {
		if(give[i] != r[i]) {
			cout << "-1";
			return 0;
		}
	}

	cout << ans.size() << "\n";
	for(int node : ans){
		cout << node+1 << "\n";
	}


	return 0;
}
