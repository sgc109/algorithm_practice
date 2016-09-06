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
const int MAX_N = 1003;

unordered_set<long long> h;
long long g[27];
int f[220];


int main() {
	char s[MAX_N];
	gets(s);
	int n = strlen(s);
	FOR(i,26) f['a'+i] = i+1;
	int cnt = 0;
	REP(len,1,n+1) {
		FOR(i,27) {
			g[i] = i;
			FOR(j,len-1) {
				g[i] = (g[i] * 27);
				
			}
		}
		long long val = 0;
		FOR(i,len) {
			
			val = (val * 27 + f[s[i]]);
			
		}
		
		for(int i = len;;++i) {
			// printf("Hash: %lld\n",val[0]*Hash[1]+val[1]);
			if(!h.count(val)) {
				// printf("pos: %d, size: %d\n",i-len,len);
				h.insert(val);
				++cnt;
			}
			if(i >=n) break;

			val = (val - g[f[s[i-len]]]);
			val = (val*27 + f[s[i]]);
		}
	}
	printf("%d",cnt);

	return 0;
}