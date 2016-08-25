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
const int MAX_N = 100002;

int a[MAX_N];
int n,pos;

int main() {
	scanf("%d%d",&n,&pos);
	FOR(i,n) {
		scanf("%d",a+i);
	}
	if(n==1) {
		printf("0");
		return 0;
	}
	sort(a,a+n);
	int index = lower_bound(a,a+n,pos) - a;
	long long sum = 0;
	int left = a[0], right = a[n-1];
	if(pos <= left) {
		printf("%d",abs(a[n-2] - pos));
		return 0;
	}
	else if(right <= pos) {
		printf("%d",abs(a[1] - pos));
		return 0;
	}

	if(abs(left-pos) >= abs(right-pos)) {
		if(index == 1) printf("%d",abs(right-pos));
		if(index == n-1)
		else printf("%d",abs(right - pos) * 2 + abs(a[1] - pos));
	}
	else {
		if(index == n-1) printf("%d",abs(left-pos));
		else printf("%d",abs(left - pos) * 2 + abs(a[n-2] - pos));	
	}

	return 0;
}