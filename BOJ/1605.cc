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
const int MAX_N = 200003;

const int CNT_MOD = 2;
const long long Hash[CNT_MOD] = {1000000007, 1000000009};

char S[MAX_N];
unordered_set<long long> h;
long long g[26][CNT_MOD];
int n;

bool check(int x) {
	h.clear();

	FOR(i,26) {
		FOR(k,CNT_MOD) g[i][k] = 'a' + i;
		FOR(j,x-1) {
			FOR(k,CNT_MOD) {
				g[i][k] = (g[i][k] * 257) % Hash[k];
			}
		}
	}
	long long val[CNT_MOD] = {0,};
	FOR(i,x) {
		FOR(k,CNT_MOD) {
			val[k] = (val[k] * 257 + S[i]) % Hash[k];
		}
	}
	FOR(i,n-x+1) {
		if(h.count(val[0]*Hash[0]+val[1])) return true;
		h.insert(val[0]*Hash[0]+val[1]);
		
		if(i != n-x) {
			FOR(k,CNT_MOD) {
				val[k] = (val[k] - g[S[i]-'a'][k] + Hash[k]) % Hash[k];
				val[k] = (val[k] * 257) % Hash[k];
				val[k] = (val[k] + S[i+x]) % Hash[k];
			}
		}
	}

	return false;
}

int main() {
	gets(S);
	n = strlen(S);
	int left = 0, right = n;
	while(left +1 < right) {
		int mid = (left + right) >> 1;
		if(check(mid)) left = mid;
		else right = mid;
	}

	printf("%d",left);


	return 0;
}