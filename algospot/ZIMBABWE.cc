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
const int MAX_N = 15;

int mod10[MAX_N];
int n,m;
string e;
string sorted;
ll dp[1<<MAX_N][20][2];
ll solve(int used, int mod, bool smaller) {
	if(used==(1<<n)-1) return !mod&&smaller;
	ll& cache = dp[used][mod][smaller];
	if(cache != -1) return cache;
	int pos=0;
	FOR(i,n) if((used>>i)&1) pos++;
	ll ret=0;
	FOR(i,n){
		if((used>>i)&1) continue;
		if(!i || sorted[i-1]!=sorted[i] || ((used>>(i-1))&1)){
			if(smaller||sorted[i]<e[pos]) ret+=solve(used|(1<<i),(mod+mod10[n-pos-1]*(sorted[i]-'0'))%m,1);
			else if(sorted[i]==e[pos]) ret+=solve(used|(1<<i),(mod+mod10[n-pos-1]*(sorted[i]-'0'))%m,0);
		}
	}
	return cache=ret%MOD;
}
int main() {
	int T;
	inp1(T);
	while(T--){
		memset(dp,-1,sizeof(dp));
		cin >> e;
		n = e.size();
		inp1(m);
		mod10[0]=1;
		FOR(i,n-1)	{
			mod10[i+1] = (mod10[i]*10)%m;
		}
		sorted = e;
		sort(sorted.begin(),sorted.end());
		printf("%lld\n",solve(0,0,0));
	}
	
	return 0;
}