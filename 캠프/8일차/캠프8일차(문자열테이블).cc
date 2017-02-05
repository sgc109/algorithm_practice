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

string T[33][33];
pii dp[33][33][33][33];
ll dp2[33][33];
// string dp2[33][33];
int pos;
pii go(int i1, int j1, int i2, int j2){
	if(!i1||!j1||!i2||!j2) {
		if(T[i1][j1][0]<T[i2][j2][0]) return {i1,j1};
		return {i2,j2};
	}
	pii& cache = dp[i1][j1][i2][j2];
	if(cache!=mp(-1,-1)) return cache;
	pii a=go(i1-1,j1,i1,j1-1);
	pii b=go(i2-1,j2,i2,j2-1);
	if(a==b) {
		if(go(i1,j1-1,i2-1,j2)==mp(i1,j1-1)) return cache={i1,j1};
		else return cache={i2,j2};
	}
	else if(a<b) return cache={i1,j1};
	return cache={i2,j2};
}
ll cnt(int i, int j){
	if(!i||!j) return 1;
	ll& cache = dp2[i][j];
	if(cache!=-1) return cache;
	return cache=cnt(i,j-1)+cnt(i-1,j);
}
string solve(int i, int j){
	// printf("solve(%d,%d)\n",i,j);
	if(!i||!j) return T[i][j];
	string& cache = T[i][j];
	if(cache!=".") return cache;
	if(go(i,j-1,i-1,j)==mp(i,j-1)) return cache=solve(i,j-1)+solve(i-1,j);
	return cache=solve(i-1,j)+solve(i,j-1);
// }
// string solve2(int i, int j, ll k){
// 	if(k==1) return T[i][j][0];
// 	if(go(i,j-1,i-1,j)==mp(i,j-1)){
// 		ll tmp=sz(solve(i,j-1));
// 		if(tmp>=k) return solve2(i,j-1,k);
// 		return solve(i,j-1)+solve2(i-1,j,k-tmp);
// 	}
// 	ll tmp=sz(solve(i-1,j));
// 	if(tmp>=k) return solve2(i-1,j,k);
// 	return solve(i-1,j)+solve2(i,j-1,k-tmp);
}
int main() {
	// FOR(i,33) FOR(j,33) dp2[i][j]=".";
	memset(dp2,-1,sizeof(dp2));
	FOR(i,33) FOR(j,33) T[i][j]=".";
	FOR(i,33) FOR(j,33) FOR(k,33) FOR(l,33) dp[i][j][k][l]=mp(-1,-1);
	string s,t;
	cin >> s >> t >> pos;
	FOR(i,sz(s)) T[i+1][0]=s[i];
	FOR(i,sz(t)) T[0][i+1]=t[i];
	string ans = solve(sz(s),sz(t));
	ans.substr(pos,min(50,sz(ans)-pos));
	return 0;
}
