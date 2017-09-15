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

int maxP[200002];
int minP[200002];
vi prices[200002];
vector<pii> ranking;
int isHome[200002];
int main() {
	// freopen("output.txt","wb",stdout);
	int n;
	inp1(n);
	FOR(i,n){
		int a,b;
		inp2(a,b);
		a--;
		maxP[a] = max(maxP[a],b);
		minP[a] = min(minP[a],b);
		prices[a].pb(b);
	}
	FOR(i,200002){
		if(maxP[i]!=0) ranking.pb(mp(maxP[i],i));
	}
	sort(ranking.begin(),ranking.end());
	int q;
	inp1(q);
	FOR(i,q){
		int k;
		inp1(k);
		vi goHome;
		FOR(j,k){
			int a;
			inp1(a);
			a--;
			goHome.pb(a);
			isHome[a]=1;
		}
		int j;
		for(j=ranking.size()-1;j>=0;j--){
			int num = ranking[j].second;
			if(maxP[num]==0 || isHome[num]) continue;
			break;
		}
		int winner;
		if(j>=0) winner = ranking[j].second;
		else {
			printf("0 0\n");
			FOR(j,goHome.size()) isHome[goHome[j]]=0;
			continue;
		}

		for(j=ranking.size()-1;j>=0;j--){
			int num = ranking[j].second;
			if(maxP[num]==0 || isHome[num] || num==winner) continue;
			break;
		}
		int limit;
		if(j<0) limit = 0;
		else limit = ranking[j].first;
		
		int idx = lower_bound(prices[winner].begin(),prices[winner].end(),limit)-prices[winner].begin();
		printf("%d %d\n",winner+1,prices[winner][idx]);

		FOR(j,goHome.size()) isHome[goHome[j]]=0;
	}
	return 0;
}