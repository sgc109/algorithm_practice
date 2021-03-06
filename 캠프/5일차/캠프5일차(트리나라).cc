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

int N,K;
vi adj[53];
int dp[53][53];
int visited[53];
int leaf;
bool dfs(int here, int dad){
	visited[here]=1;
	int cnt=0;
	for(int there : adj[here]){
		if(visited[there]) continue;
		if(there!=dad) cnt++;
		dfs(there,here);
	}
	if(cnt==0) {
		leaf=here;
		return true;
	}
	return true;
}
int dfs2(int here, int cnt){
	visited[here]=1;
	int ret=0;
	for(int there : adj[here]){
		if(visited[here]) continue;
		if(cnt>0) ret+=dfs2(there,cnt-1);
		else return 1;
		ret+=dfs2(there,cnt);
	}
	
}
int main() {
	inp2(N,K);
	FOR(i,N-1){
		int a,b;
		inp2(a,b);
		adj[a].pb(b);
		adj[b].pb(a);
	}
	dfs(1,0);
	memset(visited,0,sizeof(visited));
	dfs2(leaf,K);
	return 0;
}	
