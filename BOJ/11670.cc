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
#include <unordered_set>
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
const int MAX_N = 2502;

vl comp;
int n;
pll pairs[MAX_N];
int aMatch[MAX_N],bMatch[3*MAX_N];
unordered_set<ll> us;
vi adj[MAX_N];
int visited[MAX_N];
int level[MAX_N];

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
int bipartite(){
	memset(aMatch,-1,sizeof(aMatch));
	memset(bMatch,-1,sizeof(bMatch));
	int ret=0;
	while(1){
		if(!bfs()) break;
		int add=0;
		FOR(a,n){
			if(level[a]!=0) continue;
			if(dfs(a)) add++;
		}
		if(!add) break;
		ret+=add;
	}
	return ret;
}
void insIfNo(ll x){
	if(!us.count(x)){
		comp.pb(x);
		us.insert(x);
	}
}
int bIndex(ll x){
	return lower_bound(comp.begin(),comp.end(),x)-comp.begin();
}
int main() {
	inp1(n);
	FOR(i,n){
		ll a,b;
		scanf("%lld%lld",&a,&b);
		pairs[i] = mp(a,b);
		insIfNo(a+b);
		insIfNo(a-b);
		insIfNo(a*b);
	}	
	sort(comp.begin(),comp.end());
	FOR(i,n){
		int b;
		pll& p = pairs[i];
		b = bIndex(p.first+p.second);
		adj[i].pb(b);
		b = bIndex(p.first-p.second);
		adj[i].pb(b);
		b = bIndex(p.first*p.second);
		adj[i].pb(b);
	}
	int matched = bipartite();
	if(matched!=n){
		printf("impossible");
		return 0;
	}
	FOR(a,n){
		pll& p = pairs[a];
		if(comp[aMatch[a]] == p.first+p.second){
			printf("%lld + %lld = %lld\n",p.first,p.second,comp[aMatch[a]]);
		}
		else if(comp[aMatch[a]] == p.first-p.second){
			printf("%lld - %lld = %lld\n",p.first,p.second,comp[aMatch[a]]);
		}
		else if(comp[aMatch[a]] == p.first*p.second){
			printf("%lld * %lld = %lld\n",p.first,p.second,comp[aMatch[a]]);
		}
	}
	return 0;
}