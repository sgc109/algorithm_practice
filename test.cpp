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

class TheAlmostLuckyNumbersDivOne{
public:
	long long dp[20][2][2][2][2];
	string downLimit,upLimit;
	long long go(int pos, int upOk, int downOk, int used, int isStarted){
		if(pos>15) return 1;
		long long& cache = dp[pos][upOk][downOk][used][isStarted];
		if(cache != -1) return cache;
		long long ret=0;
		// printf("pos:%d, upOk:%d, downOk:%d, used:%d\n",pos,upOk,downOk,used);
		int up = !upOk ? upLimit[pos]-'0' : 9;
		int down = !downOk ? downLimit[pos]-'0' : 0;
		// printf("down:%d, up:%d\n",down,up);
		REP(i,down,up){
			int nupOk = (i!=down), ndownOk = (i!=up);
			int nused = isStarted ? (i!=4 && i!=7) : (i!=4 && i!=7 && i!=0);
			if(used&&nused) continue;
			ret += go(pos+1, nupOk, ndownOk, nused, isStarted|(i!=0));
		}
		return cache = ret;
	}
	long long find(long long a, long long b){
		memset(dp, -1, sizeof(dp));
		ostringstream os1, os2;
		os1 << a;
		os2 << b;
		downLimit = os1.str(), upLimit = os2.str();
		while(downLimit.size()<16) downLimit = "0" + downLimit;
		while(upLimit.size()<16) upLimit = "0" + upLimit;
		return go(0,0,0,0,0);
	}
};
int main() {
	TheAlmostLuckyNumbersDivOne obj;
	cout << obj.find(
4,7
		);
	return 0;
}
