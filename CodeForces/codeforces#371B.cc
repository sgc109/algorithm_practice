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

int a[100002];
int n;
vi v;
int main() {
	inp1(n);
	FOR(i,n) scanf("%d",a+i);
	sort(a,a+n);
	int minn = INF, maxx = -1, cntNum = 0;
	FOR(i,n) {
		if(i==0) {
			++cntNum;
			v.pb(a[i]);
		}
		else {
			if(a[i] != a[i-1]) {
				++cntNum;
				v.pb(a[i]);
			}
		}

	}
	sort(v.begin(),v.end());
	if(v.size() > 3) {
		printf("NO");
		return 0;
	}

	if(v.size() < 3) {
		printf("YES");
		return 0;
	}

	if(v[0]+v[2] == v[1]*2) {
		printf("YES");
	}
	else printf("NO");
	return 0;
}