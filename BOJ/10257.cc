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

const int MOD = 1000000007;
const int INF = 0x3c3c3c3c;
const long long INFL = 0x3c3c3c3c3c3c3c3c;
const int MAX_N = 102;


int map[12][1002];
int cntCover[29];
int cover[29];
int stainStat[1002];
bool exist[8];
int cntStat;
int dp[1002][29][29];
void dfs(int here){
	if(here>=8){
		int stat=0;
		int cnt=0;
		FOR(i,8){
			if(exist[i]){
				cnt++;
				stat |= (1<<(i+2));
				stat |= (1<<(i+1));
				stat |= (1<<i);
			}
		}
		cover[cntStat] = stat;
		cntCover[cntStat++] = cnt;
		return;
	}
	exist[here]=true;
	dfs(here+3);
	exist[here]=false;
	dfs(here+1);
}
int main() {
	dfs(0);
	cover[cntStat] = (1<<10)-1;
	cntCover[cntStat++] = 4;
	int T;
	inp1(T);
	FOR(t,T){
		memset(map,0,sizeof(map));
		memset(dp,0x3c,sizeof(dp));
		int m,n,c;
		inp3(m,n,c);
		FOR(i,c){
			int y,x;
			inp2(y,x);
			map[y-1][x-1] = 1;
		}
		FOR(i,n){
			int stat=0;
			for(int j = m-1; j >= 0; j--){
				stat <<= 1;
				stat += map[j][i];
			}
			stainStat[i]=stat;
		}
		int ans=INF;
		FOR(i,n){
			FOR(j,29){
				int jStat = cover[j];
				FOR(k,29){
					int kStat = cover[k];
					FOR(l,29){
						int covered = stainStat[i];
						int lStat = cover[l];
						if(i>=2) covered &= ~jStat;
						if(i>=1) covered &= ~kStat;
						covered &= ~lStat;
						if(covered) continue;
						dp[i][k][l] = min(dp[i][k][l],(i==0?0:dp[i-1][j][k])+cntCover[l]);
						if(i==n-1) ans=min(ans,dp[i][k][l]);
					}
				}
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}