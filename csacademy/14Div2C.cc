#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <queue>
#include <utility>
#include <stack>
#include <cstring>
#include <cstdlib>
#include <string>
#include <set>
#include <cmath>
// #include <unordered_set>
// #include <map>
#define REP(i,a,b) for(int i = a; i < b;++i) 
#define FOR(i,n) REP(i,0,n)
#define mp make_pair
#define pb push_back
#define inp1(a) scanf("%d",&a)
#define inp2(a,b) scanf("%d%d",&a,&b)
#define inp3(a,b,c) scanf("%d%d%d",&a,&b,&c)
#define inp4(a,b,c,d) scanf("%d%d%d%d",&a,&b,&c,&d)
// #define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)

using namespace std;

typedef long long ll;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<vector<int> > vvi;
typedef pair<int,int> pii;
typedef pair<int,pair<int,int> > piii;
typedef queue<int> QU;

const int MOD = 1000000007;
const int INF = 0x3c3c3c3c;
const long long INFL = 0x3c3c3c3c3c3c3c3c;
const int MAX_N = 1002;
const int MAX_M = 1002;

int n,m;
int map[MAX_N][MAX_M];
int visited[MAX_N][MAX_M];

int dx[4] = {0,-1,1,0};
int dy[4] = {-1,0,0,1};
int X1,X2,Y1,Y2,area;
bool inRange(int i, int j){
	if(0<=i&&i<n&&0<=j&&j<m) return true;
	return false;
}
void dfs(int hereI, int hereJ){
	X1 = min(X1,hereJ);
	X2 = max(X2,hereJ);
	Y1 = min(Y1,hereI);
	Y2 = max(Y2,hereI);
	area++;
	visited[hereI][hereJ]=1;
	FOR(i,4){
		int thereI = hereI+dy[i];
		int thereJ = hereJ+dx[i];
		if(inRange(thereI,thereJ) && map[thereI][thereJ] == 1 && !visited[thereI][thereJ]) dfs(thereI,thereJ);
	}
}
int main() {
	memset(visited,0,sizeof(visited));
	inp2(n,m);
	FOR(i,n){
		FOR(j,m){
			inp1(map[i][j]);
		}
	}

	int ans=-1;

	FOR(i,n){
		FOR(j,m){
			if(map[i][j]==1 && !visited[i][j]){
				area=0;
				X1=1002;X2=-1;
				Y1=1002;Y2=-1;
				dfs(i,j);
				// printf("Y1:%d, Y2:%d, X1:%d, X2:%d, area:%d\n",Y1,Y2,X1,X2,area);
				if((X2-X1+1)*(Y2-Y1+1)!=area) continue;
				if(inRange(Y1-1,X1-1)&&inRange(Y2+1,X2+1)
					&&map[Y1-1][X1-1]==0
					&&map[Y1-1][X2+1]==0
					&&map[Y2+1][X1-1]==0
					&&map[Y2+1][X2+1]==0) ans=max(ans,area);
			}
		}
	}
	printf("%d",ans);
	return 0;
}