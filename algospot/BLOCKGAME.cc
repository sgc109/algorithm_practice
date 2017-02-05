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
const int MAX_N = 102;

vi blocks;
char dp[1<<25];
int upDown(int state){
	int ret=0;
	FOR(i,5) FOR(j,5) ret+=(1<<(i*5+(4-j)))*((state>>((4-i)*5+(4-j)))&1);
	return ret;
}
int leftRight(int state){
	int ret=0;
	FOR(i,5) FOR(j,5) ret+=(1<<((4-i)*5+j))*((state>>((4-i)*5+(4-j)))&1);
	return ret;
}
int UDLR(int state){
	int ret=0;
	FOR(i,5) FOR(j,5) ret+=(1<<(i*5+j))*((state>>((4-i)*5+(4-j)))&1);
	return ret;
}

int canWin(int state){
	char& cache = dp[state];
	if(cache!=-1)return cache;
	FOR(i,blocks.size()){
		if(state&blocks[i]) continue;
		if(!canWin(state|blocks[i])) return cache=1;
	}
	return cache=0;
}
int cell(int y, int x){
	return 1<<((4-y)*5+(4-x));
}
void calcBlocks(){
	FOR(y,4){
		FOR(x,4){
			vi cells;
			FOR(dy,2){
				FOR(dx,2){
					cells.pb(cell(y+dy,x+dx));
				}
			}
			FOR(i,4){
				blocks.pb(cells[0]+cells[1]+cells[2]+cells[3]-cells[i]);
			}
		}
	}
	FOR(i,5){
		FOR(j,4){
			blocks.pb(cell(i,j)+cell(i,j+1));
			blocks.pb(cell(j,i)+cell(j+1,i));
		}
	}
}
int main() {
	calcBlocks();
	int T;
	inp1(T);
	while(T--){
		char map[6][6];
		int state=0;
		memset(dp,-1,sizeof(dp));
		FOR(i,5) {
			scanf("%s",map[i]);
			FOR(j,5) state=state*2+(map[i][j]=='#');
		}

		printf("%s\n",canWin(state)?"WINNING":"LOSING");

	}	
	return 0;
}