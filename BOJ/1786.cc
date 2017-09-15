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

vector<int> getPartialMatch(string &S) {
	int n = S.size();
	vector<int> pi(n,0);

	int begin = 1;
	int matched = 0;
	while(begin + matched < n) {
		if(S[begin+matched] == S[matched]) {
			++matched;
			pi[begin+matched-1] = matched;
		}
		else {
			if(matched == 0) ++begin;
			else {
				begin += matched - pi[matched-1];
				matched = pi[matched-1];
			}
		}
	}
	return pi;
}

vector<int> KMP(string &A, string &B) {
	vector<int> ret;
	int n = A.size();
	int m = B.size();

	vector<int> pi = getPartialMatch(B);
	int begin = 0;
	int matched = 0;
	while(begin + m <= n) {
		if(matched < m && A[begin+matched] == B[matched]) {
			++matched;
			if(matched == m) ret.pb(begin+1);
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
	string A,B;
	getline(cin, A);
	getline(cin, B);
	vector<int> ans = KMP(A,B);
	printf("%d\n",ans.size());
	FOR(i,ans.size()) {
		printf("%d\n",ans[i]);
	}
	
	return 0;
}