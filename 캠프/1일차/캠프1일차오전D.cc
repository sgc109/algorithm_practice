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
const int MAX_N = 502;

int n;
int adj[MAX_N][MAX_N];
int dp[MAX_N][MAX_N][MAX_N];
int ans;
void floyd(){
	FOR(k,n){
		FOR(j,n){
			REP(a,3,n+1){
				dp[j][a] = min(dp[j][a],dp[k][a-1] + adj[k][j]);
				if(a==n) ans=min(ans,dp[j][a]);
			}
		}
	}
}
int main() {
	ans=INF;
	memset(dp,0x3c,sizeof(dp));
	inp1(n);
	FOR(i,n){
		FOR(j,n){
			inp1(adj[i][j]);
			if(!adj[i][j]) adj[i][j]=INF;
			dp[i][j][2]=adj[i][j];
		}
	}
	floyd();
	printf("%d",ans>=INF?-1:ans);
	return 0;
}
