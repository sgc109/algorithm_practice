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
const int MAX_N = 200002;
int n,m,k;
int x,s;

int A[MAX_N],B[MAX_N];
int C[MAX_N],D[MAX_N];
int main() {
	inp3(n,m,k);
	inp2(x,s);
	FOR(i,m) inp1(A[i]);
	FOR(i,m) inp1(B[i]);
	FOR(i,k) inp1(C[i]);
	FOR(i,k) inp1(D[i]);
	ll ans = (ll)n*x;
	FOR(i,m){
		if(B[i]>s) continue;
		int idx = upper_bound(D,D+k,s-B[i])-D;
		idx--;
		if(idx>=0){
			ans = min(ans,(ll)(n-C[idx])*A[i]);
		}
		else ans = min(ans,(ll)n*A[i]);
	}
	int idx = upper_bound(D,D+k,s)-D;
	idx--;
	if(idx>=0) ans = min(ans,(ll)(n-C[idx])*x);
	printf("%lld",ans);
	return 0;
}