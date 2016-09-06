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

int n;
long long map[501][501];

int emptyI;
int emptyJ;

bool dagak1;
bool dagak2;

int main() {
	dagak1 = false;
	dagak2 = false;
	scanf("%d",&n);
	FOR(i,n) {
		FOR(j,n) {
			scanf("%I64d",&map[i][j]);
			if(map[i][j] == 0) {
				emptyI = i;
				emptyJ = j;
			}
		}
	}

	if(n==1) {
		printf("1");
		return 0;
	}

	if((emptyI+emptyJ) == (n-1)) dagak2 = true;
	if(emptyI==emptyJ) dagak1 = true;

	long long sum;
	long long gijun = 0;

	// 가로줄
	FOR(i,n) {
		if(i == emptyI) continue;
		sum = 0;
		FOR(j,n) {
			sum += map[i][j];
		}
		if(gijun==0) gijun = sum;
		else {
			if(gijun != sum) {
				printf("-1");
				return 0;
			}
		}
	}

	FOR(j,n) {
		if(j == emptyJ) continue;
		sum = 0;
		FOR(i,n) {
			sum += map[i][j];
		}
		if(gijun != sum) {
			printf("-1");
			return 0;
		}
	}

	if(!dagak1) {
		sum = 0;
		FOR(i,n) {
			sum += map[i][i];
		}
		if(gijun != sum) {
			printf("-1");
			return 0;
		}	
	}

	if(!dagak2) {
		sum = 0;
		FOR(i,n) {
			sum += map[i][n-i-1];
		}
		if(gijun != sum) {
			printf("-1");
			return 0;
		}	
	}

	long long a=0,b=0,c=0,d=0;
	FOR(i,n) {
		a += map[emptyI][i];
		b += map[i][emptyJ];
		if(dagak1) c += map[i][i];
		if(dagak2) d += map[i][n-i-1];
	}

	if(!dagak1 && !dagak2) {
		if(a == b && a < gijun) printf("%I64d",gijun - a);
		else printf("-1");
	}
	else if(dagak1 && dagak2) {
		if(a == b && b == c && c == d && d < gijun) printf("%I64d",gijun - a);
		else printf("-1");
	}
	else {
		if(dagak1) {
			if(a == b && b == c && c < gijun) printf("%I64d",gijun - c);
			else printf("-1");
		}
		else if(dagak2) {
			if(a == b && b == d && d < gijun) printf("%I64d",gijun - d);
			else printf("-1");
		}
	}



	return 0;
}