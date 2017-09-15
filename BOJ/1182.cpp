#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <queue>
#include <utility>
#include <stack>
#include <string.h>
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
const int MAX_V = 1000000;

int a[22];

int n,s;
int cnt;

void solve(int sum, int pos) {
	if(pos == n) {
		cnt += (sum == s);
		return;
	}
	solve(sum + a[pos], pos+1);
	solve(sum, pos+1);
}

int main() {
	cnt = 0;
	scanf("%d%d",&n,&s);
	FOR(i,n) {
		scanf("%d",a+i);
	}

	solve(0, 0);
	if(s == 0) --cnt;
	printf("%d",cnt);


	return 0;
}