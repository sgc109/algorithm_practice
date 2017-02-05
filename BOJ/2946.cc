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
const int MAX_N = 102;

bool cmp(pii& A, pii& B){
	return A.first<B.first;
}
int main() {
	int T;
	inp1(T);
	while(T--){
		vi A;
		vector<pii> P;
		int n;
		inp1(n);
		FOR(i,n){
			int a,b;
			inp2(a,b);
			P.pb(mp(a,b));
		}
		sort(P.begin(),P.end(),cmp);
		int limit=n+1;
		int ans=0;
		FOR(i,n){
			if(P[i].second<limit) ans++;
			limit=min(limit,P[i].second);
		}
		printf("%d\n",ans);
	}
	return 0;
}
