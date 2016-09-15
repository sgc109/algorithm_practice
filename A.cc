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

int main() {
	long long l1,r1,l2,r2,k;
	scanf("%I64d%I64d%I64d%I64d%I64d",&l1,&r1,&l2,&r2,&k);
	if(r1 < l2 || r2 < l1) {
		printf("0");
		return 0;
	}
	long long ans;
	if(l2 <= l1 && l1 <= r2 && r2 <= r1) {
		ans = r2-l1+1;
		if(l1 <= k && k <= r2) --ans;
	}
	else if(l1 <= l2 && l2 <= r1 && r1 <= r2) {
		ans = r1-l2+1;
		if(l2 <= k && k <= r1) --ans;
	}
	else if(l1 <= l2 && r2 <= r1) {
		ans = r2-l2+1;
		if(l2<=k && k <= r2) --ans;
	}
	else if(l2 <= l1 && r1 <= r2) {
		ans = r1-l1+1;
		if(l1 <= k && k <= r1) --ans;
	}
	printf("%I64d",ans);
	return 0;
}