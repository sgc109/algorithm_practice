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
#include <deque>
// #include <unordered_set>
// #include <map>
#define REP(i,a,b) for(int i = a; i <= b;++i)
#define FOR(i,n) REP(i,0,n-1)
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

const double EPSILON = 1e-9;
const double PI = acos(0.0)*2;
const int MOD = 1000000007;
const int INF = 0x3c3c3c3c;
const long long INFL = 0x3c3c3c3c3c3c3c3c;
const int MAX_N = 102;

int cnt,ans;
int n;
vector<pii> v;
int main() {
	inp1(n);
	FOR(i,n){
		int l,r;
		inp2(l,r);
		if(l>r) swap(l,r);
		v.pb(mp(l,0));
		v.pb(mp(r,1));
	}
	sort(v.begin(),v.end());
	int prev=v[0].first;
	FOR(i,v.size()){
		int se = v[i].second;
		int pos = v[i].first;
		if(cnt>0) ans+=pos-prev;
		if(se) cnt--;
		else cnt++;
		prev=pos;
	}
	printf("%d",ans);
	return 0;
}
