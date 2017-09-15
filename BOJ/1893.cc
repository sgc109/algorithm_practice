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
const int MAX_N = 1000000;

int f[220];
char A[63], W[50001], S[500001];
int aLen;
vector<int> pi;

void getPartialMatch(char s[]) {
	int n = strlen(s);
	pi = vector<int>(n,0);

	int begin = 1;
	int matched = 0;
	while(begin < n) {
		if(s[begin+matched] == s[matched]) {
			++matched;
			pi[begin+matched-1] = matched;
		}
		else {
			if(matched == 0) ++begin;
			else {
				begin += matched - pi[matched - 1];
				matched = pi[matched - 1];
			}
		}
	}
}

int KMP(char H[], char N[], int shift) {
	int ret = 0;

	int n = strlen(H);
	int m = strlen(N);
	int matched = 0;
	int begin = 0;
	while(begin + m <= n) {
		if(matched < m && A[(f[H[begin+matched]]-shift+aLen)%aLen] == N[matched]) {
			++matched;
			if(matched == m) {
				++ret;
				if(ret > 1) return ret;
			}
		}
		else {
			if(matched == 0) ++begin;
			else {
				begin += matched - pi[matched-1];
				matched = pi[matched-1];
			}
		}
	}
	return ret;
}

int main() {
	int t;
	scanf("%d ",&t);
	while(t--) {
		gets(A);gets(W);gets(S);
		aLen = strlen(A);
		vector<int> ans;
		FOR(i,aLen) f[A[i]] = i;
		getPartialMatch(W);
		FOR(shift,aLen) {
			int appear = KMP(S,W,shift);
			if(appear == 1) ans.pb(shift);
		}
		if(ans.size() == 0) printf("no solution\n");
		else if(ans.size() == 1) printf("unique: %d\n",ans[0]);
		else {
			printf("ambiguous:");
			FOR(i,ans.size()) {
				printf(" %d",ans[i]);
			}
			putchar('\n');
		}
	}
	return 0;
}