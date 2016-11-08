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
const int MAX_N = 1000000;

int partialSum[50009];
int n;
int A[50001];
int limit;
int dp[4][50004];
int solve(int trainNum, int pos) {
	if(pos>=n || trainNum >= 3) return 0;
	int ret = 0;
	int& cache1 = dp[trainNum+1][n<pos+limit?n:pos+limit];
	if(cache1==-1) cache1=solve(trainNum+1,n<pos+limit?n:pos+limit);
	ret = max(ret, partialSum[n<pos+limit?n:pos+limit]-partialSum[pos]+cache1);
	int& cache2 = dp[trainNum][pos+1];
	if(cache2==-1) cache2=solve(trainNum,pos+1);
	ret = max(ret, cache2);

	return ret;
}
int main() {
	memset(dp,-1,sizeof(dp));
	inp1(n);
	FOR(i,n) {
		inp1(A[i]);
		partialSum[i+1] = partialSum[i]+A[i];
	}

	inp1(limit);
	printf("%d",solve(0,0));

	return 0;
}