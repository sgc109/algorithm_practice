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
const int MAX_M = 100002;
const int MAX_Q = 100002;
const int MAX_C = 1000002;

int parent[MAX_N];
int depth[MAX_N];
int size[MAX_N];
int lo[MAX_Q],hi[MAX_Q];
vi query[MAX_M];
pii pairs[MAX_Q];
vector<pair<int,pii> > edges;
int ans[MAX_Q];
int n,m,Q;

int find(int here){
	if(parent[here]==here) return here;
	return parent[here] = find(parent[here]);
}
void merge(int a, int b){
	a = find(a); b = find(b);
	if(a==b) return;
	if(depth[a] < depth[b]) swap(a,b);
	parent[b] = a;
	size[a] += size[b];
	if(depth[a]==depth[b]) depth[a]++;
}
int main() {
	inp2(n,m);
	FOR(i,m){
		int a,b,c;
		inp3(a,b,c);
		--a;--b;
		edges.pb(mp(c,mp(a,b)));
	}
	sort(edges.begin(),edges.end());
	inp1(Q);
	FOR(i,Q){
		int a,b;
		inp2(a,b);
		--a;--b;
		pairs[i] = mp(a,b);
		lo[i]=0;
		hi[i]=m;
	}
	while(1){
		bool ended=true;
		FOR(i,Q){
			if(lo[i]<hi[i]){
				query[(lo[i]+hi[i])>>1].pb(i);
				ended=false;
			}
		}
		if(ended) break;
		FOR(i,n){
			parent[i]=i;
			depth[i]=1;
			size[i]=1;
		}
		FOR(i,m){
			int a = edges[i].second.first;
			int b = edges[i].second.second;
			merge(a,b);
			for(int q : query[i]){
				int u = pairs[q].first;
				int v = pairs[q].second;
				if(find(u)==find(v)){
					hi[q] = i;
					ans[q] = size[find(u)];
				}
				else lo[q] = i+1;
			}
			query[i].clear();
		}
	}
	FOR(i,Q){
		if(lo[i]==m) printf("-1\n");
		else printf("%d %d\n",edges[lo[i]].first,ans[i]);
	}
	return 0;
}