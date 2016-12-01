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
// #define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)

using namespace std;

typedef long long ll;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<vector<int> > vvi;
typedef pair<int,int> pii;
typedef pair<int,pair<int,int> > piii;
typedef queue<int> QU;

const int MOD = 1000000007;
const int INF = 0x3c3c3c3c;
const long long INFL = 0x3c3c3c3c3c3c3c3c;
const int MAX_N = 100002;

char Rank[MAX_N];
int dist[MAX_N];
int parent[MAX_N];
int maxD;
int maxI;
vi adj[MAX_N];
int n;

void NO(){
	printf("Impossible!");
	exit(0);
}
void dfs(int here, int dad){
	for(int there : adj[here]){
		if(there==dad || Rank[there]!=0) continue;
		parent[there] = here;
		dist[there] = dist[here]+1;
		if(dist[there] > maxD){
			maxD = dist[there];
			maxI = there;
		}
		dfs(there,here);
	}
}
void solve(int start, char alpha){
	if(alpha>'Z') NO();
	maxD=0;
	maxI=start;
	dist[start]=0;
	dfs(start,-1);
	maxD=0;
	dist[maxI]=0;
	dfs(maxI,-1);
	int r=maxD/2;
	int c=maxI;
	while(r--) c=parent[c];
	// printf("center:%d, 2*r:%d\n",c,maxD);
	Rank[c]=alpha;
	for(int child : adj[c]){
		if(Rank[child]!=0) continue;
		solve(child,alpha+1);
	}
}

int main() {
	memset(Rank,0,sizeof(Rank));
	inp1(n);
	FOR(i,n-1){
		int a,b;
		inp2(a,b);
		a--;b--;
		adj[a].pb(b);
		adj[b].pb(a);
	}
	solve(0,'A');
	FOR(i,n){
		printf("%c ",Rank[i]);
	}
	return 0;
}