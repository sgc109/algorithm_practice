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
const int MAX_N = 2002;

int N,K;
vi adj[MAX_N];
int dist[MAX_N];
int cnt;
void dfs(int here){
	for(int there : adj[here]){
		if(dist[there]!=-1) continue;
		dist[there] = dist[here]+1;
		if(dist[there] > K/2) ++cnt;
		dfs(there);
	}
}
int main() {
	inp2(N,K);
	FOR(i,N-1){
		int a,b;
		inp2(a,b);
		--a;--b;
		adj[a].pb(b);
		adj[b].pb(a);
	}
	int ans=INF;
	if(K%2){
		FOR(a,N){
			for(int b : adj[a]){
				memset(dist,-1,sizeof(dist));
				cnt=0;
				dist[a]=dist[b]=0;
				dfs(a);
				dfs(b);
				ans=min(ans,cnt);
			}
		}
	}
	else {
		FOR(c,N){
			memset(dist,-1,sizeof(dist));
			cnt=0;
			dist[c]=0;
			dfs(c);
			ans=min(ans,cnt);
		}
	}
	printf("%d",ans);
	return 0;
}