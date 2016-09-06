#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <queue>
#include <utility>
#include <stack>
#include <cstring>
#include <cstdlib>
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
	int n,m;
	scanf("%d%d",&n,&m);
	bool bnw = true;
	FOR(i,n) {
		FOR(j,m) {
			char c;
			scanf(" %c",&c);
			if(c != 'B' && c != 'W' && c != 'G') bnw = false;
		}
	}
	if(bnw) printf("#Black&White");
	else printf("#Color");
	return 0;
}