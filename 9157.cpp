#include <bits/stdc++.h>
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

int N,S;
int cntCanTake[23];
int dp[21][8194];
int canWin(int pos, int cntStones){
	pos%=2*N;
	if(!cntStones) return 1;
	int& cache = dp[pos][cntStones];
	if(cache!=-1) return cache;
	int ret = 0;
	for(int i = 1; i <= cntCanTake[pos] && i <= cntStones; i++){
		if(!canWin(pos+1,cntStones-i)) ret = 1;
	}
	return cache = ret;
}
int main() {
	while(1){
		inp1(N);
		if(!N) break;
		memset(dp,-1,sizeof(dp));
		inp1(S);
		FOR(i,2*N) inp1(cntCanTake[i]);
		if(canWin(0,S)) printf("1\n");
		else printf("0\n");
	}
	return 0;
}
