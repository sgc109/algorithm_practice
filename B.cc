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

const int MOD = 1000000007;
const int INF = 0x3c3c3c3c;
const long long INFL = 0x3c3c3c3c3c3c3c3c;
const int MAX_N = 100002;

int cnt[MAX_N];
int f[MAX_N];
int b[MAX_N];
vector<pii> sorted;

void NO(){
	printf("Impossible");
	exit(0);
}
int main() {
	int n,m;
	inp2(n,m);
	FOR(i,n) {
		inp1(f[i]);
		cnt[f[i]]++;
		sorted.pb(mp(f[i],i));
	}
	sort(sorted.begin(),sorted.end());
	bool amb = false;
	vi ans;
	FOR(i,m) {
		inp1(b[i]);
		if(cnt[b[i]]==0) NO();
		else if(cnt[b[i]]>1) amb=true;
		else {
			int pos = lower_bound(sorted.begin(),sorted.end(),mp(b[i],-1))-sorted.begin();
			ans.pb(sorted[pos].second+1);
		}
	}
	if(amb) {
		printf("Ambiguity");
		return 0;
	}
	printf("Possible\n");
	FOR(i,ans.size()){
		printf("%d ",ans[i]);
	}
	


	return 0;
}