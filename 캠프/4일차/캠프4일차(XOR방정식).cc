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
#define REP(i,a,b) for(int i = a; i <= b;++i)
#define FOR(i,n) REP(i,0,n-1)
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

ll S,X;
ll solve(ll sum, int pos){
	if(sum>S) return 0;
	if(pos<0) return sum==S;
	ll ret=0;
	if(X&(1ll<<pos)){
		if((1ll<<pos)+sum<=S) ret+=2*solve(sum+(1ll<<pos),pos-1);
	}
	else {
		if((1ll<<(pos+1))+sum<=S) ret+=solve(sum+2*(1ll<<pos),pos-1);
		if(S-sum<=2*((1ll<<pos)-1)) ret+=solve(sum,pos-1);
	}
	return ret;
}
int main() {
	scanf("%lld%lld",&S,&X);
	cout << solve(0,60)-(X==S?2:0);
	return 0;
}
