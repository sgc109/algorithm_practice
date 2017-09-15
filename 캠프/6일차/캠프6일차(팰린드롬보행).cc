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

int D[23][23];
int N,M;
char adj[23][23];
int go(int u, int v){
	if(u==v) return 0;
	if(adj[u][v]!=0) return 1;
	int& cache=D[u][v];
	if(cache!=-1) return cache;
	cache=INF;
	int ret=INF;
	FOR(i,N){
		if(adj[u][i]==0) continue;
		FOR(j,N){
			if(adj[v][j]==0) continue;
			if(adj[u][i]==adj[v][j]) ret=min(ret,2+go(i,j));
		}
	}
	return ret;
}
int main() {
	memset(adj,0,sizeof(adj));
	memset(D,-1,sizeof(D));
	inp2(N,M);
	FOR(i,M){
		int a,b;
		char c;
		inp2(a,b);
		scanf(" %c",&c);
		adj[a][b]=adj[b][a]=c;
	}
	int ans=go(0,1);
	if(ans>=INF) ans=-1;
	printf("%d",ans);

	return 0;
}
