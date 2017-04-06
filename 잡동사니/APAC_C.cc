// #include <bits/stdc++.h>
// #include <iostream>
#include <unordered_set>
#include <unordered_map>
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
const int MOD = 1e9+7;
const int INF = 0x3c3c3c3c;
const long long INFL = 0x3c3c3c3c3c3c3c3c;
const int MAX_N = 102;

ll dp[100003];
ll ans[100003];
ll sqr(ll x){return x*x;}
ll go(int n){
	if(n<0) return 0;
	if(n==0) return 1;
	if(n%2) return 0;
	ll& cache = dp[n];
	if(cache!=-1) return cache;
	return cache = sqr(go((n-2)/2))+sqr(go(n/2))+2*go((n-2)/2)*go((n-2)/2-2)+(n>2?1:0);
}
int T,L,R;
int main() {
	freopen("output.txt","w",stdout);
	memset(dp,-1,sizeof(dp));
	for(int i = 2; i <= 100000; i+=2){
		if(dp[i]==-1) dp[i]=go(i);
		ans[i]+=ans[i-2]+dp[i];
	}
	scanf("%d",&T);
	for(int t=1; t<=T; t++){
		scanf("%d%d",&L,&R);
		int tmp = 2*min(L,R);
		printf("Case #%d: %lld\n",t,ans[tmp]);
	}
	return 0;
}
