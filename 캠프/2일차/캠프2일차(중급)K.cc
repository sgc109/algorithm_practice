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
#define REP(i,a,b) for(int i = a; i < b;++i)
#define FOR(i,n) REP(i,0,n)
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

string S;
int n;
int dp[51][51][51][2][3];
int solve(int A,int B,int C, int waitB, int waitC){
	int& cache = dp[A][B][C][waitB][waitC];
	if(cache!=-1) return cache;
	if(!A&&!B&&!C) return cache=1;
	int ret=0;
	if(A>0) ret|=solve(A-1,B,C,max(waitB-1,0),max(waitC-1,0));
	if(B>0&&!waitB) ret|=solve(A,B-1,C,1,max(waitC-1,0));
	if(C>0&&!waitC) ret|=solve(A,B,C-1,max(waitB-1,0),2);	
	return cache=ret;
}
void trace(int A,int B,int C, int waitB, int waitC){
	if(!A&&!B&&!C) return;
	if(A>0 && dp[A-1][B][C][max(waitB-1,0)][max(waitC-1,0)]) {
		printf("A");
		trace(A-1,B,C,max(waitB-1,0),max(waitC-1,0));
		return;
	}
	if(B>0&&!waitB&&dp[A][B-1][C][1][max(waitC-1,0)]) {
		printf("B");
		trace(A,B-1,C,1,max(waitC-1,0));
		return;
	}
	if(C>0&&!waitC&&dp[A][B][C-1][max(waitB-1,0)][2]) {
		printf("C");
		trace(A,B,C-1,max(waitB-1,0),2);	
	}
}
int cnt[3];
int main() {
	memset(dp,-1,sizeof(dp));
	cin >> S;
	n=S.size();
	FOR(i,n){
		cnt[S[i]-'A']++;
	}
	if(!solve(cnt[0],cnt[1],cnt[2],0,0)) printf("-1");
	else trace(cnt[0],cnt[1],cnt[2],0,0);
	return 0;
}
