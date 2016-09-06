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
const int MAX_N = 1000003;

vector<int> getPartialMatch(char s[]) {
	int n = strlen(s);
	vector<int> pi(n,0);
	int begin = 1;
	int matched = 0;
	while(begin + matched < n) {
		if(s[begin+matched] == s[matched]) {
			++matched;
			pi[begin+matched-1] = matched;
		}
		else {
			if(matched ==0 ) ++begin;
			else {
				begin += matched - pi[matched-1];
				matched = pi[matched-1];
			}
		}
	}
	return pi;
}

int maxOverlap(char a[], char b[]) {
	int n = strlen(a);
	int m = strlen(b);

	vector<int> pi = getPartialMatch(b);
	int begin = 1;
	int matched = 0;
	while(begin < n) {
		if(matched < m && a[begin+matched] == b[matched]) {
			++matched;
			if(begin + matched == n) return matched;
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
	int n;
	char s[MAX_N];

	scanf("%d ",&n);
	gets(s);

	printf("%d",n - maxOverlap(s,s));

	return 0;
}