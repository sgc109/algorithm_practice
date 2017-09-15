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
unordered_map<ll,ll> dp[2][2];
ll dnc(int s, int e, int l, int r){
	auto& cache = dp[l][r][(ll)s*200000+e];
	if(s==e) return cache=cost[s][l+r];
	if(cache!=0) return cache;
	int m=(s+e)>>1;
	ll ans1 = dnc(s,m,l,0)+dnc(m+1,e,1,r);
	ll ans2 = dnc(s,m,l,1)+dnc(m+1,e,0,r);
	return cache=max(ans1,ans2);
}
void trace(int s, int e, int l, int r){
	if(s==e) return;
	int m=(s+e)>>1;
	ll ans1 = dp[l][0][(ll)s*200000+m]+dp[1][r][(ll)(m+1)*200000+e];
	ll ans2 = dp[l][1][(ll)s*200000+m]+dp[0][r][(ll)(m+1)*200000+e];
	if(ans1>ans2) {
		DAG[m].pb(m+1);
		trace(s,m,l,0);
		trace(m+1,e,1,r);
	}
	else {
		DAG[m+1].pb(m);
		trace(s,m,l,1);
		trace(m+1,e,0,r);
	}
}
void dfs(int here){
	if(visisted[here]) return;
	visisted[here]=1;
	for(int there : DAG[here]) dfs(there);
	v.pb(here);
}
int main() {
	inp1(N);
	FOR(i,N) FOR(j,3) inp1(cost[i][j]);
	printf("%lld\n",dnc(0,N-1,0,0));
	trace(0,N-1,0,0);
	FOR(i,N) dfs(i);
	reverse(all(v));
	FOR(i,sz(v)) printf("%d ",v[i]+1);
	return 0;
}
