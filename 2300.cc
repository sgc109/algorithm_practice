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

const int MOD = 1000000007;
const int INF = 0x3c3c3c3c;
const long long INFL = 0x3c3c3c3c3c3c3c3c;
const int MAX_N = 10002;

int N;
pii cords[MAX_N];
ll dp[MAX_N];
ll solve(int n){
	if(n==N) return 0;
	ll& cache = dp[n];
	if(cache!=-1) return cache;
	ll ret=INFL;
	int l = 0;
	REP(i,n,N){
		l = max(l,max(cords[i].first-cords[n].first,2*abs(cords[i].second)));
		ret = min(ret, l+solve(i+1));
	}
	// printf("n:%d, ret:%lld, l:%d\n",n,ret,l);
	return cache = ret;
}
int main() {
	memset(dp,-1,sizeof(dp));
	inp1(N);
	FOR(i,N){
		inp2(cords[i].first,cords[i].second);
	}
	sort(cords,cords+N);
	printf("%lld",solve(0));
	return 0;
}