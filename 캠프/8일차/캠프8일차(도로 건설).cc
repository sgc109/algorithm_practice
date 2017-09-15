// #include <bits/stdc++.h>
#include <unordered_set>
// #include <unordered_map>
// #include <iostream>
#include <vector>
#include <cstdio>
#include <cstring>
#include <queue>
#include <set>
#include <map>
#include <cmath>
#include <algorithm>
#include <utility>
#include <string>
#define REP(i,a,b) for(int i=a;i<=b;++i)
#define FOR(i,n) for(int i=0;i<n;++i)
#define pb push_back
#define all(v) (v).begin(),(v).end()
#define sz(v) ((int)(v).size())
#define inp1(a) scanf("%d",&a)
#define inp2(a,b) scanf("%d%d",&a,&b)
#define inp3(a,b,c) scanf("%d%d%d",&a,&b,&c)
#define inp4(a,b,c,d) scanf("%d%d%d%d",&a,&b,&c,&d)
#define inp5(a,b,c,d,e) scanf("%d%d%d%d%d",&a,&b,&c,&d,&e)
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
typedef vector<piii> viii;
const double EPSILON = 1e-9;
const double PI = acos(-1);
const int MOD = 1000000007;
const int INF = 0x3c3c3c3c;
const long long INFL = 0x3c3c3c3c3c3c3c3c;
const int MAX_N = 102;

int N,M,K;
ll dp[33][33][33][1<<9];
ll go(int u, int v, int restRoad, int state){
	if(u==N) return !restRoad;
	if(restRoad<0) return 0;
	ll& cache = dp[u][v][restRoad][state];
	if(cache!=-1) return cache;
	if(v==min(u+K+1,N)) return cache = (state&1?0:go(u+1,u+2,restRoad,state>>1));
	return cache = (go(u,v,restRoad-1,(state^1)^(1<<v-u))+go(u,v+1,restRoad,state))%MOD;
}
int main() {
	memset(dp,-1,sizeof(dp));
	scanf("%d%d%d",&N,&M,&K);
	printf("%lld", go(0,1,M,0));
	return 0;

}
