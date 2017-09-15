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
const int MAX_N = 1002;


vi A,B;
vi boys,girls;
int n,m;
ll dp[MAX_N][MAX_N];

ll solve(int posA, int posB){
	if(posA == A.size()) return 0;
	if(posB == B.size()) return INFL;

	ll ret=INFL;

	ll& cache1 = dp[posA][posB+1];
	if(cache1 == -1) cache1 = solve(posA,posB+1);
	ret = min(ret,cache1);
	ll& cache2 = dp[posA+1][posB+1];
	if(cache2==-1) cache2 = solve(posA+1,posB+1);
	ret = min(ret,abs(A[posA]-B[posB])+cache2);

	return ret;
}
int main() {
	memset(dp,-1,sizeof(dp));
	inp2(n,m);
	boys.resize(n);
	girls.resize(m);
	FOR(i,n) inp1(boys[i]);
	FOR(i,m) inp1(girls[i]);

	if(n>=m) {
		A=girls;
		B=boys;
	}
	else {
		A=boys;
		B=girls;
	}
	sort(A.begin(),A.end());
	sort(B.begin(),B.end());
	printf("%lld", solve(0,0));
	return 0;
}