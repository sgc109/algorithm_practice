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

const int INF = 0x3c3c3c3c;
const long long INFL = 0x3c3c3c3c3c3c3c3c;
const int MAX_N = 10001;
const int MAX_M = 500002;

char s[200000000];
 
inline void init() { fread(s, 1, sizeof(s), stdin); }
inline void readN(int &r)
{
    static char *p = s;
    while (*p < 48) p++;
    for (r = *p & 15; *++p & 16; r = r * 10 + (*p & 15));
}

int cache[MAX_N][MAX_N];
int n,m,q;
vector<pii> adj[MAX_N];
void dijkstra(int start){
	priority_queue<pii> pq;
	cache[start][start] = INF;
	pq.push(mp(INF,start));
	while(!pq.empty()){
		int here = pq.top().second;
		int hereMin = pq.top().first;
		pq.pop();
		if(cache[start][here] > hereMin) continue;
		for(pii& p : adj[here]){
			int there = p.first;
			int thereMin = min(hereMin,p.second);
			if(cache[start][there] < thereMin){
				cache[start][there] = thereMin;
				pq.push(mp(cache[start][there],there));
			}
		}
	}
}

int main() {
	FILE *fp = fopen("output.txt","wb");
	init();
	int T;
	readN(T);
	printf("T:%d\n",T);
	FOR(t,T){
		printf("T:%d\n",t);
		memset(cache,-1,sizeof(cache));
		readN(n);readN(m);
		FOR(i,n) adj[i].clear();
		FOR(i,m){
			int a,b,c;
			readN(a);readN(b);readN(c);
			--a;--b;
			adj[a].pb(mp(b,c));
			adj[b].pb(mp(a,c));
		}
		readN(q);
		ll ans=0;
		FOR(i,q){
			int a,b;
			readN(a);readN(b);
			--a;--b;
			if(a==b) continue;
			if(cache[a][b] != -1) ans+=cache[a][b];
			else if(cache[b][a] != -1) ans+=cache[b][a];
			else {
				// memset(cache[a],-1,sizeof(cache[a]));
				dijkstra(a);
				ans+=cache[a][b];
			}
		}
		fprintf(fp,"%lld\n",ans);
	}
	return 0;
}