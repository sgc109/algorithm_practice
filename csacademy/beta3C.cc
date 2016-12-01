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

int n;
pii arr[MAX_N];
vector<pii> sorted;
int main() {
	inp1(n);
	FOR(i,n){
		int a,b;
		inp2(a,b);
		arr[i]=mp(a,b);
		sorted.pb(mp(a,i));
		sorted.pb(mp(b,i));
	}
	sort(sorted.begin(),sorted.end());
	int pos=sorted[sorted.size()/2].first;
	int idx=sorted[sorted.size()/2].second;
	ll sum=0;
	FOR(i,n){
		if(i==idx) continue;
		if(arr[i].first <= pos && pos <= arr[i].second) continue;
		if(pos < arr[i].first) sum+=arr[i].first-pos;
		else sum+=pos-arr[i].second;
	}
	printf("%lld",sum);
	return 0;
}