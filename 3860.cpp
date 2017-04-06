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

int W,H,G,E,X,Y,T;
int X1,Y1,X2,Y2;
vector<pair<pair<int,int>,int> > warf[903];
int isGrave[33][33];
ll dist[903];
int dy[] = {0,-1,1,0};
int dx[] = {-1,0,0,1};
bool inRange(int i, int j){
	return 0<=i && i < H && 0<= j && j < W;
}
int main() {
	while(1){
		FOR(i,903) warf[i].clear();
		memset(isGrave,0,sizeof(isGrave));
		memset(dist,0x3c,sizeof(dist));
		inp2(W,H);
		if(!W&&!H) break;
		inp1(G);
		FOR(i,G){
			inp2(X,Y);
			isGrave[Y][X] = 1;
		}
		inp1(E);
		FOR(i,E){
			inp4(X1,Y1,X2,Y2,T);
			warf[Y1][X1].pb({{X2,Y2},T});
		}

		dist[0] = 0;
		FOR(k,N){
			FOR(i,H){
				FOR(j,W){
					FOR(l,4){
						int ni = i+dy[l];
						int nj = j+dx[l];
						if(!inRange(ni,nj) || isGrave(ni,nj)) continue;
						int there = ni*W+nj;
						int cost = 1;
						if(warf[there].size()) there = warf[there].
						if(dist[there] < dist[here] + )
					}
				}
			}
		}
	}
	return 0;
}