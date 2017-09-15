#include <bits/stdc++.h>
#define REP(i,a,b) for(int i=a;i<=b;++i)
#define FOR(i,n) for(int i=0;i<n;++i)
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

int T,N,t;
ll R;
ll Xs[53],Ys[53];
vector<pair<ll,ll> > v;
bool inRange(ll xx, ll yy, ll ldX, ll ldY){
	return ldX<=xx&&xx<=ldX+R&&ldY<=yy&&yy<=ldY+R;
}
int cntInRec(pll A, pll B){
	int ret=0;
	FOR(i,N){
		bool a=inRange(Xs[i],Ys[i],A.first,A.second);
		bool b=inRange(Xs[i],Ys[i],B.first,B.second);
		if(a||b) ret++;
	}
	return ret;
}
int main() {
	for(inp1(T),t=0;T-t;t++){
		v.clear();
		inp1(N);scanf("%lld",&R);
		FOR(i,N) scanf("%lld%lld",Xs+i,Ys+i);
		FOR(i,N) FOR(j,N) v.pb({Xs[i],Ys[j]});
		int ans=0;
		FOR(i,v.size()){
			FOR(j,v.size()){
				ans=max(ans,cntInRec(v[i],v[j]));
			}
		}
		printf("Case #%d: %d\n",t+1,ans);
	}
	return 0;
}
