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

const int MOD = 1000000;
const int INF = 0x3c3c3c3c;
const long long INFL = 0x3c3c3c3c3c3c3c3c;
const int MAX_N = 5002;

string str;
int n;
int dp[MAX_N];
int solve(int pos){
	if(pos==n) return 1;
	if(str[pos]=='0') return -1;
	int& cache = dp[pos];
	if(cache!=-1) return cache;
	int ret=-1;
	int ret1=solve(pos+1);
	int ret2=-1;
	if(pos<n-1 &&(str[pos]-'0')*10+str[pos+1]-'0' <=26) ret2=solve(pos+2);
	if(ret1!=-1&&ret2!=-1) ret=ret1+ret2;
	else if(ret1!=-1) ret=ret1;
	else if(ret2!=-1) ret=ret2;
	return cache=(ret!=-1?ret%MOD:-1);
}

int main() {
	memset(dp,-1,sizeof(dp));
	cin >> str;
	n = str.size();
	int ans = solve(0);
	printf("%d",ans==-1?0:ans);
	return 0;
}