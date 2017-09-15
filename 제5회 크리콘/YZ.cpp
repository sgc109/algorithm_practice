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

int dy[] = {0, -1, 1, 0};
int dx[] = {-1, 0, 0, 1};

int N,M;
char pane[403][403];
int ans[403][403];
int visited[403][403];
vii path;
unordered_map<ll,int> um;
int cnt;
ll trans(int hereI, int hereJ, int ud, int lr){
	return hereI*401*401*401+hereJ*401*401+ud*401+lr;
}
int dfs(int hereI, int hereJ, int ud, int lr, char color) {
	if(hereI < 0) ud--, hereI=N-1;
	if(hereI >= N) ud++, hereI=0;;
	if(hereJ < 0) lr--, hereJ=M-1;
	if(hereJ >= M) lr++, hereJ=0;

	if(pane[hereI][hereJ] != color) return 0;
	auto& p = um[trans(hereI,hereJ,ud,lr)];
	if(p) return 0;
	p = 1;
	cnt++;
	visited[hereI][hereJ] = 1;

	if(N*M < cnt) return 1;

	FOR(k,4){
		int nextI = hereI + dy[k];
		int nextJ = hereJ + dx[k];
		if(dfs(nextI, nextJ, ud, lr, color)) return 1;
	}
	return 0;
}
int main() {
	inp2(N,M);
	FOR(i,N) scanf("%s",pane[i]);
	FOR(i,N){
		FOR(j,M){
			if(visited[i][j]) continue;
			um.clear();
			cnt = 0;
			if(dfs(i,j,0,0,pane[i][j])) ans[i][j] = -1;
			else ans[i][j] = cnt;
		}
	}
	FOR(i,N){
		FOR(j,M){
			printf("%d ",ans[i][j]);
		}
		printf("\n");
	}
	return 0;
}
