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
// #define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)

using namespace std;

typedef long long ll;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<vector<int> > vvi;
typedef pair<int,int> pii;
typedef pair<int,pair<int,int> > piii;
typedef queue<int> QU;

const int MOD = 1000000007;
const int INF = 0x3c3c3c3c;
const long long INFL = 0x3c3c3c3c3c3c3c3c;
const int MAX_N = 102;
const int MAX_W = 1002;

int n;
string things[MAX_N];
int W[MAX_N];
int P[MAX_N];
// int selected[MAX_N];
int dp[MAX_W][MAX_N];

int solve(int w, int pos){
	if(pos==n) return dp[w][pos]=0;
	int& cache = dp[w][pos];
	if(cache != -1) return cache;
	int ret=0;
	if(w>=W[pos]) {
		ret=solve(w-W[pos],pos+1)+P[pos];
		// selected[pos]=1;
	}
	int notSelect = solve(w,pos+1);
	if(ret < notSelect){
		ret = notSelect;
		// selected[pos]=0;
	}
	return cache=ret;
}

void reconstruct(int w, int pos, vector<string>& vs){
	if(pos==n) return;

	if(dp[w][pos]!=dp[w][pos+1]) {
		vs.push_back(things[pos]);
		reconstruct(w-W[pos],pos+1,vs);
	}
	else reconstruct(w,pos+1,vs);
}

int main() {
	int T;
	inp1(T);
	while(T--){
		memset(dp,-1,sizeof(dp));
		int limit;
		inp2(n,limit);
		FOR(i,n){
			cin >> things[i];
			inp2(W[i],P[i]);
		}
		printf("%d ",solve(limit,0));
		int cnt=0;
		vector<string> vs;
		reconstruct(limit,0,vs);
		printf("%d\n",vs.size());
		FOR(i,vs.size()){
			cout << vs[i] << "\n";
		}
	}
	
	return 0;
}