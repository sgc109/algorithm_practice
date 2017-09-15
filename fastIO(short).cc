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
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)

using namespace std;

typedef long long ll;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<vector<int> > vvi;
typedef pair<int,int> pii;
typedef pair<int,pair<int,int> > piii;

const int INF = 0x3c3c3c3c;
const long long INFL = 0x3c3c3c3c3c3c3c3c;
const int MAX_N = 1000002;

vi adj[MAX_N];
int n;
int ans;
enum{DOMINATED=0,UNDOMINATED=1,DOMINATOR=2};
int visited[MAX_N];

char s[15000000];
 
inline void init() { fread(s, 1, sizeof(s), stdin); }
inline void readN(int &r)
{
    static char *p = s;
    while (*p < 48) p++;
    for (r = *p & 15; *++p & 16; r = r * 10 + (*p & 15));
}

int traversal(int here){
	visited[here]=1;
	int state = UNDOMINATED;
	for(int& there : adj[here]){
		if(visited[there] == 0 && traversal(there)==UNDOMINATED) state=DOMINATOR;
	}
	if(state==DOMINATOR) ++ans;
	return state;
}

int main() {
	init();
	readN(n);
	FOR(i,n-1){
		int a,b;
		readN(a);
		readN(b);
		adj[a].pb(b);
		adj[b].pb(a);
	}
	traversal(1);
	printf("%d\n", ans);
	return 0;
}