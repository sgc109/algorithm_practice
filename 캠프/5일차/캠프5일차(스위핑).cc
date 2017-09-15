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

int N;
double myX1[100002],myY1[100002];
double myX2[100002],myY2[100002];
vector<pair<double,int>> v;
int main() {
	inp1(N);
	FOR(i,N) {
		scanf("%lf%lf%lf%lf",&myX1[i],&myY1[i],&myX2[i],&myY2[i]);
		int tmp;
		if(myY1[i]/myX1[i]<myY2[i]/myX2[i]) tmp=1;
		else tmp=0; 
		v.pb(mp(myY1[i]/myX1[i],tmp^1));
		v.pb(mp(myY2[i]/myX2[i],tmp));
	}
	sort(v.begin(),v.end());
	int ans=0;
	int line=0;
	FOR(i,v.size()){
		if(!v[i].second) line++;
		else line--;
		ans=max(ans,line);
	}
	printf("%d",ans);

	return 0;
}
