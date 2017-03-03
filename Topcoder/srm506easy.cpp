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

class SlimeXSlimesCity{
public:
	ll pSum[53];
	int pop[53];
	int N;
	int dp[53][53][53];
	ll PSUM(int l, int r){return pSum[r]-pSum[l-1];}
	int go(int l, int r, int id){
		if(id<l || r<id) return 0;
		if(l==r) return 1;
		int& cache = dp[l][r][id];
		if(cache !=-1) return cache;
		int ret=0;
		REP(k,l,r-1){
			if((go(l,k,id)&&PSUM(l,k)>=PSUM(k+1,r))||(go(k+1,r,id)&&PSUM(l,k)<=PSUM(k+1,r))) ret=1;
		}
		return cache = ret;
	}
	int solve(){
		FOR(i,N) pSum[i+1] = pSum[i]+pop[i];
		memset(dp,-1,sizeof(dp));
		int ans=0;
		REP(i,1,N) ans+=go(1,N,i);
		return ans;
	}
	int merge(vector <int> population){
		N = population.size();
		FOR(i,N) pop[i] = population[i];
		return solve();
	}
};
int main() {
	SlimeXSlimesCity obj;
	cout << obj.merge(
{{8388608, 1024, 131072, 4, 268435456, 4096, 262144, 65536, 16384, 67108864, 33554432, 16777216, 8, 2097152, 128, 1, 32, 32768, 64, 134217728, 524288, 4194304, 2, 512, 8192, 256, 536870912, 2048, 1048576, 16, 31053630, 558490010, 549284480, 339007660, 490637317, 919639275, 114667712, 279564429, 254418094, 566351725, 218125422, 724033571, 908038454, 548245735, 320625104, 99884110, 912249545, 982895294, 242429798, 645592008}}
);
	return 0;
}
