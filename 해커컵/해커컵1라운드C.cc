#include <bits/stdc++.h>
#define REP(i,a,b) for(int i=a;i<=b;++i)
#define FOR(i,n) for(int i=0;i<n;++i)
#define pb push_back
#define all(v) (v).begin(),(v).end()
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

ll D[103][5003][2];
int N,M,K,T;
int G[103][103];
int A[5003],B[5003];
int a,b,c,t;
void floyd(){REP(k,1,N) REP(i,1,N) REP(j,1,N) G[i][j]=min(G[i][j],G[i][k]+G[k][j]);}
ll go(int pos, int lastLoad, int now){
	if(lastLoad==K&&!now) return 0;
	ll& cache=D[pos][lastLoad][now];
	if(cache!=-1) return cache;
	ll ret=INFL;
	if(now<2&&lastLoad<K) ret=min(ret,go(A[lastLoad+1],lastLoad+1,now+1)+G[pos][A[lastLoad+1]]);
	if(now>0) ret=min(ret,go(B[(now==1?lastLoad:lastLoad-1)],lastLoad,now-1)+G[pos][B[(now==1?lastLoad:lastLoad-1)]]);
	return cache=ret;
}
int main() {
	freopen("manic_moving.txt","r",stdin);
	freopen("output.txt","w",stdout);	
	for(inp1(T),t=0;T-t;t++){
		memset(G,0x3c,sizeof(G));
		memset(D,-1,sizeof(D));
		inp3(N,M,K);
		FOR(i,M) {
			inp3(a,b,c);
			G[a][b]=min(G[a][b],c),G[b][a]=min(G[b][a],c);
		}
		REP(i,1,K){
			inp2(a,b);
			A[i]=a,B[i]=b;
		}
		floyd();
		REP(i,1,N) G[i][i]=0;
		ll ans=go(1,0,0);
		if(ans>=INF) ans=-1;
		printf("Case #%d: %lld\n",t+1,ans);
	}
	return 0;
}
