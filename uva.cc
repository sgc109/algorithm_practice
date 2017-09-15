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
const int MAX_N = 42;
const int MAX_F = 32002;
int dp[MAX_N][112004];
int cnt[MAX_N];
int num[MAX_N];

int N,F;
int solve(int pos, int want){
	if(pos==N) return want==0;
	int& cache = dp[pos][want+56000];
	if(cache != -1) return cache;
	int a = solve(pos+1,want-num[pos]);
	int b = solve(pos+1,want+num[pos]);
	if(a) cnt[pos]|=1;
	if(b) cnt[pos]|=2;
	// printf("pos:%d, want:%d, dp:%d\n",pos,want,a||b);
	return cache = a||b;
}
int main() {
	while(1){
		inp2(N,F);
		if(!N&&!F) break;
		FOR(i,N) inp1(num[i]);
		memset(dp,-1,sizeof(dp));
		memset(cnt,0,sizeof(cnt));
		if(!solve(0,F)){
			printf("*");
		}
		else {
			FOR(i,N) {
				if(cnt[i]==3) printf("?");
				else if(cnt[i]==2) printf("-");
				else if(cnt[i]==1) printf("+");
			}
		}
		printf("\n");
	}
	return 0;
}