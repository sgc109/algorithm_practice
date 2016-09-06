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

int main() {
	int e,s,m;
	scanf("%d%d%d",&e,&s,&m);
	int year = 1;
	while(1) {
		if(e == 1 && s == 1 && m == 1) break;

		--e;--s;--m;
		if(!e) e = 15;
		if(!s) s = 28;
		if(!m) m = 19;
		++year;
	}

	printf("%d",year);

	return 0;
}