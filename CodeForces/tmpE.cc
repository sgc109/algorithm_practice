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
#include <cassert>
// #include <unordered_set>
#include <map>
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

int slices[10000002];
ll cache[10000002];
int n,k;

void NO(){
	printf("-1");
	exit(0);
}

bool ok(int limit){
	// memset(cache,0,sizeof(cache));
	ll acc=0;
	for(int i = 1e7; i >=limit; i--){
		if(slices[i]+cache[i]<=0) continue;
		if(i/2<limit) {
			acc+=slices[i]+cache[i];
		}
		else {
			cache[i/2] += slices[i]+cache[i];
			cache[(i+1)/2] += slices[i]+cache[i];
		}
		cache[i]=0;
	}
	return acc>=k;
}

int main() {
	inp2(n,k);
	FOR(i,n) {
		int a;
		inp1(a);
		slices[a]++;
	}
	int lo=1,hi=1e7+1;
	while(lo<hi){
		int mid = (lo+hi)>>1;
		if(ok(mid)) lo=mid+1;
		else hi=mid;
	}
	lo--;
	if(lo<1) NO();
	printf("%d",lo);
	
	return 0;
}