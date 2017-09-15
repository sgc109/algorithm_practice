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
const int MAX_N = 1000002;

int n;
int adj[MAX_N][2];
int aMatch[MAX_N];
int bMatch[MAX_N];
int level[MAX_N];

char s[15000000];
 
inline void init() { fread(s, 1, sizeof(s), stdin); }
inline void readN(int &r)
{
    static char *p = s;
    while (*p < 48) p++;
    for (r = *p & 15; *++p & 16; r = r * 10 + (*p & 15));
}

bool bfs(){
	queue<int> q;
	memset(level,-1,sizeof(level));
	FOR(a,n){
		if(aMatch[a]==-1) {
			q.push(a);
			level[a]=0;
		}
	}
	if(q.empty()) return false;
	while(!q.empty()){
		int a = q.front();
		q.pop();
		for(int b : adj[a]){
			if(bMatch[b]!=-1 && level[bMatch[b]]==-1) {
				level[bMatch[b]]=level[a]+1;
				q.push(bMatch[b]);
			}
		}
	}
	return true;
}

bool dfs(int a){
	for(int b : adj[a]){
		if(bMatch[b] == -1 || level[bMatch[b]] == level[a]+1 && dfs(bMatch[b])){
			aMatch[a] = b;
			bMatch[b] = a;
			return true;
		}
	}
	return false;
}
int bipartite() {
	int ret=0;
	memset(aMatch,-1,sizeof(aMatch));
	memset(bMatch,-1,sizeof(bMatch));

	while(1){
		memset(level,-1,sizeof(level));

		bfs();

		int flow=0;

		FOR(a,n){
			if(aMatch[a] == -1 && dfs(a)) ++flow;
		}
		if(flow==0) break;

		ret += flow;
	}


	return ret;
}

int main() {
	init();
	readN(n);
	FOR(i,n){
		readN(adj[i][0]);
		readN(adj[i][1]);
		--adj[i][0];--adj[i][1];
	}

	int maxMatch = bipartite();

	if(maxMatch != n) {
		printf("-1\n");
		return 0;
	}

	FOR(i,n){
		printf("%d\n",aMatch[i]+1);
	}

	return 0;
}