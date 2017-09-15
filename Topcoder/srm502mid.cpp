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

struct problem{
	ll maxPts;
	ll decPts;
	ll reqT;
	bool operator<(const problem& rhs) const{
		return decPts*rhs.reqT>rhs.decPts*reqT;
	}
};
ll dp[53][100003];
vector<problem> probs;
int N,totT;
class TheProgrammingContestDivOne{
public:
	ll solve(int id, int t){
		if(id==N) return 0;
		ll& cache = dp[id][t];
		if(cache != -1) return cache;
		ll ret = 0;
		ret = max(ret,solve(id+1,t));
		if(probs[id].reqT <= totT-t) ret = max(ret, probs[id].maxPts - (t+probs[id].reqT)*probs[id].decPts + solve(id+1,t+probs[id].reqT));

		return cache=ret;
	}
	int find(int T, vector <int> maxPoints, vector <int> pointsPerMinute, vector <int> requiredTime){
		totT = T;
		memset(dp,-1,sizeof(dp));
		N = sz(maxPoints);
		FOR(i,N) probs.pb({(ll)maxPoints[i],(ll)pointsPerMinute[i],(ll)requiredTime[i]});
		sort(all(probs));
		return (int)solve(0,0);
	}
};
int main() {
	TheProgrammingContestDivOne obj;
	cout << obj.find(
100000, {652, 743, 587, 4926}, {6, 5, 3, 4}, {4, 5, 3, 6}

		);
	return 0;
}
