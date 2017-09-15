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

int N,M;
char map[53][53];
int totalCnt[300];
int memo[300];
int main() {
	// freopen("output.txt","w",stdout);
	inp2(N,M);
	FOR(i,N) scanf("%s",map[i]);
	FOR(i,N) {
		FOR(j,M) {
			if(map[i][j]=='.') continue;
			totalCnt[map[i][j]]++;
			if(!memo[map[i][j]]) memo[map[i][j]]=1;
		}
	}
	string ans;
	while(1){
		string todo;
		FOR(i,300) if(memo[i]) todo+=(char)i;
		if(todo.size()==0) break;
		string pAns;
		vi LIs,LJs,RIs,RJs;
		FOR(k,todo.size()){
			char nowColor=todo[k];
			// printf("nowColor:%c\n",nowColor);
			int LI=INF,LJ=INF,RI=-1,RJ=-1;
			FOR(i,N){
				FOR(j,M){
					if(map[i][j]==nowColor){
						LI=min(LI,i);
						RI=max(RI,i);
						LJ=min(LJ,j);
						RJ=max(RJ,j);
					}
				}
			}
			if(LI==INF) {
				printf("-1");
				return 0;
			}
			int cnt=0;
			bool poss=true;
			// printf("LI:%d, RI:%d, LJ:%d, RJ:%d\n",LI,RI,LJ,RJ);
			REP(i,LI,RI){
				REP(j,LJ,RJ){
					if(map[i][j]==nowColor) cnt++;
					else if(map[i][j]!='?') {poss=false;goto hell;}
				}
			}
			hell:
			// printf("cnt:%d\n",cnt);
			if(cnt!=totalCnt[nowColor]) continue;
			LIs.pb(LI);
			RIs.pb(RI);
			LJs.pb(LJ);
			RJs.pb(RJ);
			pAns+=nowColor;
			// printf("added:%c\n",nowColor);
		}
		if(pAns.size()==0){
			printf("-1");
			return 0;
		}
		int maxI,maxC=-1;
		FOR(i,pAns.size()){
			if(maxC<pAns[i]) maxC=pAns[i],maxI=i;
		}
		int k=maxI;
		memo[pAns[maxI]]=0;
		REP(i,LIs[k],RIs[k]){
			REP(j,LJs[k],RJs[k]){
				map[i][j]='?';
			}
		}
		ans=pAns[maxI]+ans;
		printf("removed:%c\n",pAns[maxI]);
		// FOR(i,N){
		// 	FOR(j,M){
		// 		printf("%c",map[i][j]);
		// 	}
		// 	printf("\n");
		// }
		// printf("\n");
	}
	cout << ans;
	return 0;
}
