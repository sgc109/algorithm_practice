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
// #include <unordered_set>
// #include <map>
#define REP(i,a,b) for(int i = a; i < b;++i) 
#define FOR(i,n) REP(i,0,n)
#define mp make_pair
#define pb push_back
#define inp1(a) scanf("%d",&a)
#define inp2(a,b) scanf("%d%d",&a,&b)
#define inp3(a,b,c) scanf("%d%d%d",&a,&b,&c)
#define inp4(a,b,c,d) scanf("%d%d%d%d",&a,&b,&c,&d)
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)

using namespace std;

typedef long long ll;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<vector<int> > vvi;
typedef pair<int,int> pii;
typedef pair<int,pair<int,int> > piii;
typedef queue<int> QU;

const int INF = 0x3c3c3c3c;
const long long INFL = 0x3c3c3c3c3c3c3c3c;
const int MAX_N = 102;

vi adj[MAX_N];
pii intervals[MAX_N];
int nodeCnt;
int n;
int visited[MAX_N];
void dfs(int here){
	// printf("here:%d\n",here);
	visited[here] = 1;
	for(int& there : adj[here]){
		if(!visited[there]) dfs(there);
	}
}
int main() {
	inp1(n);
	FOR(i,n){
		int o,a,b;
		inp3(o,a,b);
		if(o==1){
			intervals[nodeCnt++]=mp(a,b);
			pii& newNode = intervals[nodeCnt-1];
			FOR(i,nodeCnt-1){
				pii& oldNode = intervals[i];
				if(oldNode.first < newNode.first && newNode.first < oldNode.second || oldNode.first < newNode.second && newNode.second < oldNode.second) adj[nodeCnt-1].pb(i);
				if(newNode.first < oldNode.first && oldNode.first < newNode.second || newNode.first < oldNode.second && oldNode.second < newNode.second) adj[i].pb(nodeCnt-1);
			}
		}
		else{
			--a;--b;
			memset(visited,0,sizeof(visited));
			dfs(a);
			if(visited[b]) printf("YES\n");
			else printf("NO\n");
		}
	}
	return 0;
}