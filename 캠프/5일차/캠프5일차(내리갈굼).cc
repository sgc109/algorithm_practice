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
#include <set>
#include <cmath>
#include <deque>
// #include <unordered_set>
// #include <map>
#define REP(i,a,b) for(int i = a; i <= b;++i)
#define FOR(i,n) REP(i,0,n-1)
#define mp make_pair
#define pb push_back
#define all(v) (v).begin(),(v).end()
#define inp1(a) scanf("%d",&a)
#define inp2(a,b) scanf("%d%d",&a,&b)
#define inp3(a,b,c) scanf("%d%d%d",&a,&b,&c)
#define inp4(a,b,c,d) scanf("%d%d%d%d",&a,&b,&c,&d)

using namespace std;

typedef long long ll;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<vector<int> > vvi;
typedef pair<int,int> pii;
typedef pair<int,pair<int,int> > piii;
typedef queue<int> QU;

const double EPSILON = 1e-9;
const double PI = acos(0.0)*2;
const int MOD = 1000000007;
const int INF = 0x3c3c3c3c;
const long long INFL = 0x3c3c3c3c3c3c3c3c;
const int MAX_N = 102;

int N,M;
vi adj[100003];
ll g[100003];
void dfs(int here, int dad){
	for(int there : adj[here]){
		if(there==dad) continue;
		g[there]+=g[here];
		dfs(there,here);
	}
}
int main() {
	inp2(N,M);
	REP(i,1,N){
		int dad;
		inp1(dad);
		if(i==1) continue;
		adj[i].pb(dad);
		adj[dad].pb(i);
	}
	FOR(i,M){
		int a,b;
		inp2(a,b);
		g[a]+=b;
	}
	dfs(1,0);

	REP(i,1,N) printf("%lld ",g[i]);
	return 0;	

}
