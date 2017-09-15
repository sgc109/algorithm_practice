#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <queue>
#include <utility>
#include <stack>
#include <string.h>
#include <string>
#include <stdlib.h>
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
const int MAX_V = 64;

char map[MAX_V][MAX_V];

int solve(int i, int j, int n, string &ans) {
	if(n == 1) {
		ans += map[i][j];
		return map[i][j] - '0';
	}
	ans += "(";
	int dir4[4];
	int cnt[3] = {0,};
	dir4[0] = solve(i,j,n/2,ans);
	++cnt[dir4[0]];
	dir4[1] = solve(i,j+n/2,n/2,ans);
	++cnt[dir4[1]];
	dir4[2] = solve(i+n/2,j,n/2,ans);
	++cnt[dir4[2]];
	dir4[3] = solve(i+n/2,j+n/2,n/2,ans);
	++cnt[dir4[3]];
	if(cnt[0] == 4) {
		ans.resize(ans.size()-5);
		ans += "0";
		return 0;
	}
	else if(cnt[1] == 4) {
		ans.resize(ans.size()-5);
		ans += "1";
		return 1;
	}

	ans += ")";
	return 2;
}

int main() {
	int n;
	scanf("%d",&n);
	FOR(i,n) {
		scanf("%s",map[i]);
	}
	string ans="";
	solve(0,0,n,ans);
	printf("%s",ans.c_str());
	return 0;
}