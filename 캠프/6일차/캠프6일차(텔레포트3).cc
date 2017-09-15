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

vi adj[10];
ll dist[10][10];
ll D(ll x1, ll y1, ll x2, ll y2){
	return abs(x1-x2)+abs(y1-y2);
}
pii P[10];
pii H,N;
void floyd(){
	FOR(k,8){
		FOR(i,8){
			FOR(j,8){
				dist[i][j]=min(dist[i][j],dist[i][k]+dist[k][j]);
				// printf("dist[%d][%d]:%lld\n",i,j,dist[i][j]);
			}
		}
	}
}
ll a,b;
int main() {
	memset(dist,0x3c,sizeof(dist));
	FOR(i,8) {
		scanf("%lld%lld",&a,&b),P[i]={a,b};
		if(i>2&&i%2) dist[i][i-1]=dist[i-1][i]=10;
	}
	FOR(i,8){
		FOR(j,8){
			if(dist[i][j]!=INFL) continue;
			dist[i][j]=D(P[i].first,P[i].second,P[j].first,P[j].second);
		}
	}
	floyd();

	printf("%lld",dist[0][1]);

	
	return 0;
}
