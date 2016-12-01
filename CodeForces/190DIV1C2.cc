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

int n;
int size[MAX_N]; // i번 노드를 루트로 갖는 서브트리의 노드수
int Rank[MAX_N];
int centroid;
vi adj[MAX_N];

void NO(){
	printf("Impossible!");
	exit(0);
}

int getSize(int here, int parent){
	// printf("here:%d\n",here);
	size[here]=1;
	for(int there : adj[here]){
		if(Rank[there]!=0 || there==parent) continue;
		size[here] += getSize(there,here);
	}
	return size[here];
}
void dfs(int here, int total, int parent){
	int maxSize=-1;
	for(int there : adj[here]){
		if(Rank[there]!=0 || there==parent) continue;
		maxSize = max(maxSize, size[there]);
	}
	maxSize = max(maxSize, total-size[here]);
	if(maxSize <= total/2) {
		centroid=here;
		return;
	}
	for(int there : adj[here]){
		if(Rank[there]!=0 || there==parent) continue;
		dfs(there,total,here);
	}
}

void solve(int root, char alpha){
	if(alpha>'Z') NO();
	getSize(root,-1);
	int total = size[root];
	dfs(root, total, -1);
	Rank[centroid]=alpha;
	// printf("root:%d, centroid:%d\n",root+1,centroid+1);
	for(int there : adj[centroid]){
		if(Rank[there]!=0) continue;
		solve(there, alpha+1);
	}
}
int main() {
	memset(Rank,0,sizeof(Rank));
	inp1(n);
	FOR(i,n-1){
		int a,b;
		inp2(a,b);
		--a;--b;
		adj[a].pb(b);
		adj[b].pb(a);
	}
	solve(0,'A');
	FOR(i,n){
		printf("%c ",Rank[i]);
	}
	return 0;
}