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
const int MAX_V = 202;

int adj[MAX_V][MAX_V];
int degree[MAX_V];
int n,m;
int fakeEdge[MAX_V][MAX_V];
int ans1;
int passed[MAX_V][MAX_V];
vector<pii> ans2;
void dfs(int here){
	REP(there,1,n+1){
		if(!adj[here][there]) continue;
		// printf("here:%d, there:%d\n",here,there);
		adj[here][there]--;
		adj[there][here]--;
		dfs(there);
		if(fakeEdge[min(here,there)][max(here,there)]>=2 && !passed[min(here,there)][max(here,there)]) {
			passed[min(here,there)][max(here,there)]=1;
			ans2.pb(mp(here,there));
		}
	}
}
int main() {
	int T;
	inp1(T);
	while(T--){
		memset(degree,0,sizeof(degree));
		memset(fakeEdge,0,sizeof(fakeEdge));
		memset(adj,0,sizeof(adj));
		memset(passed,0,sizeof(passed));
		ans1=0;
		ans2.clear();

		inp2(n,m);
		FOR(i,m){
			int a,b;
			inp2(a,b);
			adj[a][b]++;
			adj[b][a]++;
			degree[a]++;
			degree[b]++;
			fakeEdge[min(a,b)][max(a,b)]=2;
		}
		vi oddNode;
		REP(i,1,n+1){
			if(degree[i]%2==1){
				oddNode.pb(i);
			}
			else ++ans1;
		}
		FOR(i,oddNode.size()/2){
			int a = oddNode[2*i];
			int b = oddNode[2*i+1];
			adj[a][b]++;
			adj[b][a]++;
			fakeEdge[min(a,b)][max(a,b)]++;
		}
		REP(i,1,n+1) dfs(i);
		printf("%d\n",ans1);
		FOR(i,ans2.size()){
			printf("%d %d\n",ans2[i].first,ans2[i].second);
		}
	}
	return 0;
}