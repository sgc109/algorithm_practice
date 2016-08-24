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
	
const int INF = 0x7a7a7a7a;
const int MAX_V = 100001;

vector<vector<ii> > adj;
vector<int> factory;
vector<int> isFactory;

int main() {
	int n,m,k;
	scanf("%d%d%d",&n,&m,&k);
	adj = vector<vector<ii> >(n);
	factory = vector<int>(k);
	isFactory = vector<int>(MAX_V,0);

	FOR(i,m) {
		int a,b,c;
		scanf("%d%d%d",&a,&b,&c);
		--a;--b;
		adj[a].pb(mp(b,c));
		adj[b].pb(mp(a,c));
	}
	FOR(i,k) {
		scanf("%d",&factory[i]);
		--factory[i];
		isFactory[factory[i]] = 1;
	}

	int minn = INF;
	FOR(i,k) {
		int curFactory = factory[i];
		FOR(j,adj[curFactory].size()) {
			if(!isFactory[adj[curFactory][j].first]) minn = min(minn,adj[curFactory][j].second);
		}
	}
	if(minn == INF) printf("-1");
	else printf("%d",minn);
	return 0;
}