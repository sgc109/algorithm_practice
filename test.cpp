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

ll dp[10][1<<10];
int W,H;
int bitOn(int state, int pos){
	return state|(1<<pos-1);
}
int isOn(int state, int pos){
	return state&(1<<pos-1);
}
ll go(int, int);
ll back(int h, int w, int prvState, int curState){
	if(w==W) return go(h+1,curState);
	ll ret=0;
	ret+=back(h,w+1,prvState,curState);
	if(isOn(prvState,w)){
		(ret+=back(h,w+1,prvState,bitOn(curState,w)))%=MOD;
		if(w+1<W && isOn(prvState,w+1)) (ret+=back(h,w+2,prvState,bitOn(bitOn(curState,w),w+1)))%=MOD;
		if(w+2<W && isOn(prvState,w+2)) (ret+=back(h,w+3,prvState,bitOn(bitOn(bitOn(curState,w),w+1),w+2)))%=MOD;
	}
	return ret;
}
ll go(int h, int prvState){
	if(h==H) return 1;
	ll& cache = dp[h][prvState];
	if(cache!=-1) return cache;
	return cache = back(h,0,prvState,0);
}
int main() {
	memset(dp,-1,sizeof(dp));
	scanf("%d%d",&W,&H);
	printf("%lld",go(0,(1<<W)-1));
	return 0;
}
