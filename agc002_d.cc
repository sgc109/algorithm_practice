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
typedef vector<ll> vl;
typedef vector<vector<int> > vvi;
typedef pair<int,int> pii;
typedef pair<int,pair<int,int> > piii;
typedef queue<int> QU;

const int MOD = 1000000007;
const int INF = 0x3c3c3c3c;
const long long INFL = 0x3c3c3c3c3c3c3c3c;
const int MAX_N = 100002;

int parent[MAX_N];
int depth[MAX_N];
int size[MAX_N];
pair<pii,int> pairs[MAX_N];
int lo[MAX_N],hi[MAX_N];
vi query[MAX_N];
pii edges[MAX_N];
int N,M,Q;
int find(int p){
	if(parent[p]==p) return p;
	return parent[p] = find(parent[p]);
}
void merge(int a, int b){
	a = find(a); b = find(b);
	if(a==b) return;
	if(depth[a]<depth[b]) swap(a,b);
	parent[b] = a;
	if(depth[a]==depth[b]) depth[a]++;
	size[a] += size[b];
}
int main() {
	inp2(N,M);
	FOR(i,M){
		int a,b;
		inp2(a,b);
		a--;b--;
		edges[i]=mp(a,b);
	}
	inp1(Q);
	FOR(i,Q){
		int a,b,c;
		inp3(a,b,c);
		a--;b--;
		pairs[i]=mp(mp(a,b),c);
		lo[i]=0;hi[i]=M;
	}
	while(1){
		bool ended=true;
		// printf("start\n");
		FOR(i,Q){
			if(lo[i]<hi[i]){
				// printf("i:%d\n",i);
				query[(lo[i]+hi[i])>>1].pb(i);
				ended=false;
			}
		}
		if(ended) break;
		FOR(i,N){
			parent[i]=i;
			size[i]=1;
			depth[i]=1;
		}
		FOR(i,M){
			int u = edges[i].first;
			int v = edges[i].second;
			merge(u,v);
			for(int q : query[i]){
				int a = pairs[q].first.first;
				int b = pairs[q].first.second;
				int c = pairs[q].second;
				int cnt;
				a = find(a); b = find(b);
				if(a==b) cnt = size[a];
				else cnt = size[a]+size[b];
				if(cnt<c) lo[q]=i+1;
				else hi[q]=i;
			}
			query[i].clear();
		}
	}
	FOR(i,Q){
		printf("%d\n",lo[i]+1);
	}
	return 0;
}