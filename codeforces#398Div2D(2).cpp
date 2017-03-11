#include <bits/stdc++.h>
#define REP(i,a,b) for(int i=a;i<=b;++i)
#define FOR(i,n) for(int i=0;i<n;++i)
#define pb push_back
#define all(v) (v).begin(),(v).end()
#define sz(v) ((int)(v).size())
#define inp1(a) scanf("%d",&a)
#define inp2(a,b) scanf("%d%d",&a,&b)
#define inp3(a,b,c) scanf("%d%d%d",&a,&b,&c)
#define inp4(a,b,c,d) scanf("%d%d%d%d",&a,&b,&c,&d)
#define inp5(a,b,c,d,e) scanf("%d%d%d%d%d",&a,&b,&c,&d,&e)
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
typedef vector<int> vi;	
typedef vector<ll> vl;
typedef pair<int,int> pii;
typedef vector<pii> vii;
typedef vector<pll> vll;
typedef vector<vector<int> > vvi;
typedef pair<int,pair<int,int> > piii;
typedef vector<piii> viii;
const double EPSILON = 1e-9;
const double PI = acos(-1);
const int MOD = 1e9+7;
const int INF = 0x3c3c3c3c;
const long long INFL = 0x3c3c3c3c3c3c3c3c;
const int MAX_N = 102;

int n,m,k;
int fridge[1000003];
int store[1000003];
int milks[2000003];
pii sorted[1000003];
bool check(int t){
	merge(fridge,fridge+n,store+m-t,store+m,milks);
	int day = 0, milk = 0;
	for(; milk < n + t; day++){
		for(int i = 0 ; i < k && milk < n + t; i++, milk++){
			if(milks[milk] < day) return false;
		}
	}
	return true;
}
int main() {
	inp3(n,m,k);
	FOR(i,n) inp1(fridge[i]);
	FOR(i,m) inp1(store[i]), sorted[i] = {store[i],i+1};
	sort(fridge,fridge+n);
	sort(sorted,sorted+m);
	FOR(i,m) store[i] = sorted[i].first;

	int lo=0,hi=m+1;
	while(lo<hi){
		int mid = (lo+hi)>>1;
		if(check(mid)) lo = mid+1;
		else hi=mid;
	}
	printf("%d\n",lo-1);
	if(lo-1>0) FOR(i,lo-1) printf("%d ", sorted[m-i-1].second);
	return 0;
}
