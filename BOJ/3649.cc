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

const int MOD = 1000000007;
const int INF = 0x3c3c3c3c;
const long long INFL = 0x3c3c3c3c3c3c3c3c;
const int MAX_N = 1000002;

ll L;
ll legos[MAX_N];
int n;
int main() {
	while(scanf("%lld",&L)!=-1){
		bool found=false;
		L*=10000000;
		scanf("%d",&n);
		for(int i = 0; i < n; i++) scanf("%lld",legos+i);
		sort(legos,legos+n);
		for(int i = 0 ; i < n; i++) {
			ll A = legos[i];
			ll B = L-legos[i];
			if(A>B) break;
			int pos = upper_bound(legos,legos+n,B)-legos;
			pos--;
			if(pos<0||i==pos) continue;
			if(B==legos[pos]) {
				found=true;
				printf("yes %lld %lld\n",A,B);
				break;
			}
		}
		if(!found) printf("danger\n");
	}
	return 0;
}
