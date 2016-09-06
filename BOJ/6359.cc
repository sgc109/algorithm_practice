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
#include <unordered_set>
#include <set>
#include <map>
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

const int INF = 0x3a3a3a3a;
const long long INFL = 0x3a3a3a3a3a3a3a3a;
const int MAX_N = 101;

int divisorCnt[101];

int main() {
	REP(i,1,101) {
		for(int j = i; j <=100; j += i) {
			++divisorCnt[j];
		}
	}

	int T;
	inp1(T);
	while(T--) {
		int n;
		inp1(n);
		int ans = 0;
		REP(i,1,n+1) {
			if(divisorCnt[i] %2 ==1) ++ans;
		}
		printf("%d\n",ans);
	}

	return 0;
}