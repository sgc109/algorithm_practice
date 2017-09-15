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
typedef vector<int> vi;
typedef vector<vector<int> > vvi;

const int INF = 0x3a3a3a3a;
const long long INFL = 0x3a3a3a3a3a3a3a3a;
const int MAX_N = 1000000;

int n;
int a[202];
int lis[202];
int pos[202];
int from[202];

int main() {
	inp1(n);
	FOR(i,n) inp1(a[i]);

	int size=0;
	FOR(i,n){
		int lower = lower_bound(lis+1,lis+1+size,a[i]) - lis;
		if(lower > size) size = lower;
		lis[lower] = a[i];
		pos[lower] = i;
		from[i] = pos[lower-1];
	}
	printf("%d",n-size);
	return 0;
}