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
#define fastio() ios_base::sync_with_stdio(false),cin.tie(NULL)
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

int dp[1003][1003];
int N,K;
string str;
char ans[1003];
int go(int pos, int score){
	if(pos == str.size()) return score == 0 || score == 2*K;
	int& cache = dp[pos][score];
	if(cache != -1) return cache;

	int ret = 0;
	if(score <= 0 || score >= 2*K) return cache = 0;
	if(str[pos] == 'W') return ans[pos] = 'W', cache = go(pos+1, score+1);
	else if(str[pos] == 'D') return ans[pos] = 'D', cache = go(pos+1, score);
	else if(str[pos] == 'L') return ans[pos] = 'L', cache = go(pos+1, score-1);
	
	ans[pos] = 'L';
	if(go(pos+1, score-1)) return 1;
	
	ans[pos] = 'D';
	if(go(pos+1, score)) return 1;

	ans[pos] = 'W';
	if(go(pos+1, score+1)) return 1;

	return 0;
}
int main() {
	memset(dp,-1,sizeof(dp));
	scanf("%d %d\n",&N,&K);
	cin >> str;
	
	if(!go(0, K)) return !printf("NO");

	ans[sz(str)] = 0;
	printf("%s",ans);
	return 0;
}
