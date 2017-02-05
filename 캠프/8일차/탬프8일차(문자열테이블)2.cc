#include <bits/stdc++.h>
#define REP(i,a,b) for(int i=a;i<=b;++i)
#define FOR(i,n) for(int i=0;i<n;++i)
#define pb push_back
#define mp make_pair
#define all(v) (v).begin(),(v).end()
#define sz(v) ((int)(v).size())
#define inp1(a) scanf("%d",&a)
#define inp2(a,b) scanf("%d%d",&a,&b)
#define inp3(a,b,c) scanf("%d%d%d",&a,&b,&c)
#define inp4(a,b,c,d) scanf("%d%d%d%d",&a,&b,&c,&d)
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<pair<int,int> > vii;
typedef vector<vector<int> > vvi;
typedef pair<int,int> pii;
typedef pair<int,pair<int,int> > piii;
const double EPSILON = 1e-9;
const double PI = acos(0.0)*2;
const int MOD = 1000000007;
const int INF = 0x3c3c3c3c;
const long long INFL = 0x3c3c3c3c3c3c3c3c;
const int MAX_N = 102;

char T[33][33];
ll dp[33][33];
bool lesser[33][33];
ll pos;
ll cnt(int i, int j){
	ll& cache = dp[i][j];
	if(cache) return cache;
	if(!i||!j) return cache=1;
	return cache=cnt(i,j-1)+cnt(i-1,j);
}
char solve(int i, int j){
	if(!i||!j) return T[i][j];
	char& cache = T[i][j];
	if(cache!=-1) return cache;
	if(solve(i-1,j)==solve(i,j-1)) {
		int k;
		if(solve(i-2,j)==solve(i,j-2)){
			lesser[i][j]=lesser[i-1][j-1];
		}
		else lesser[i][j]=solve(i-2,j)<solve(i,j-2);
		return cache=solve(i-1,j);
	}
	lesser[i][j]=solve(i-1,j)<solve(i,j-1);
	return cache=min(solve(i-1,j),solve(i,j-1));
}
bool go(int i, int j, ll k){
	if(!i||!j) {
		printf("%c",T[i][j]);
		return true;
	}
	if(lesser[i][j]){
		if(dp[i-1][j]<=k) return go(i,j-1,k-dp[i-1][j]);
		else return go(i-1,j,k);
	}
	else {
		if(dp[i][j-1]<=k) return go(i-1,j,k-dp[i][j-1]);
		else return go(i,j-1,k);
	}
	return false;
}
int main() {
	memset(T,-1,sizeof(T));
	memset(dp,0,sizeof(dp));
	string s,t;
	cin >> s >> t >> pos;
	FOR(i,sz(s)) T[i+1][0]=s[i];
	FOR(i,sz(t)) T[0][i+1]=t[i];
	cnt(sz(s),sz(t));
	solve(sz(s),sz(t));
	FOR(i,(int)min(50ll,dp[sz(s)][sz(t)]-pos)) go(sz(s),sz(t),pos+i);
	return 0;
}
