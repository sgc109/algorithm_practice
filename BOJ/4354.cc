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

vector<int> getPartialMatch(char S[]) {
	int n = strlen(S);
	vector<int> pi(n,0);

	int begin = 1;
	int matched = 0;
	while(begin < n) {
		if(S[matched] == S[begin + matched]) {
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

int maxOverlap(char A[], char B[]) {
	int n = strlen(A);
	int m = strlen(B);

	vector<int> pi = getPartialMatch(B);
	int begin = 1;
	int matched = 0;
	while(begin < n) {
		if(matched < m && A[begin+matched] == B[matched]) {
			++matched;
			if(begin+matched == n) return matched;
		}
		else {
			if(matched == 0) ++begin;
			else {
				begin += matched - pi[matched-1];
				matched = pi[matched-1];
			}
		}
	}
	return 0;
}

int main() {
	setbuf(stdout,NULL);
	char S[1000004];
	int n;
	while(true) {
		scanf("%s",S);
		n = strlen(S);
		if(!strcmp(S,".")) break;
		int chunk = n - maxOverlap(S,S);
		if(n % chunk == 0) printf("%d\n",n/chunk);
		else printf("%d\n", 1);
	}
	return 0;
}