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

int ans1;
vector<pii> ans2;
int passed[MAX_V][MAX_V];
int degree[MAX_V];
vi adj[MAX_V];
int started[MAX_V];
int n,m;
int passedEdge;

void dfs(int here){
	for(int& there : adj[here]){
		if(passed[min(here,there)][max(here,there)]) continue;
		passed[min(here,there)][max(here,there)]=1;
		++passedEdge;
		degree[here]--;
		degree[there]--;
		ans2.pb(mp(here,there));
		dfs(there);
		return;
	}
}
int main() {
	int T;
	inp1(T);
	while(T--){
		memset(degree,0,sizeof(degree));
		memset(passed,0,sizeof(passed));
		memset(started,0,sizeof(started));
		FOR(i,MAX_V) adj[i].clear();
		ans1 = 0;
		ans2.clear();

		inp2(n,m);
		FOR(i,m){
			int a,b;
			inp2(a,b);
			adj[a].pb(b);
			adj[b].pb(a);
			degree[a]++;
			degree[b]++;
		}
		REP(i,1,n+1) if(degree[i]%2==0) ++ans1;

		passedEdge=0;
		while(passedEdge < m){
			int start=-1;
			REP(i,1,n+1) {
				if(!started[i] && degree[i]%2==1){
					start = i;
					break;
				}
			}
			if(start==-1){
				REP(i,1,n+1) {
					if(!started[i]){
						start = i;
						break;
					}
				}	
			}
			started[start] = 1;
			dfs(start);
		}
		printf("%d\n",ans1);
		FOR(i,ans2.size()){
			printf("%d %d\n",ans2[i].first,ans2[i].second);
		}
	}
	return 0;
}