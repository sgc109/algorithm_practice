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

char seat[1001][4];

int main() {
	int n;
	scanf("%d ",&n);
	FOR(i,n) {
		scanf("%c",&seat[i][0]);
		scanf("%c",&seat[i][1]);
		getchar();
		scanf("%c",&seat[i][2]);
		scanf("%c ",&seat[i][3]);
	}
	bool ans = false;
	FOR(i,n) {
		if(seat[i][0] == 'O' && seat[i][1] == 'O') {
			seat[i][0] = '+';
			seat[i][1] = '+';
			ans = true;
			break;
		}
		if(seat[i][2] == 'O' && seat[i][3] == 'O') {
			seat[i][2] = '+';
			seat[i][3] = '+';
			ans = true;
			break;	
		}
	}

	if(ans) {
		printf("YES\n");
		FOR(i,n) {
			FOR(j,2) printf("%c",seat[i][j]);
			printf("|");
			FOR(j,2) printf("%c",seat[i][j+2]);
			printf("\n");
		}
	}
	else printf("NO");
	return 0;
}