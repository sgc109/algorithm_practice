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

int N;
int D[1<<16][16];
char W[17][17];
int bitCnt(int x){
	int ret=0;
	for(;x;x-=x&-x,ret++){}
	return ret;
}
vi bi[1<<16];
void calcBi(int here){
	int cnt1=bitCnt(here);
	for(int p=here;p;p=(p-1)&here){
		int cnt2=bitCnt(p);
		if(cnt1==cnt2*2) {
			bi[here].pb(p);
			if(!bi[p].size()) calcBi(p);
		}
	}
}
ll go(int S, int id){
	if((S&(1<<id))==0) return 0;
	if(bitCnt(S)==1) return 1;
	ll& cache=D[S][id];
	if(cache!=-1) return cache;
	ll ret=0;
	for(auto s1 : bi[S]){
		int s2=S-s1;
		FOR(enemy,N){
			if(W[id][enemy]=='N') continue;
			ret+=go(s1,id)*go(s2,enemy)*2;
		}
	}
	return cache=ret;
}
int main() {
	memset(D,-1,sizeof(D));
	inp1(N);
	FOR(i,N) scanf("%s",W[i]);
	calcBi((1<<N)-1);
	FOR(i,N) printf("%lld ",go((1<<N)-1,i));
	return 0;
}
