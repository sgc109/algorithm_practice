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
#define REP(i,a,b) for(int i = a; i <= b;++i)
#define FOR(i,n) REP(i,0,n-1)
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
const int MAX_N = 102;

int N,M,K;
vi adj[300];
int cap[300][300];
int capp[200];
int parent[300];
int sink,src;
void connect(int a, int b, int c){
	adj[a+1].pb(b);
	adj[b+1].pb(a);
	cap[a+1][b]=c;
	cap[b+1][a]=c;
}
int edmonds(){
	int ret=0;
	while(1){
		memset(parent,-1,sizeof(parent));
		queue<int> q;
		q.push(src);
		while(!q.empty()&&parent[sink+1]==-1){
			int here = q.front();
			q.pop();
			for(int there : adj[here]){
				if(parent[there]!=-1||cap[here][there]<=0) continue;
				parent[there]=here;
				q.push(there);
			}
		}
		if(parent[sink+1]==-1) break;
		int minFlow=INF;
		for(int p=sink+1;p;p=parent[p]){
			minFlow=min(minFlow,cap[parent[p]][p]);
		}
		for(int p=sink+1;p;p=parent[p]){
			cap[parent[p]][p]-=minFlow;
			cap[p][parent[p]]+=minFlow;
		}
		ret+=minFlow;
	}
	return ret;
}
int main() {
	inp3(N,M,K);
	FOR(i,N) inp1(capp[i]);
	sink = (N-1)<<1;
	src = 0;
	FOR(i,M){
		int a,b;
		inp2(a,b);
		a--;b--;
		a*=2;b*=2;
		connect(a,b,INF);
	}
	FOR(i,N){
		adj[2*i].pb(2*i+1);
		adj[2*i+1].pb(2*i);
		cap[2*i][2*i+1]=(capp[i]==-1?INF:capp[i]);
	}
	int fw = edmonds();
	if(fw>=K) printf("YES");
	else printf("NO");

	return 0;
}
