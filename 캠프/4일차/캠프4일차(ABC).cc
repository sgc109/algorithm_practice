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

int N,K;
int dp[33][33][33][3000];
char ans[33];
int solve(int pos, int A, int B, int P){
	if(pos==N)  return P==K;
	int& cache = dp[pos][A][B][P];
	if(cache != -1) return cache;

	ans[pos]='A';
	if(solve(pos+1,A+1,B,P)) return 1;

	ans[pos]='B';
	if(solve(pos+1,A,B+1,P+A)) return 1;

	ans[pos]='C';
	if(solve(pos+1,A,B,P+A+B)) return 1;

	return cache=0;
}
int main() {
	memset(dp,-1,sizeof(dp));
	inp2(N,K);
	if(solve(0,0,0,0)) ans[N]=0,printf("%s",ans);
	else printf("-1");
	return 0;
}
