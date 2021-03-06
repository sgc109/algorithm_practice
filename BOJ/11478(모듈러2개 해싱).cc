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

const long long Hash[2] = {1000000007, 1000000009};
unordered_set<long long> h;
long long g[27][2];
int f[220];


int main() {
	char s[MAX_N];
	gets(s);
	int n = strlen(s);
	FOR(i,26) f['a'+i] = i+1;
	int cnt = 0;
	REP(len,1,n+1) {
		FOR(i,27) {
			g[i][0] = i; g[i][1] = i;
			FOR(j,len-1) {
				FOR(k,2) {
					g[i][k] = (g[i][k] * 27) % Hash[k];
				}
			}
		}
		long long val[2] = {0,};
		FOR(i,len) {
			FOR(k,2) {
				val[k] = (val[k] * 27 + f[s[i]]) % Hash[k];
			}
		}
		
		for(int i = len;;++i) {
			if(!h.count(val[0]*Hash[1]+val[1])) {
				h.insert(val[0]*Hash[1]+val[1]);
				++cnt;
			}
			if(i >=n) break;

			FOR(k,2) {
				val[k] = (val[k] - g[f[s[i-len]]][k] + Hash[k]) % Hash[k];
				val[k] = (val[k]*27 + f[s[i]]) %Hash[k];
			}
		}
	}
	printf("%d",cnt);

	return 0;
}