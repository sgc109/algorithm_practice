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
#include <deque>
// #include <unordered_set>
// #include <map>
#define REP(i,a,b) for(int i = a; i <= b;++i)
#define FOR(i,n) REP(i,0,n-1)
#define mp make_pair
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
typedef vector<vector<int> > vvi;
typedef pair<int,int> pii;
typedef pair<int,pair<int,int> > piii;
typedef queue<int> QU;

const double EPSILON = 1e-9;
const double PI = acos(0.0)*2;
const int MOD = 1000000007;
const int INF = 0x3c3c3c3c;
const long long INFL = 0x3c3c3c3c3c3c3c3c;
const int MAX_N = 102;

int N;
int dy[]={-1,-1,0,0,1,1};
int dx[]={0,1,-1,1,-1,0};
char map[53][53];
int colored[53][53];
int colorNow;
bool inRange(int i, int j){return 0<=j&&j<N&&0<=i&&i<N;}
void dfs(int hereI, int hereJ){
	// printf("hereI:%d, hereJ:%d\n",hereI,hereJ);
	colored[hereI][hereJ]=colorNow;
	colorNow^=1;
	FOR(i,6){
		int ni=hereI+dy[i];
		int nj=hereJ+dx[i];
		if(!inRange(ni,nj)||map[ni][nj]!='X') continue;
		if(colored[ni][nj]!=-1){
			if(colored[ni][nj]==colored[hereI][hereJ]) {
				printf("3");
				exit(0);
			}
		}
		else dfs(ni,nj);
	}
}
int main() {
	memset(colored,-1,sizeof(colored));
	inp1(N);
	FOR(i,N) scanf("%s",map[i]);
	int cnt=0;
	bool adj=false;
	FOR(i,N){
		FOR(j,N){
			if(map[i][j]!='X') continue;
			cnt++;
			FOR(k,6){
				int ni=i+dy[k];
				int nj=j+dx[k];
				if(!inRange(ni,nj)) continue;
				if(map[ni][nj]=='X') adj=true;
			}
		}
	}
	if(!cnt) {
		printf("0");
		return 0;
	}
	if(!adj){
		printf("1");
		return 0;
	}
	FOR(i,N){
		FOR(j,N){
			if(map[i][j]!='X'||colored[i][j]!=-1) continue;
			dfs(i,j);
		}
	}
	printf("2");
	return 0;
}
