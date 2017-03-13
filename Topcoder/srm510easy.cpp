/*
https://community.topcoder.com/stat?c=problem_statement&pm=11461

dp 문제이다. 꽤나 익숙한 유형중 하나이다. 어떠한 수가 있으면 맨윗자리부터 내려오면서 조건을 만족하는 가능한 숫자들의 경우의 수를 구하는문제로
보통 문제에서 주어진 상한이나 하한을 보면서 특정 자리수가 상한보다 낮아지거나 하한보다 높아지는순간 그 뒷자리는 크기에대해 전혀 신경을 쓰지 않아도 되므로
그에 대한 메모를 bool 형태로 memoization 해주면된다. 이 문제에서는 하한과 상한 두개 모두 있으므로 두개를 함께 따져주며 계산을 하면되고
4나 7을 제외한 수가 최대 한번만 나올 수있다는 조건도 있으므로 지금까지 4나 7을 제외한 수가 나왔는지 안나왔는지도 함께 memoization 해주면된다
단 아직 앞에 leading zero만 나왔을땐 4나7이 아닌수가 나왔다고 세면 안되기 때문에 이것도 memoization 해준다. 즉 bool형태의 memoization 을 4개해주고
현재 몇자리까지 봐줬는지를 하나봐주면되는데 10^16까지니까 최대 17정도될것이다.
그리고 지금까지는 이진수에 대해서 이렇게 윗자리부터 따져주며 세는것을 많이 봤었는데 십진수에 대해서는 처음본것같다.
*/

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
		if(pos>16) return isStarted;
		long long& cache = dp[pos][upOk][downOk][used][isStarted];
		if(cache != -1) return cache;
		long long ret=0;
		int up = !upOk ? upLimit[pos]-'0' : 9;
		int down = !downOk ? downLimit[pos]-'0' : 0;
		REP(i,down,up){
			int ndownOk = (i!=down), nupOk = (i!=up);
			int nused = isStarted ? (i!=4 && i!=7) : (i!=4 && i!=7 && i!=0);
			if(used&&nused) continue;
			ret += go(pos+1, upOk|nupOk, downOk|ndownOk, used|nused, isStarted|(i!=0));
		}
		return cache = ret;
	}
	long long find(long long a, long long b){
		memset(dp, -1, sizeof(dp));
		ostringstream os1, os2;
		os1 << a;
		os2 << b;
		downLimit = os1.str(), upLimit = os2.str();
		while(downLimit.size()<17) downLimit = "0" + downLimit;
		while(upLimit.size()<17) upLimit = "0" + upLimit;
		return go(0,0,0,0,0);
	}
};