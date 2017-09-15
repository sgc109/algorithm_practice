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
#define REP(i,a,b) for(int i = a; i < b;++i)
#define FOR(i,n) REP(i,0,n)
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

int N,M,K;
int color[52];
int main() {
	memset(dp,-1,sizeof(dp));
	inp1(M);
	FOR(i,M) {
		inp1(color[i]);
		N+=color[i];
	}
	inp1(K);
	double ans=0;
	FOR(i,M){
		if(color[i]<K) continue;
		double cnt=1;
		FOR(j,K){
			cnt*=(double)(color[i]-j)/(N-j);
		}
		ans+=cnt;
	}
	printf("%.10lf",ans);
	return 0;
}

/*
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
#define REP(i,a,b) for(int i = a; i < b;++i)
#define FOR(i,n) REP(i,0,n)
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

int N,M,K;
int color[52];
ll dp[52][52];
ll nCr(int n, int r){
	if(r<0) return 0;
	if(n==r||r==0) return 1;
	if(r==1) return n;
	ll& cache = dp[n][r];
	if(cache!=-1) return cache;
	return cache=nCr(n-1,r)+nCr(n-1,r-1);
}
int main() {
	memset(dp,-1,sizeof(dp));
	inp1(M);
	FOR(i,M) {
		inp1(color[i]);
		N+=color[i];
	}
	inp1(K);
	ll num=0;
	FOR(i,M){
		ll cnt=1;
		FOR(j,K){
			cnt*=nCr(N-j,color[i]-j);
		}
		num+=cnt;
	}
	printf("%.10lf",(double)num/nCr(N,K));
	return 0;
}
*/