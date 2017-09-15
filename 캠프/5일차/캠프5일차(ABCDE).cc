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
int start;
vi adj[2003];
int visited[2003];
int dfs(int here){
	visited[here]=1;
	vi childs;
	for(int there:adj[here]){
		if(visited[there]) continue;
		int cnt = dfs(there);
		childs.pb(cnt);
	}
	sort(childs.begin(),childs.end());
	if(here==start) {
		if(childs.size()==0) return 0;
		else if(childs.size()==1) {
			return childs[0]>=4;
		}
		else {
			return childs[childs.size()-1]+childs[childs.size()-2]>=4;
		}
	}
	return childs.size()==0?1:1+childs.back();
}
int main() {
	inp2(N,M);
	FOR(i,M){
		int a,b;
		inp2(a,b);
		adj[a].pb(b);
		adj[b].pb(a);
	}
	FOR(i,N){
		memset(visited,0,sizeof(visited));
		start=i;
		if(dfs(i)) {
			printf("1");
			return 0;
		}
	}
	printf("0");
	return 0;
}
