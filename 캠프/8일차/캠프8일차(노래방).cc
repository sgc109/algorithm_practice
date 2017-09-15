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
const double PI = acos(0.0)*2;
const int MOD = 1000000007;
const int INF = 0x3c3c3c3c;
const long long INFL = 0x3c3c3c3c3c3c3c3c;
const int MAX_N = 102;

int dp[2000][2000];
int note[2000];
int N;
int go(int pos, int last){
	if(pos==N-1) return 0;
	int& cache = dp[pos][last+1];
	if(cache!=-1) return cache;
	int ret = INF;
	ret=min(ret,(last==-1?0:abs(note[last]-note[pos+1]))+go(pos+1,pos));
	ret=min(ret,abs(note[pos]-note[pos+1])+go(pos+1,last));
	return cache=ret;
}
int main() {
	memset(dp,-1,sizeof(dp));
	scanf("%d",&N);
	for(int i = 0; i < N; i++) scanf("%d",note+i);
	printf("%d",go(0,-1));
	return 0;
}
