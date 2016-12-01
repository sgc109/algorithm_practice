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
const int MAX_N = 10002;

int N;
vi adj[MAX_N+1];
int oil[MAX_N+1];
int depth[MAX_N+1];
int childCnt[MAX_N+1];

int bfs(int start){
	queue<int> q;
	q.push(start);
	depth[start]=0;
	while(!q.empty()){
		int here = q.front();
		q.pop();
		for(int there : adj[here]){
			if(depth[there]!=-1) continue;
			childCnt[here]++;
			depth[there] = depth[here]+1;
			q.push(there);
		}
	}
}

int solve(int here) { // here번 노드에서 최대 도약횟수
	if(oil[here]<=1 || !childCnt[here]) return 0;

	int ret=0;
	vi childTrav;
	int leafCnt=0;

	for(int child : adj[here]){
		if(depth[child] < depth[here]) continue;
		int ret = solve(child);
		if(ret) childTrav.pb(-ret);
		if(oil[child]) leafCnt+=oil[child];
	}
	sort(childTrav.begin(),childTrav.end());
	for(int travCnt : childTrav){
		ret+=-travCnt+2;
		oil[here]--;
		if(oil[here]==1){
			oil[here]--;
			return ret;
		}
	}
	int goAndCome = (oil[here]>leafCnt?leafCnt:oil[here]-1);
	oil[here]-=goAndCome;
	ret+=2*goAndCome;

	oil[here]--;
	return ret;
}
int main() {
	int T;
	inp1(T);
	FOR(t,T){
		memset(depth,-1,sizeof(depth));
		memset(childCnt,0,sizeof(childCnt));
		inp1(N);
		FOR(i,N+1) adj[i].clear();
		FOR(i,N){
			inp1(oil[i+1]);
		}
		oil[0]=INF;

		FOR(i,N){
			int a,b;
			inp2(a,b);
			adj[a].pb(b);
			adj[b].pb(a);
		}
		
		bfs(0);
		int ans=0;
		for(int child : adj[0]){
			ans = max(ans, 2+solve(child));
		}
		printf("#%d %d\n",t+1,ans);
	}
	return 0;
}