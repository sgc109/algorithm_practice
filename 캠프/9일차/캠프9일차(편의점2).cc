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
const double EPSILON = 1e-9;
const double PI = acos(0.0)*2;
const int MOD = 1000000007;
const int INF = 0x3c3c3c3c;
const long long INFL = 0x3c3c3c3c3c3c3c3c;
const int MAX_N = 102;

int N;
ll X[100003],Y[100003];
ll allSum(ll* home, ll p){
	ll ret=0;
	FOR(i,N) ret+=(abs(p-home[i]));
	return ret;
}
int main() {
	cin >> N;
	FOR(i,N) cin >> X[i] >> Y[i];
	ll lo=-1e7,hi=1e7;
	ll ansX=1e12;
	while(lo<=hi){
		ll m1=(lo*2+hi)/3,m2=(lo+hi*2)/3;
		ansX=min({ansX,allSum(X,m1),allSum(X,m2)});
		if(allSum(X,m1)<=allSum(X,m2)) hi=m2-1;
		else lo=m1+1;
	}
	lo=-1e7,hi=1e7;
	ll ansY=1e12;
	while(lo<=hi){
		ll m1=(lo*2+hi)/3,m2=(lo+hi*2)/3;
		ansY=min({ansY,allSum(Y,m1),allSum(Y,m2)});
		if(allSum(Y,m1)<=allSum(Y,m2)) hi=m2-1;
		else lo=m1+1;
	}
	cout << ansX+ansY;

	
	return 0;
}
