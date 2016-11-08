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
typedef queue<int> QU;

const int INF = 0x3c3c3c3c;
const long long INFL = 0x3c3c3c3c3c3c3c3c;
const int MAX_N = 102;

int num[MAX_N];
int n;
long long dp[22][MAX_N];
long long solve(int cur, int pos){
	if(pos == n-1) return cur==num[n-1];
	long long ret=0;
	if(cur-num[pos] >=0) {
		long long& cache = dp[cur-num[pos]][pos+1];
		if(cache==-1) cache = solve(cur-num[pos],pos+1);
		ret+=cache;
	}
	if(cur+num[pos] <=20) {
		long long& cache = dp[cur+num[pos]][pos+1];
		if(cache==-1) cache = solve(cur+num[pos],pos+1);
		ret+=cache;
	}
	return ret;
}
int main() {
	memset(dp,-1,sizeof(dp));
	inp1(n);
	FOR(i,n){
		inp1(num[i]);
	}
	printf("%lld",solve(num[0],1));
	return 0;
}