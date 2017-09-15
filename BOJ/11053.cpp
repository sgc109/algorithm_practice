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

int a[1002];

int main() {
	int n;
	scanf("%d",&n);
	int size = 0;
	FOR(i,n) {
		int tmp;
		scanf("%d",&tmp);
		int pos = lower_bound(a,a+size,tmp) - a;
		a[pos] = tmp;
		size = max(size, pos+1);
	}
	printf("%d",size);
	return 0;
}