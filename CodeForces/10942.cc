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
const int MAX_N = 2002;

int dp[MAX_N][MAX_N];
int n,m;
int arr[MAX_N];
int solve(int l, int r){
	int& cache = dp[l][r];
	if(l==r) return cache=1;
	if(l+1==r) return cache=(arr[l]==arr[r]);
	if(cache!=-1) return cache;
	cache = solve(l+1,r-1)&&(arr[l]==arr[r]);
}
int main() {
	memset(dp,-1,sizeof(dp));
	inp1(n);
	FOR(i,n) inp1(arr[i]);
	FOR(i,n) solve(0,i);
	FOR(i,n) solve(i,n-1);
	inp1(m);
	FOR(i,m){
		int a,b;
		inp2(a,b);
		--a;--b;
		printf("%d\n",dp[a][b]);
	}
	return 0;
}