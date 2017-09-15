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
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)

using namespace std;

typedef long long ll;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<vector<int> > vvi;
typedef pair<int,int> pii;
typedef pair<int,pair<int,int> > piii;

const int INF = 0x3c3c3c3c;
const long long INFL = 0x3c3c3c3c3c3c3c3c;
const int MAX_V = 400;

char map[21][21];
int dist[MAX_V][MAX_V];
int r,c;
int n;
int goldPos[16];
int goldVal[16];
int goldCnt;
int basePos;

int dx[4] = {0,-1,1,0};
int dy[4] = {1,0,0,-1};

long long dp[16][1<<16];

bool inRange(int i, int j){
	if(0<=i&&i<r&&0<=j&&j<c) return true;
	return false;
}

void floyd() {
	FOR(k,n){
		FOR(i,n){
			FOR(j,n){
				dist[i][j] = min(dist[i][j],dist[i][k]+dist[k][j]);
			}
		}
	}
}

long long solve(int from, int visit) {
	long long ret=-2*dist[goldPos[from]][basePos];
	int it = visit;
	FOR(i,goldCnt) {
		if(!(it&1)) {
			long long& cache = dp[i][visit+(1<<i)];
			if(cache == -1) cache = solve(i,visit+(1<<i));
			ret = max(ret, cache - 2*dist[goldPos[from]][goldPos[i]] + goldVal[i]);
		}
		it>>=1;
	}
	return ret;
}

int main() {
	freopen("output.txt","w",stdout);
	int T;
	inp1(T);
	while(T--){
		memset(dp,-1,sizeof(dp));
		memset(dist,0x3c,sizeof(dist));
		goldCnt=0;
		inp2(r,c);
		n=r*c;
		FOR(i,r) scanf(" %s",map[i]);
		FOR(i,r){
			FOR(j,c){
				if(map[i][j]=='~') continue;
				if(map[i][j] == 'E') basePos=i*c+j;
				else if(map[i][j] != '.') {
					goldPos[goldCnt]=i*c+j;
					goldVal[goldCnt++]=map[i][j]-'0';
				}
				FOR(k,4){
					int nextI = i+dy[k];
					int nextJ = j+dx[k];
					if(inRange(nextI,nextJ) && map[nextI][nextJ] != '~') {
						dist[i*c+j][nextI*c+nextJ] = 1;
					}
				}
			}
		}
		floyd();

		long long ans = 0;
		FOR(i,goldCnt) {
			long long& cache = dp[i][1<<i];
			if(cache == -1) cache = solve(i,1<<i);
			// printf("chache:%d\n",cache-2*dist[basePos][goldPos[i]]+goldVal[i]);
			ans = max(ans,cache-2*dist[basePos][goldPos[i]]+goldVal[i]);
		}
		printf("%lld\n",ans);
	}

	return 0;
}