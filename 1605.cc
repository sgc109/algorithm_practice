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
const int MAX_N = 200003;

const int CNT_MOD = 2;
const long long Hash[CNT_MOD] = {1000000007, 1000000009};

char S[MAX_N];
long long f[220];
unordered_set<long long> h[CNT_MOD];
long long g[26][CNT_MOD];
int n;

bool check(int x) {
	FOR(i,CNT_MOD) {
		h[i].clear();
	}

	FOR(i,26) {
		FOR(k,CNT_MOD) g[i][k] = i;
		FOR(j,x-1) {
			FOR(k,CNT_MOD) {
				g[i][k] = (g[i][k] * 26) % Hash[k];
			}
		}
	}
	long long val[CNT_MOD] = {0,};
	FOR(i,x) {
		FOR(k,CNT_MOD) {
			val[k] = (val[k] * 26 + f[S[i]]) % Hash[k];
		}
	}]
	FOR(i,n-x+1) {
		FOR(k,CNT_MOD) {
			if(!h[k].count(val[k])) break;
			if(k==CNT_MOD-1) return true;
		}
		FOR(k,CNT_MOD) {
			if(!h[k].count(val[k])) h[k].insert(val[k]);
		}
		
		if(i != n-x) {
			FOR(k,CNT_MOD) {
				val[k] = (val[k] - g[f[S[i]]][k] + Hash[k]) % Hash[k];
				val[k] = (val[k] * 26) % Hash[k];
				val[k] = (val[k] + f[S[i+x]]) % Hash[k];
			}
		}
	}

	return false;
}

int main() {
	FOR(i,26) {
		f['a'+i] = i;
	}
	scanf("%d ",&n);
	gets(S);
	int left = 0, right = n;
	while(left +1 < right) {
		int mid = (left + right) >> 1;
		if(check(mid)) left = mid;
		else right = mid;
	}

	printf("%d",left);


	return 0;
}