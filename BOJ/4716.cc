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
// #include <unordered_set>
#include <set>
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

typedef pair<long long, long long> pll;
typedef vector<int> vi;
typedef vector<vector<int> > vvi;
typedef pair<int,int> pii;

const int INF = 0x3a3a3a3a;
const long long INFL = 0x3a3a3a3a3a3a3a3a;
const int MAX_N = 1000;


int main() {
	while(1) {
		int want[MAX_N], cost[MAX_N][2];
		vector<pii> diffs;
		int flowA=0,flowB=0;
		int n,cntA,cntB;
		int totalCost=0;
		inp3(n,cntA,cntB);
		if(n==0&&cntA==0&&cntB==0) break;
		FOR(i,n) {
			inp1(want[i]);
			FOR(j,2) inp1(cost[i][j]);
			diffs.pb(mp(abs(cost[i][0]-cost[i][1]),i));
			if(cost[i][0] > cost[i][1]) {
				totalCost += cost[i][1]*want[i];
				flowB+=want[i];
			}
			else {
				totalCost += cost[i][0]*want[i];
				flowA+=want[i];
			}
		}
		sort(diffs.begin(),diffs.end());
		int pos=0;

		while(flowA > cntA || flowB > cntB) {
			if(flowA > cntA) {
				if(cost[diffs[pos].second][0] > cost[diffs[pos].second][1]) {
					++pos;
					continue;
				}
				if(flowA-cntA >= want[diffs[pos].second]) {
					totalCost+=	diffs[pos].first*want[diffs[pos].second];
					flowA-=want[diffs[pos].second];
					flowB+=want[diffs[pos].second];
					++pos;
				}
				else {
					totalCost += diffs[pos].first*(flowA-cntA);
					flowB+=flowA-cntA;
					flowA-=flowA-cntA;
				}
			}
			else {
				if(cost[diffs[pos].second][1] > cost[diffs[pos].second][0]) {
					++pos;
					continue;
				}
				if(flowB-cntB >= want[diffs[pos].second]) {
					totalCost+=	diffs[pos].first*want[diffs[pos].second];
					flowB-=want[diffs[pos].second];
					flowA+=want[diffs[pos].second];
					++pos;
				}
				else {
					totalCost += diffs[pos].first*(flowB-cntB);
					flowA+=flowB-cntB;
					flowB-=flowB-cntB;
				}
			}
		}
		printf("%d\n",totalCost);
	}
	return 0;
}