// #include <bits/stdc++.h>
#include <vector>
#include <cstdio>
#include <iostream>
#include <cstring>
#include <queue>
#include <set>
#include <map>
#include <cmath>
#include <algorithm>
#include <utility>
#include <string>
#include <unordered_map>
#define REP(i,a,b) for(int i=a;i<=b;++i)
#define FOR(i,n) for(int i=0;i<n;++i)
#define pb push_back
#define all(v) (v).begin(),(v).end()
#define sz(v) ((int)(v).size())
#define inp1(a) scanf("%d",&a)
#define inp2(a,b) scanf("%d%d",&a,&b)
#define inp3(a,b,c) scanf("%d%d%d",&a,&b,&c)
#define inp4(a,b,c,d) scanf("%d%d%d%d",&a,&b,&c,&d)
#define inp5(a,b,c,d,e) scanf("%d%d%d%d%d",&a,&b,&c,&d,&e)z
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef pair<int,int> pii;
typedef vector<pii> vii;
typedef vector<pll> vll;
typedef vector<vector<int> > vvi;
typedef pair<int,pair<int,int> > piii;
typedef pair<pii,pii> piiii;
typedef vector<piii> viii;
const double EPSILON = 1e-9;
const double PI = acos(-1);
const int MOD = 1000000007;
const int INF = 0x3c3c3c3c;
const long long INFL = 0x3c3c3c3c3c3c3c3c;
const int MAX_N = 102;

int N;
int cost[200003][3];
vi DAG[200003];
int visisted[200003];
vi v;
ll dp[200003][2];

void dfs(int here){
	if(visisted[here]) return;
	visisted[here]=1;
	for(int there : DAG[here]) dfs(there);
	v.pb(here);
}
ll solve(int pos, int prevGone){
	if(pos==N) return 0;
	ll& cache = dp[pos][prevGone];
	if(cache!=-1) return cache;
	ll ret=0;
	ll ans1,ans2;
	if(prevGone) {
		ans1=cost[pos][1]+solve(pos+1,1);
		ans2=0;
		if(pos<N-1) ans2=cost[pos][2]+solve(pos+1,0);
	}
	else {
		ans1=cost[pos][0]+solve(pos+1,1);
		ans2=0;
		if(pos<N-1) ans2=cost[pos][1]+solve(pos+1,0);
	}
	return cache=max(ans1,ans2);
}
void trace(int pos, int prevGone){
	if(pos==N-1) return;
	ll ans1 = (prevGone?cost[pos][1]+dp[pos+1][1]:cost[pos][0]+dp[pos+1][1]);
	ll ans2 = (prevGone?cost[pos][2]+dp[pos+1][0]:cost[pos][1]+dp[pos+1][0]);
	if(ans1>ans2){
		DAG[pos].pb(pos+1);
	}
	else {
		DAG[pos+1].pb(pos);
	}
	if(ans1>ans2) trace(pos+1,1);
	else trace(pos+1,0);
}
int main() {
	memset(dp,-1,sizeof(dp));
	inp1(N);
	FOR(i,N) FOR(j,3) inp1(cost[i][j]);
	printf("%lld\n",solve(0,0));
	trace(0,0);
	FOR(i,N) dfs(i);
	reverse(all(v));
	FOR(i,sz(v)) printf("%d ",v[i]+1);
	return 0;
}
