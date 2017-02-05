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
const int MAX_N = 502;

int adj[MAX_N][MAX_N];
int dist[MAX_N];
int n,m;
void update(){
	memset(dist,0x3c,sizeof(dist));
	dist[0]=0;
	priority_queue<pii> pq;
	pq.push(mp(0,0));
	while(!pq.empty()){
		int here = pq.top().second;
		int hereDist = -pq.top().first;
		pq.pop();
		if(dist[here]<hereDist) continue;
		FOR(there,n){
			if(!adj[here][there]) continue;
			if(dist[there]>hereDist+1){
				dist[there]=hereDist+1;
				pq.push(mp(-dist[there],there));
			}
		}
	}
}
int main() {
	inp2(n,m);
	FOR(i,m){
		int a,b;
		inp2(a,b);
		a--;b--;
		adj[a][b]=1;
		adj[b][a]=1;
	}
	
	int q;
	inp1(q);
	FOR(i,q){
		int a,b;
		inp2(a,b);
		a--;b--;
		adj[a][b]=adj[b][a]=1;
		update();
		FOR(i,n) printf("%d ",dist[i]>n?-1:dist[i]);
		printf("\n");
	}
	return 0;
}
