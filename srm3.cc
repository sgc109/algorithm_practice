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
typedef pair<int,int> pii;
typedef vector<pii> vii;
typedef vector<pll> vll;
typedef vector<vector<int> > vvi;
typedef pair<int,pair<int,int> > piii;
typedef vector<piii> viii;
const double EPSILON = 1e-9;
const double PI = acos(0.0)*2;
const int MOD = 1000000007;
const int INF = 0x3c3c3c3c;
const long long INFL = 0x3c3c3c3c3c3c3c3c;
const int MAX_N = 102;
class FoxPlayingGame{
public:
	double theMax(int nA, int nB, int paramA, int paramB){
		double ret=0;
		double a=paramA/1000.0;
		double b=paramB/1000.0;
		if((a>0&&(-1<b&&b<1))||(a<0&&b>=1)) nB=0;
		else {
			if(a<0&&(-1<b&&b<0)) nB=min(nB,1);
			if(b<=-1&&nB>0){
				if(a>0&&nB%2) nB--;
				if(a<0&&nB%2==0) nB--;
			}
		}
		FOR(i,nA) ret+=a;
		FOR(i,nB) ret*=b;
		return ret;
	}
};