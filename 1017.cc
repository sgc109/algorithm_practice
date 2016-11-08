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
const int MAX_N = 52;
const int MAX_I = 1002;

int matchN[MAX_N];
int notPrime[MAX_I];
int arr[MAX_N];
int n;
int with;
int visited[MAX_N];

void figurePrime(){
	notPrime[2] = 0;
	for(int i = 2; i*i < MAX_I; ++i){
		if(notPrime[i]) continue;
		for(int j = 2*i; j < MAX_I; j+=i){
			notPrime[j]=1;
		}
	}
}

bool dfs(int here){
	if(visited[here]) return false;
	visited[here] = 1;
	FOR(i,n){
		if(i==0 || i==with || i==here) continue;
		if(!notPrime[arr[here]+arr[i]]){
			if(matchN[i]==-1 || dfs(matchN[i])){
				matchN[here] = i;
				matchN[i] = here;
				return true;
			}
		}
	}
	return false;
}

int bipartite(){
	int ret=0;
	memset(matchN,-1,sizeof(matchN));
	FOR(i,n){
		if(i==0 || i==with) continue;
		memset(visited,0,sizeof(visited));
		if(dfs(i)) ++ret;
	}
	return ret;
}

int main() {
	inp1(n);
	FOR(i,n){
		inp1(arr[i]);
	}
	figurePrime();
	int cnt=0;
	REP(i,1,n){
		if(notPrime[arr[0]+arr[i]]) continue;
		with=i;
		if(bipartite()==n/2-1){
			++cnt;
			printf("%d ",arr[i]);
		}
	}
	if(!cnt) printf("-1");

	return 0;
}