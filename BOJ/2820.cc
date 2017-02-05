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
#define all(v) (v).begin(),(v).end()
#define inp1(a) scanf("%d",&a)
#define inp2(a,b) scanf("%d%d",&a,&b)
#define inp3(a,b,c) scanf("%d%d%d",&a,&b,&c)
#define inp4(a,b,c,d) scanf("%d%d%d%d",&a,&b,&c,&d)

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
const int MAX_N = 102;

int N,M;
int n;
int money[500002];
int parent[500002];
ll t[524289];
ll lz[1048577];
vi adj[500002];
int id2order[500002];
int startEnd[500002][2];
int nodeCnt;
ll query(int nl, int nr, int node, int pos){
	if(lz[node]) {
		if(nl-nr) lz[node<<1] += lz[node], lz[node<<1|1] += lz[node];
		else t[node-n] += lz[node];
		lz[node]=0;
	}
	if(pos < nl || nr < pos) return 0;
	if(nl == nr && nr == pos) return t[node-n];
	int nm = (nl+nr)>>1;
	return query(nl,nm,node<<1,pos)+query(nm+1,nr,node<<1|1,pos);

} ll query(int pos){return query(0,n-1,1,pos);}

void rUpdate(int nl, int nr, int l, int r, int node, int val){
	if(lz[node]) {
		if(nl-nr) lz[node<<1] += lz[node], lz[node<<1|1] += lz[node];
		else t[node-n] += lz[node];
		lz[node]=0;
	}
	if(r < nl || nr < l) return;
	if(l <= nl && nr <= r) {
		if(nl-nr) lz[node<<1] += val, lz[node<<1|1] += val;
		else t[node-n] += val;
		return;
	}
	int nm = (nl+nr)>>1;
	rUpdate(nl,nm,l,r,node<<1,val);
	rUpdate(nm+1,nr,l,r,node<<1|1,val);

} void rUpdate(int l, int r, int val){rUpdate(0,n-1,l,r,1,val);}

int last;
void dfs(int here){
	id2order[here] = nodeCnt;
	t[nodeCnt] = money[here];
	last = nodeCnt++;
	FOR(i,adj[here].size()){
		int there = adj[here][i];
		dfs(there);
		if(i==0) startEnd[here][0] = id2order[there];
	}
	startEnd[here][1] = (last!=id2order[here]?last:0);
}
int main() {
	inp2(N,M);
	inp1(money[1]);
	n = 1<<(int)ceil(log2(N));
	for(int i = 2; i <= N; i++){
		int a,b;
		inp2(a,b);
		money[i] = a;
		parent[i] = b;
		adj[b].pb(i);
	}
	dfs(1);
	while(M--){
		char op;
		scanf(" %c",&op);
		if(op=='p'){
			int a,b;
			inp2(a,b);
			if(!startEnd[a][0] || !b) continue;
			rUpdate(startEnd[a][0],startEnd[a][1],b);
		}
		else if(op=='u') {
			int a;
			inp1(a);
			printf("%lld\n",query(id2order[a]));
		}
	}

	return 0;
}