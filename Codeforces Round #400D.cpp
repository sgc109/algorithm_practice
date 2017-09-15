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

int N,M;
int doors[100003];
vi switche2[100003];

vi G[200003];
int sccCnt, cnt;
int order[200003], sccId[200003];
stack<int> s;
int NOT(int x){
	return x^1;
}
int TRANS(int x){
	return 2*x;
}
int dfs(int here){
	s.push(here);
	int ret = order[here] = cnt++;
	for(int there : G[here]){
		if(sccId[there]!=-1) continue;
		if(order[there]!=-1) ret = min(ret, order[there]);
		else ret = min(ret, dfs(there));
	}	
	if(ret == order[here]){
		while(1){
			int p = s.top();
			s.pop();
			sccId[p] = sccCnt;
			if(p==here) break;
		}
		sccCnt++;
	}
	return ret;
}
int main() {
	memset(order,-1,sizeof(order));
	memset(sccId,-1,sizeof(sccId));
	inp2(N,M);
	FOR(i,N) inp1(doors[i]);
	FOR(i,M){
		int k;
		inp1(k);
		FOR(j,k){	
			int a;
			inp1(a);
			a--;
			switche2[a].pb(i);
		}
	}
	FOR(i,N){
		int swt1 = switche2[i][0];
		int swt2 = switche2[i][1];
		int a = TRANS(swt1);
		int b = TRANS(swt2);
		if(!doors[i]) a = NOT(a);
		G[a].pb(b);
		G[b].pb(a);
		G[NOT(a)].pb(NOT(b));
		G[NOT(b)].pb(NOT(a));
	}
	FOR(i,2*M) if(order[i]==-1) dfs(i);
	vii sorted;
	FOR(i,2*M) sorted.pb({-sccId[i],i});
	sort(all(sorted));  

	FOR(i,sz(sorted)-1){
		if(sorted[i].first == sorted[i+1].first && sorted[i].second == (sorted[i+1].second^1)) {
			printf("NO");
			return 0;
		}
	}
	printf("YES");
	return 0;
}
