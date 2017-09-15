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

pii cord[3];
int main() {
	FOR(i,3){
		int x,y;
		inp2(x,y);
		cord[i]=mp(x,y);
	}
	vector<pii> ans;
	int dx = cord[0].first-cord[2].first;
	int dy = cord[0].second-cord[2].second;
	ans.pb(mp(cord[1].first-dx,cord[1].second-dy));
	ans.pb(mp(cord[1].first+dx,cord[1].second+dy));
	dx = cord[0].first-cord[1].first;
	dy = cord[0].second-cord[1].second;
	ans.pb(mp(cord[2].first+dx,cord[2].second+dy));
	printf("3\n");
	FOR(i,ans.size()){
		printf("%d %d\n",ans[i].first,ans[i].second);
	}
	return 0;
}