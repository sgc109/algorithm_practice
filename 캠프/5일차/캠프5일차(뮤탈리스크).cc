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
#include <deque>
// #include <unordered_set>
// #include <map>
#define REP(i,a,b) for(int i = a; i <= b;++i)
#define FOR(i,n) REP(i,0,n-1)
#define mp make_pair
#define pb push_back
#define all(v) (v).begin(),(v).end()
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

const double EPSILON = 1e-9;
const double PI = acos(0.0)*2;
const int MOD = 1000000007;
const int INF = 0x3c3c3c3c;
const long long INFL = 0x3c3c3c3c3c3c3c3c;
const int MAX_N = 102;

int N;
int energy[3];
int dp[300][300][300];
int solve(int a, int b, int c){
	if(a<=0&&b<=0&&c<=0) return 0;
	int& cache=dp[a+230][b+230][c+230];
	if(cache!=-1) return cache;
	int ans=INF;
	int att[3]={1,3,9};
	FOR(i,6){
		if(!((a<=0&&att[0]==9)||(b<=0&&att[1]==9)||(c<=0&&att[2]==9))) ans=min(ans,solve(a-att[0],b-att[1],c-att[2])+1);
		next_permutation(att,att+3);
	}
	return cache=ans;
}
int main() {
	memset(dp,-1,sizeof(dp));
	inp1(N);
	FOR(i,N) inp1(energy[i]);
	printf("%d",solve(energy[0],energy[1],energy[2]));
	return 0;
}
