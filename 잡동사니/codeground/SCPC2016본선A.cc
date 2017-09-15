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
const int MAX_N = 502;
const int MAX_M = 502;

int n,m;
int dp[MAX_N][MAX_M];
int boxPos[MAX_N];
int pSum[MAX_N][MAX_N]; // pSum[i][j] : i번 마을~j번 마을 이 하나의 쓰레기통을 사용할때 최소 총 거리 합
int solve(int pos, int cntBox){
	if(pos==n) return 0;
	if(cntBox==0) return INF;
	int& cache = dp[pos][cntBox];
	if(cache!=-1) return cache;
	int ret=INF;
	for(int i = pos+1; i <=n; i++){
		ret = min(ret,pSum[pos][i-1]+solve(i,cntBox-1));
	}
	return cache = ret;
}
int main() {
	int T;
	inp1(T);
	FOR(t,T){
		memset(dp,-1,sizeof(dp));
		inp2(n,m);
		FOR(i,n) inp1(boxPos[i]);
		sort(boxPos,boxPos+n);
		for(int i = 0; i < n; i++){
			pSum[i][i] = 0;
			for(int j = i+1; j < n; j++){
				pSum[i][j] = pSum[i][j-1] + boxPos[j] - boxPos[(i+j)>>1];
			}
		}
		int ans = solve(0,m);
		printf("Case #%d\n%d\n",t+1,ans);
	}
	return 0;
}