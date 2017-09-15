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
const int MAX_N = 360000;
const long long Hash = 10000007;

long long g;
long long h1, h2;
int n;
vector<int> v1,v2;
vector<int> vv1,vv2;

int main() {
	scanf("%d",&n);
	v1.resize(n);
	v2.resize(n);
	vv1.resize(n);
	vv2.resize(n);
	FOR(i,n) scanf("%d",&v1[i]);
	sort(v1.begin(),v1.end());
	FOR(i,n) scanf("%d",&v2[i]);
	sort(v2.begin(),v2.end());
	FOR(i,n-1) vv1[i] = v1[i+1]-v1[i];
	vv1[n-1] = v1[0] - v1[n-1] + MAX_N;
	FOR(i,n-1) vv2[i] = v2[i+1]-v2[i];
	vv2[n-1] = v2[0] - v2[n-1] + MAX_N;

	g = 1;
	FOR(i,n-1) {
		g = (g * MAX_N) % Hash;
	}

	h1 = 0;
	FOR(i,n) {
		h1 = (h1 * MAX_N + vv1[i]) % Hash;
	}

	h2 = 0;
	FOR(i,n) {
		h2 = (h2 * MAX_N + vv2[i]) % Hash;
	}

	bool poss = false;
	FOR(i,n) {
		if(h1 == h2) {
			poss = true;
			break;
		}
		h2 = (h2 - (vv2[i]*g)%Hash + Hash) % Hash;
		h2 = (h2 * MAX_N) % Hash;
		h2 = (h2 + vv2[i]) % Hash;
	}

	if(poss) printf("possible");
	else printf("impossible");

return 0;
}