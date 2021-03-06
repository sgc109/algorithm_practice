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
const int MAX_N = 1000000;

int main() {
	freopen("output.txt","w",stdout);
	int T;
	inp1(T);
	while(T--){
		ll x,y;
		scanf("%lld%lld",&x,&y);
		++x;
		ll bit=1;
		ll ans=0;
		FOR(i,62){
			ll start = x/bit*bit;
			if(start<x) start+=bit;
			ll end = y/bit*bit;
			if(start<=end) ans += (end-start)/bit+1;
			bit<<=1;
		}
		printf("%lld\n",ans);
	}
	return 0;
}