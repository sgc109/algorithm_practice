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
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)

using namespace std;

typedef long long ll;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<vector<int> > vvi;
typedef pair<int,int> pii;
typedef pair<int,pair<int,int> > piii;
typedef queue<int> QU;

const int INF = 0x3c3c3c3c;
const long long INFL = 0x3c3c3c3c3c3c3c3c;
const int MAX_N = 1002;

int ans[MAX_N];
int main() {
	int n,k,l,r,sall,sk;
	inp3(n,k,l);
	inp3(r,sall,sk);
	FOR(i,k){
		ans[i]=sk/k;
	}
	int rest = sk%k;
	for(int i=0;i<k,rest>0;++i){
		ans[i]++;
		rest--;
	}
	if(n!=k){
		rest = sall-sk;
		REP(i,k,n+1){
			ans[i]=rest/(n-k);
		}
		rest = rest%(n-k);
		for(int i=k;i<n+1,rest>0;++i){
			ans[i]++;
			rest--;
		}
	}
	FOR(i,n) printf("%d ",ans[i]);
	return 0;
}