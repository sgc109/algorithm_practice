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
int E[303];
ll dp[303][303];
int solve(int pos, int cont){
	if(pos==N) return 1;
	ll& cache = dp[pos][cont];
	if(cache!=-1) return cache;
	ll ans=0;
	ans+=solve(pos+1,0);
	if(E[pos]==-1) ans=(ans+solve(pos+1,cont+1))%MOD;
	else if(pos-E[pos] > cont) ans=(ans+solve(pos+1,cont+1));
	return cache=ans%MOD;
}
int main() {
	memset(dp,-1,sizeof(dp));
	inp2(N,M);
	memset(E,-1,sizeof(E));
	FOR(i,M) {
		int l,r;
		inp2(l,r);
		E[r]=max(E[r],l);
	}
	cout << solve(0,0);

	return 0;
}
