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
#include <ctime>
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

const int INF = 0x3c3c3c3c;
const long long INFL = 0x3c3c3c3c3c3c3c3c;
const int MAX_N = 202;

int n,m;
vvi adj;
int aMatch[MAX_N],bMatch[MAX_N];
int visited[MAX_N];

bool dfs(int a){
	if(visited[a]==1) return false;
	visited[a] = 1;
	FOR(b,n){
		if(adj[a][b]==0) continue;
		if(bMatch[b]==-1 || dfs(bMatch[b])) {
			bMatch[b] = a;
			aMatch[a] = b; 	
			return true;
		}
	}
	return false;
}

int bipartite(){
	int ret=0;
	FOR(a,n){
		memset(visited,0,sizeof(visited));
		if(dfs(a)) ++ret;
	}
	return ret;
}

int main() {

	adj = vvi(MAX_N,vi(MAX_N,1));
	memset(aMatch,-1,sizeof(aMatch));
	memset(bMatch,-1,sizeof(bMatch));
	inp2(n,m);
	FOR(i,m){
		int o,x,y,v;
		inp4(o,x,y,v);
		--x;--y;--v;
		if(o==2){
			FOR(j,v){
				REP(k,x,y+1){
					adj[j][k]=0;
				}
			}
		}
		else if(o==1){
			REP(j,v+1,n){
				REP(k,x,y+1){
					adj[j][k]=0;
				}
			}
		}
		FOR(j,n){
			if(j < x || y < j) adj[v][j]=0;
		}
	}

	int ans=bipartite();


	if(ans!=n){
		printf("-1");
		return 0;
	}

	FOR(i,n){
		printf("%d ",bMatch[i]+1);
	}



	return 0;
}