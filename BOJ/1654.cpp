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

typedef long long ll
;typedef pair<int, int> ii;
typedef pair<ll, ll> llll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<vector<int> > vvi;
typedef vector<ii> vii;
	
const int INF = 0x3a3a3a3a;
const int MAX_V = 1000000;

int n, k;
vector<long long> v;

long long func(long long x) {
	long long ret = 0;
	FOR(i,n) {
		ret += v[i]/x;
	}
	return ret;
}

int main() {
	scanf("%d%d",&n,&k);
	v = vector<long long>(n);
	FOR(i,n) {
		scanf("%lld",&v[i]);
	}

	long long left = 0;
	long long right = 1;
	right <<= 31;
	//printf("%lld\n",right);
	while(right - left > 1) {
		long long mid = (left + right) >> 1;
		//printf("left : %lld, mid : %lld, right : %lld, func(mid) : %lld\n",left,mid,right,func(mid));
		if(func(mid) >= k) left  = mid;
		else right = mid;
	}
	printf("%lld",left);



	return 0;
}