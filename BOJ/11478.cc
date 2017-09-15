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

struct Compare {
	vector<int>& group;
	int t;
	Compare(vector<int>& _group, int _t) : group(_group), t(_t) {}
	bool operator () (int a, int b) {
		if(group[a] != group[b]) return group[a] < group[b];
		else return group[a+t] < group[b+t];
	}
};

vector<int> getSuffixArray(string& s) {
	int n = s.size();
	vector<int> perm(n);
	FOR(i,n) perm[i] = i;
	vector<int> group(n+1);
	FOR(i,n) group[i] = s[i];
	group[n] = -1;
	int t = 1;
	while(t < n) {
		Compare compare(group,t);
		sort(perm.begin(),perm.end(),compare);
		/*FOR(i,n) 
			printf("%d ",perm[i]);
		printf("\n");*/
		t*=2;
		if(t >= n) break;

		vector<int> newGroup(n+1);
		newGroup[n]=-1;
		newGroup[perm[0]] = 0;
		REP(i,1,n) {
			if(compare(perm[i-1],perm[i])) newGroup[perm[i]] = newGroup[perm[i-1]] + 1;
			else newGroup[perm[i]] = newGroup[perm[i-1]];
		}
		group = newGroup;
	}

	return perm;
}

int n;
string s;

int cntCommonPrefix(int a, int b) {
	int ret = 0;
	while(a < n && b < n && s[a] == s[b]) {
		++a;++b;++ret;
	}

	return ret;
}

int cntPartialString(string& s) {
	int cnt = 0;
	vector<int> suffixArray = getSuffixArray(s);
	cnt += s.size() - suffixArray[0];
	REP(i,1,n) {
		int cp = cntCommonPrefix(suffixArray[i-1],suffixArray[i]);
		cnt += s.size() - suffixArray[i] - cp;
	}
	return cnt;
}

int main() {
	cin >> s;
	n = s.size();
	printf("%d",cntPartialString(s));
	return 0;
}