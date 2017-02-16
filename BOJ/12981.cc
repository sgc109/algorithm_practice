// #include <bits/stdc++.h>
// #include <unordered_set>
// #include <unordered_map>
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
typedef vector<piii> viii;
const double EPSILON = 1e-9;
const double PI = acos(-1);
const int MOD = 1000000007;
const int INF = 0x3c3c3c3c;
const long long INFL = 0x3c3c3c3c3c3c3c3c;
const int MAX_N = 102;

int dp[103][103][103];
int go(int a, int b, int c){
	if(a<0||b<0||c<0) return INF;
	if(!a&&!b&&!c) return 0;
	int& cache = dp[a][b][c];
	if(cache!=-1) return cache;
	int ret=INF;
	ret=min(ret,1+go(a-3,b,c));
	ret=min(ret,1+go(a,b-3,c));
	ret=min(ret,1+go(a,b,c-3));
	ret=min(ret,1+go(a-1,b-1,c-1));
	ret=min(ret,1+go(a-2,b,c));
	ret=min(ret,1+go(a,b-2,c));
	ret=min(ret,1+go(a,b,c-2));
	ret=min(ret,1+go(a-1,b-1,c));
	ret=min(ret,1+go(a,b-1,c-1));
	ret=min(ret,1+go(a-1,b,c-1));
	ret=min(ret,1+go(a-1,b,c));
	ret=min(ret,1+go(a,b-1,c));
	ret=min(ret,1+go(a,b,c-1));
	return cache=ret;
}
int main() {
	memset(dp,-1,sizeof(dp));
	int A,B,C;
	inp3(A,B,C);
	printf("%d",go(A,B,C));
	return 0;
}
