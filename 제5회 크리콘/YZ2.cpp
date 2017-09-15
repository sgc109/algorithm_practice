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
char pane2[1203][1203];
int ans[403][403];
int visited[1203][1203];
vii path;
int cnt;
bool inf;
int startI,startJ;
bool inRange(int hereI, int hereJ){
	return 0<=hereI && hereI<3*N && 0<=hereJ && hereJ<3*M;
}
void dfs(int hereI, int hereJ, char color){
	if(!inRange(hereI,hereJ)||visited[hereI][hereJ]||color!=pane2[hereI][hereJ]) return;
	cnt++;
	visited[hereI][hereJ] = 1;
	if((hereI!=startI || hereJ!=startJ) && hereI%N==startI%N && hereJ%M==startJ%M) inf=true;
	path.pb({hereI,hereJ});
	FOR(i,4){
		int nextI = hereI + dy[i];
		int nextJ = hereJ + dx[i];
		dfs(nextI, nextJ, color);
	}
}
int main() {
	inp2(N,M);
	FOR(i,N) scanf("%s",pane[i]);
	
	FOR(i,3*N){
		FOR(j,3*M){
			pane2[i][j] = pane[i%N][j%M];
		}
	}
	for(int i = N; i < 2*N; i++){
		for(int j = M; j < 2*M; j++){
			if(visited[i][j]) continue;
			startI = i, startJ = j;
			dfs(i,j,pane2[i][j]);

			for(auto p : path)
				ans[p.first%N][p.second%M] = inf?-1:cnt;
			cnt = 0;
			path.clear();
			inf = false;
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
