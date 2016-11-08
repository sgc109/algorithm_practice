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
typedef queue<int> QU;

const int INF = 0x3c3c3c3c;
const long long INFL = 0x3c3c3c3c3c3c3c3c;
const int MAX_N = 200002;

pii adj[MAX_N][2];
int aMatch[MAX_N];
int bMatch[2*MAX_N];
int level[MAX_N];
int n;

int bfs(int K){
	QU q;
	for(int a=1;a<=n;++a){
		if(aMatch[a]==-1){
			level[a]=0;
			q.push(a);
		}
	}

	while(!q.empty()){
		int a = q.front();
		q.pop();
		for(auto& p : adj[a]){
			int b = p.first;
			int c = p.second;
			if(c > K) continue;
			if(level[bMatch[b]] == -1){
				level[bMatch[b]] = level[a] + 1;
			}
		}
	}
}
bool dfs(int a, int K){
	for(auto& p : adj[a]){
		int b = p.first;
		int c = p.second;
		if(c > K) continue;
		if(bMatch[b] == -1 || level[bMatch[b]] == level[a]+1 && dfs(bMatch[b],K)){
			aMatch[a] = b;
			bMatch[b] = a;
			return true;
		}
	}
	return false;
}
int hopcroft(int K) {
	int ret=0;
	memset(aMatch,-1,sizeof(aMatch));
	memset(bMatch,-1,sizeof(bMatch));
	while(1){
		memset(level,-1,sizeof(level));
		bfs(K);
		int match=0;
		for(int a=1;a<=n;++a){
			if(aMatch[a] == -1 && dfs(a,K)) ++match;
		}
		if(match==0) break;
		ret+=match;
	}
	return ret;
}
int main() {
	inp1(n);
	for(int i=1;i<=n;++i){
		int f1,fk1,f2,fk2;
		inp4(f1,fk1,f2,fk2);
		adj[i][0]=mp(f1,fk1);
		adj[i][1]=mp(f2,fk2);
	}

	int l=0,r=1e6+1;
	while(l<r){
		int mid=(l+r)>>1;
		if(hopcroft(mid) == n) r=mid;
		else l=mid+1;
	}
	if(l==1e6+1) {
		printf("-1");
		return 0;
	}
	printf("%d",l);

	return 0;
}