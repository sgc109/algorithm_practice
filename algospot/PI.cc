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
typedef vector<vector<int> > vvi;
typedef pair<int,int> pii;
typedef pair<int,pair<int,int> > piii;
typedef queue<int> QU;

const int INF = 0x3c3c3c3c;
const long long INFL = 0x3c3c3c3c3c3c3c3c;
const int MAX_N = 10002;


char S[MAX_N];
int dp[MAX_N];
int len;

int figureDif(int pos, int n){
	int diff=S[pos]-S[pos+1];
	bool inc=true;
	bool swit=true;
	REP(i,1,n-1){
		int here=pos+i;
		if(S[here]-S[here+1]!=diff) {
			inc=false;
			if(i%2==0) swit=false;
		}
		if(i%2==1&&S[here]-S[here+1]!=-diff) swit=false;
	}
	if(inc) {
		if(diff==0) return 1;
		else if(diff==1||diff==-1) return 2;
	}
	if(swit) return 4;
	if(inc) return 5;
	return 10;
}
int solve(int pos){
	if(pos==len) return 0;
	if(pos>len) return INF;
	int ret=INF;
	int& cache = dp[pos];
	if(cache!=-1) return cache;
	REP(i,3,6){
		int tmp = solve(pos+i);
		if(tmp!=INF) ret = min(ret, figureDif(pos,i)+tmp);
	}
	return cache = ret;
}

int main() {
	int T;
	inp1(T);
	while(T--){
		memset(dp,-1,sizeof(dp));
		scanf("%s",S);
		len = strlen(S);
		printf("%d\n",solve(0));
	}
	return 0;
}