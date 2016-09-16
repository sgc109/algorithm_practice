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
const int MAX_N = 1000000;

int n;
vector<pii> pairs;
vi ans;
int main() {
	inp1(n);
	FOR(i,2*n) {
		int a,b;
		inp2(a,b);
		pairs.pb(mp(a,b));
	}
	sort(pairs.begin(),pairs.end());
	for(int i = 0; i <2*n; i+=2) {
		if(pairs[i].first != pairs[i+1].first) {
			printf("-1");
			return 0;
		}
	}

	int pos = lower_bound(pairs.begin(),pairs.end(),mp(pairs[0].second,pairs[1].second)) - pairs.begin();
	if(pos == pairs.size()) {
		pos = lower_bound(pairs.begin(),pairs.end(),mp(pairs[1].second,pairs[0].second)) - pairs.begin();
		if(pos == pairs.size()) {
			printf("-1");
			return 0;
		}
		check[pos] = 1;
		++checkCnt;
		ans.pb(pairs[0].first);
		ans.pb(pairs[1].second);
		ans.pb(pairs[0].second);
	}
	else {
		if(check[pos] == 1) {
			printf("-1");
			return 0;
		}
		check[pos] = 1;
		++checkCnt;
		ans.pb(pairs[0].first);
		ans.pb(pairs[0].second);
		ans.pb(pairs[1].second);
	}

	while(checkCnt < 2*n) {
		int findNum = ans[ans.size()-2];
		int pos = lower_bound(pairs.begin(),pairs.end(),mp(findNum,0)) - pairs.begin();
		if(pos == pairs.size()) {
			printf("-1");
			return 0;
		}
		bool found = false;
		if(check[pos] == 1) {
			if(pos-1 >= 0) {
				if(pairs[pos-1].first == findNum && check[pos-1] == 0) {
					found = true;
					check[pos-1] = 1;
					++checkCnt;
					ans.pb(pairs[pos-1].second);
					// printf("1!%d\n",findNum);
				}
			}
			if(pos+1 < 2*n) {
				if(pairs[pos+1].first == findNum && check[pos+1] == 0) {
					found = true;
					check[pos+1] = 1;
					++checkCnt;
					ans.pb(pairs[pos+1].second);
					// printf("2!%d\n",findNum);
				}
			}
			if(!found) {
				printf("-1");
				return 0;
			}
		}
		else {
			check[pos] = 1;
			++checkCnt;
			ans.pb(pairs[pos].second);
		}
		int pos2 = lower_bound(pairs.begin(),pairs.end(),mp(ans[ans.size()-2],ans[ans.size()-1]))-pairs.begin();
		if(pos2==pairs.size()) {
			printf("-1");
			return 0;
		}
		if(check[pos2] == 0){
			check[pos2]=1;
			++checkCnt;	
		}
		

	}
	FOR(i,ans.size()-2) {
		printf("%d ",ans[i]);
	}
	return 0;
}