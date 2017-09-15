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

int N,M,L;
vector<pii> adj[MAX_N];
vi endInG,endInG2;
vi longDist;
pii parent[MAX_N];
int dist[MAX_N];
vi worst;

int maxD,maxI;
void dfs(int here){
	for(auto p : adj[here]){
		int there = p.first;
		int d = p.second;
		if(parent[there].first != -1) continue;
		parent[there] = mp(here,d);
		dist[there] = dist[here]+d;
		if(dist[there] > maxD){
			maxD = dist[there];
			maxI = there;
		}
		dfs(there);
	}
}

int main() {
	inp3(N,M,L);
	FOR(i,M){
		int a,b,c;
		inp3(a,b,c);
		adj[a].pb(mp(b,c));
		adj[b].pb(mp(a,c));
	}

	FOR(i,MAX_N) parent[i]=mp(-1,-1);
	memset(dist,0x3c,sizeof(dist));	
	FOR(i,N){
		if(parent[i].first==-1) {
			maxI=i;maxD=0;
			parent[i]=mp(i,0);
			dist[i] = 0;
			dfs(i);
			endInG.pb(maxI);
		}
	}

	FOR(i,MAX_N) parent[i]=mp(-1,-1);
	memset(dist,0x3c,sizeof(dist));	
	for(auto node : endInG){
		maxI=node;maxD=0;
		parent[node]=mp(node,0);
		dist[node] = 0;
		dfs(node);
		longDist.pb(maxD);
		endInG2.pb(maxI);
	}
	FOR(i,endInG2.size()){
		int node = endInG2[i];
		int sum=0;
		int maxmin=INF;
		for(int p = node; parent[p].first != p; p = parent[p].first){
			sum+=parent[p].second;
			maxmin=min(maxmin,max(sum,longDist[i]-sum));
		}
		if(maxmin==INF) maxmin=0;
		worst.pb(maxmin);
	}
	sort(worst.begin(),worst.end(),greater<int>());

	vi ans;
	if(worst.size()>=2) ans.pb(worst[0]+worst[1]+L);
	for(auto i : longDist){
		ans.pb(i);
	}
	if(worst.size()>=3) ans.pb(worst[1]+worst[2]+2*L);
	int maxAns=-1;
	for(auto i : ans){
		maxAns = max(maxAns, i);
	}
	printf("%d",maxAns);
	return 0;
}