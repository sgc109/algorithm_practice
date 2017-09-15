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
// #include <unordered_set>
// #include <map>
#define REP(i,a,b) for(int i = a; i < b;++i) 
#define FOR(i,n) REP(i,0,n)
#define mp make_pair
#define pb push_back
#define inp1(a) scanf("%d",&a)
#define inp2(a,b) scanf("%d%d",&a,&b)
#define inp3(a,b,c) scanf("%d%d%d",&a,&b,&c)
#define inp4(a,b,c,d) scanf("%d%d%d%d",&a,&b,&c,&d)
// #define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)

using namespace std;

typedef long long ll;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<vector<int> > vvi;
typedef pair<int,int> pii;
typedef pair<int,pair<int,int> > piii;
typedef queue<int> QU;

const int MOD = 1000000007;
const int INF = 0x3c3c3c3c;
const long long INFL = 0x3c3c3c3c3c3c3c3c;
const int MAX_N = 100005;

int pXOR[MAX_N];
int pSum[MAX_N];
int arr[MAX_N];
ll ans;
int N,A,B;
int figCnt(int pos, int num){
	if(pos<0) return 0;
	return (num?pSum[pos]:pos-pSum[pos]);
}
ll solve(int base){
	memset(pXOR,0,sizeof(pXOR));
	memset(pSum,0,sizeof(pSum));
	ll add=0;
	FOR(i,N){
		pXOR[i+1]=pXOR[i]^((arr[i]>>base)&1);
	}
	FOR(i,N){
		pSum[i+1]=pSum[i]+(pXOR[i+1]);
	}

	REP(j,1,N+1){
		int a = j-B; int b = j-A;
		add+=figCnt(b,pXOR[j]^1)-figCnt(a-1,pXOR[j]^1)+(pXOR[j]&&a<1&&b>=0);
	}
	return add;
}
int main() {
	inp3(N,A,B);
	FOR(i,N) inp1(arr[i]);
	FOR(i,31){
		ans = (ans+(solve(i)<<i))%MOD;
	}
	printf("%lld",ans);
	return 0;
}