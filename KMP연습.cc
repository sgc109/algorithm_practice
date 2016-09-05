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
#define inp1(a) scanf("%d",&a)
#define inp2(a,b) scanf("%d%d",&a,&b)
#define inp3(a,b,c) scanf("%d%d%d",&a,&b,&c)
#define inp4(a,b,c,d) scanf("%d%d%d%d",&a,&b,&c,&d)

using namespace std;

typedef pair<long long, long long> pll;

const int INF = 0x3a3a3a3a;
const long long INFL = 0x3a3a3a3a3a3a3a3a;
const int MAX_N = 1000000;

vector<int> getPartialMatch(string &S) {
	int n = S.size();
	vector<int> pi(n);

	int begin = 1;
	int matched = 0;

	while(begin + matched < n) {
		if(S[matched] == S[begin+matched]) {
			++matched;
			pi[begin+matched-1] = matched;
			if(begin+matched == n) break;
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
	int n = A.size();
	int m = B.size();

	vector<int> ret;
	vector<int> pi = getPartialMatch(B);

	int begin = 0;
	int matched = 0;
	while(begin + m <= n) {
		if(matched < m && A[begin + matched] == B[matched]) {
			++matched;
			if(matched == m) ret.push_back(begin);
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
	cin >> A >> B;
	vector<int> pos = KMP(A,B);
	FOR(i,pos.size()) {
		printf("%d ",pos[i]);
	}
	return 0;
}