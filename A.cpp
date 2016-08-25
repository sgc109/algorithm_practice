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
#define REP(i,a,b) for(int i = a; i < b;++i) 
#define FOR(i,n) REP(i,0,n)
#define mp make_pair
#define pb push_back

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef pair<ll, ll> llll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<vector<int> > vvi;
typedef vector<ii> vii;
	
const int INF = 0x3a3a3a3a;
const int MAX_N = 1000001;

int a[MAX_N];

int main() {
	int n,b,d;
	scanf("%d%d%d",&n,&b,&d);
	long long cur = 0;
	long long cnt = 0;
	FOR(i,n) {
		scanf("%d",a+i);
		if(a[i] > b) continue;
		cur += a[i];
		if(cur > d) {
			++cnt;
			cur = 0;
		}
	}
	printf("%I64d",cnt);
	return 0;
}