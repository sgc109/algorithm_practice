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
typedef vector<vector<int> > vvi;
typedef pair<int,int> pii;
typedef pair<int,pair<int,int> > piii;
typedef queue<int> QU;

const int INF = 0x3c3c3c3c;
const long long INFL = 0x3c3c3c3c3c3c3c3c;
const int MAX_N = 10002;
const int MAX_M = 500002;


int n,m,q;
ll maxBand[MAX_N];
int main() {
	// freopen("output.txt","w",stdout);
	int T;
	inp1(T);
	while(T--){
		memset(maxBand,-1,sizeof(maxBand));
		pair<ll,pii> edges[MAX_M];
		inp2(n,m);
		FOR(i,m){
			int a,b;
			ll c;
			inp2(a,b);
			scanf("%lld",&c);
			--a;--b;
			edges[i] = mp(-c,mp(a,b));
		}
		sort(edges,edges+m);
		FOR(i,m){
			int a = edges[i].second.first;
			int b = edges[i].second.second;
			ll c = -edges[i].first;
			// printf("a:%d, b:%d, c:%d\n",a,b,c);
			maxBand[a] = max(maxBand[a], c);
			maxBand[b] = max(maxBand[b], c);
		}
		inp1(q);
		ll ans=0;
		FOR(i,q){
			int a,b;
			inp2(a,b);
			--a;--b;
			ans+=min(maxBand[a],maxBand[b]);
		}
		printf("%lld\n",ans);
	}
	return 0;
}