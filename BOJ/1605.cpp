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

const long long Hash = 10000000007;

char S[MAX_N];
long long f[220];
unordered_set<long long> h;
long long g[26];
int n;

bool check(int x) {
	h.clear();

	FOR(i,26) {
		g[i] = i;
		FOR(j,x-1) {
			g[i] = (g[i] * 26) % Hash;
		}
	}
	long long val = 0;
	string str;
	FOR(i,x) {
		val = (val * 26 + f[S[i]]) % Hash;
		str += S[i];
	}
	FOR(i,n-x+1) {
		if(h.count(val)) return true;
		h.insert(val);
		
		if(i != n-x) {
			val = (val - g[f[S[i]]] + Hash) % Hash;
			val = (val * 26) % Hash;
			val = (val + f[S[i+x]]) % Hash;
			str = str.substr(1,str.size()) + S[i+x];
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