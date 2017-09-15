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

int prime[1000002];

int m, n;

int main() {
	FOR(i,1000002) 
		prime[i] = 0;
	scanf("%d%d",&m,&n);
	for(int i = 2; i*i <= n; ++i) {
		if(prime[i] == 1) continue;
		for(int j = 2*i; j <= n; j+=i) {
			prime[j] = 1;
		}
	}
	prime[1] = 1;

	REP(i,m,n+1) {
		if(!prime[i]) printf("%d\n",i);
	}
	return 0;
}