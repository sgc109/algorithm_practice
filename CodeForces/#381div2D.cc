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
const int MAX_N = 200002;

ll dist;
vector<pii> adj[MAX_N];
int limit[MAX_N];
int cnt[MAX_N];
set<pair<ll,int> > st;
int p[MAX_N];
void dfs1(int here){
	auto it = st.lower_bound(mp(dist-(ll)limit[here],0));
	if(here!=0){
		cnt[p[here]]++;
		if((*it).second!=0) cnt[p[(*it).second]]--;
	}
	for(auto& p : adj[here]){
		int there = p.first;
		int cost = p.second;
		dist+=cost;
		st.insert(mp(dist,there));
		dfs1(there);
		dist-=cost;
		st.erase(--st.end());
	}
}
void dfs2(int here){
	for(auto& p : adj[here]){
		int there = p.first;
		dfs2(there);
		cnt[here]+=cnt[there];
	}
}
int main() {
	int n;
	inp1(n);
	FOR(i,n) inp1(limit[i]);
	FOR(i,n-1){
		int pp,d;
		inp2(pp,d);
		pp--;
		adj[pp].pb(mp(i+1,d));
		p[i+1] = pp;
	}
	p[0]=0;
	st.insert(mp(0,0));
	dfs1(0);
	dfs2(0);
	FOR(i,n) printf("%d ",cnt[i]);
	return 0;
}