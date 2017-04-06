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

int N;
int adj[303][303];
int inorder[303];
int order[303];
int main() {
	inp1(N);
	FOR(i,N){
		FOR(j,N){
			scanf("%1d",&adj[i][j]);
			if(adj[i][j]) inorder[j]++;
		}
	}	
	priority_queue<int> pq;
	vi ans;
	FOR(i,N){
		if(!inorder[i]){
			pq.push(-i);
		}
	}
	while(!pq.empty()){
		int here = -pq.top();
		ans.pb(here);
		pq.pop();
		FOR(there,N){
			if(!adj[here][there]) continue;
			inorder[there]--;
			if(!inorder[there]) pq.push(-there);
		}
	}	
	if(sz(ans)<N) {
		printf("-1");
		return 0;
	}
	FOR(i,sz(ans)) order[ans[i]] = i+1;
	FOR(i,N) printf("%d ",order[i]);

	return 0;
}
