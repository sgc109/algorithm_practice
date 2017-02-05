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

int N,M;
int dp[1<<20][100];
char pane[12][12];
int go(int state, int pos){
	state%=(1<<20);
	if(pos==N*M) return 0;
	int& cache=dp[state][pos];
	if(cache!=-1) return cache;
	int ret=INF;
	int up=(state&(3<<(2*(M-1))))>>(2*(M-1));
	int left=state&3;
	if(pane[pos/M][pos%M]=='#') ret=min(ret,go(state<<2,pos+1));
	else {
		ret=min(ret,go((state<<2)|1,pos+1)+(up!=1));
		ret=min(ret,go((state<<2)|2,pos+1)+(pos%M==0||left!=2));
	}
	return cache=ret;
}
int main() {
	memset(dp,-1,sizeof(dp));
	cin >> N >> M;
	FOR(i,N) scanf("%s",pane[i]);
	cout << go(0,0);

	return 0;
}
