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
const int MAX_N = 1002;

int n,m;
vi adj[MAX_N];
int level[MAX_N];
int aMatch[MAX_N],bMatch[MAX_N];

bool dfs(int a){

	for(int b : adj[a]){
		if(bMatch[b]==-1 || level[bMatch[b]]==level[a]+1 && dfs(bMatch[b])){
			bMatch[b] = a;
			aMatch[a] = b;
			return true;
		}
	}
	return false;
}
int hopcroft(){
	int ret=0;
	while(1){
		int add=0;
		memset(level,-1,sizeof(level));
		queue<int> q;
		FOR(a,n) {
			if(aMatch[a]==-1) {
				level[a]=0;
				q.push(a);
			}
		}
		// if(q.empty()) break;
		while(!q.empty()){
			int a = q.front();
			q.pop();
			for(int b : adj[a]){
				if(bMatch[b]==-1) continue;
				if(level[bMatch[b]]!=-1) continue;
				level[bMatch[b]]=level[a]+1;
				q.push(bMatch[b]);
			}
		}
		FOR(a,n) {
			if(aMatch[a]==-1&&dfs(a)) ++add;
		}
		if(!add) break;
		// printf("add:%d\n",add);
		ret+=add;
	}
	return ret;
}
int main() {
	inp2(n,m);
	FOR(i,n){
		int c;
		inp1(c);
		while(c--) {
			int tmp;
			inp1(tmp);
			tmp--;
			adj[i].pb(tmp);
		}
	}
	memset(aMatch,-1,sizeof(aMatch));
	memset(bMatch,-1,sizeof(bMatch));
	int ans = hopcroft();
	printf("%d",ans);
	return 0;
}