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
#include <deque>
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

const double EPSILON = 1e-9;
const double PI = acos(0.0)*2;
const int MOD = 1000000007;
const int INF = 0x3c3c3c3c;
const long long INFL = 0x3c3c3c3c3c3c3c3c;
const int MAX_N = 5002;

int n,m,p,q;
vector<pii> adj[MAX_N];
vi con;
vi home;
int a,b,c;
int dist[MAX_N];
int minNum;
int minD;
void dijkstra(int start){
	memset(dist,0x3c,sizeof(dist));
	dist[start]=0;
	priority_queue<pii> pq;
	pq.push(mp(0,start));
	while(!pq.empty()){
		int here = pq.top().second;
		int hereDist = -pq.top().first;
		pq.pop();
		if(dist[here]<hereDist) continue;
		for(auto p : adj[here]){
			int there = p.first;
			int thereDist = p.second+hereDist;
			if(dist[there]<=thereDist) continue;
			dist[there] = thereDist;
			pq.push(mp(-thereDist,there));
		}
	}

}
int main() {
	minD=INF;
	inp2(n,m);
	FOR(i,m){
		inp3(a,b,c);
		a--;b--;
		adj[a].pb(mp(b,c));
		adj[b].pb(mp(a,c));
	}
	inp2(p,q);
	FOR(i,p){
		inp1(a);
		a--;
		home.pb(a);
	}
	FOR(i,q){
		inp1(a);
		a--;
		con.pb(a);
	}
	FOR(i,q){
		adj[5000].pb(mp(con[i],0));
		adj[con[i]].pb(mp(5000,0));
	}
	dijkstra(5000);
	FOR(i,p){
		if(dist[home[i]]<minD) minD=dist[home[i]],minNum=home[i];
	}
	printf("%d",minNum+1);
	return 0;
}
