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
#include <unordered_set>
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

int n;
int dp[1<<15];
int poss[1<<15];
int solve(int state){
	// printf("state:%d\n",state);
	if(state==0) return 0;
	int& cache = dp[state];
	if(cache!=-1) return cache;
	int ret = poss[state];
	REP(i,1,1<<n){
		if((state|i)!=state || state==i) continue;
		ret=max(ret,solve(i)+solve(state^i));
	}
	return cache=ret;
}
string vs[16]={"NYYN",
 "YNYY",
 "YYNY",
 "NYYN"};
unordered_set<int> us[16];
int main() {
	memset(dp,-1,sizeof(dp));
	n = vs[0].size();
	FOR(i,n){
		FOR(j,n){
			if(vs[i][j]=='Y') us[i].insert(j);
		}
	}
	int check[15];
	FOR(state,1<<n){
		memset(check,0,sizeof(check));
		FOR(i,n){
			if(!((state>>i)&1)) continue;
			check[i]=1;
			FOR(j,n){
				if(j==i||vs[i][j]=='N') continue;
				check[j]=1;
				FOR(k,n){
					if(k==i||k==j||vs[j][k]=='N') continue;
					if(us[k].count(i)) check[k]=1;
				}
			}
		}
		int cnt=0;
		FOR(i,n) if(check[i])++cnt;
		if(cnt==n) poss[state]=1;
	}
	printf("%d",solve((1<<n)-1));
	return 0;
}