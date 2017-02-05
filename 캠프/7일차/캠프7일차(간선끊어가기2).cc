#include <bits/stdc++.h>
#define REP(i,a,b) for(int i=a;i<=b;++i)
#define FOR(i,n) for(int i=0;i<n;++i)
#define pb push_back
#define all(v) (v).begin(),(v).end()
#define sz(v) ((int)(v).size())
#define inp1(a) scanf("%d",&a)
#define inp2(a,b) scanf("%d%d",&a,&b)
#define inp3(a,b,c) scanf("%d%d%d",&a,&b,&c)
#define inp4(a,b,c,d) scanf("%d%d%d%d",&a,&b,&c,&d)
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<pair<int,int> > vii;
typedef vector<vector<int> > vvi;
typedef pair<int,int> pii;
typedef pair<int,pair<int,int> > piii;
const double EPSILON = 1e-9;
const double PI = acos(0.0)*2;
const int MOD = 1000000007;
const int INF = 0x3c3c3c3c;
const long long INFL = 0x3c3c3c3c3c3c3c3c;
const int MAX_N = 102;

int N,M,a,b,c,S,T;
int adj[51][51];
int cap[51][51],flow[51][51];
int parent[51],level[51];
int iter[51];
bool dfs(int here){
	if(here==T) return true;
	for(int& there=iter[here];there<=N;there++){
		if(!adj[here][there]||cap[here][there]-flow[here][there]<=0 || level[here]+1!=level[there]) continue;
		parent[there]=here;
		if(dfs(there)) return true;
	}
	return false;
}
int dinic(){
	int ret=0;
	while(1){
		memset(level,-1,sizeof(level));
		memset(iter,0,sizeof(iter));
		queue<int> q;
		q.push(S);
		level[S]=0;
		while(!q.empty()&&level[T]==-1){
			int here=q.front();
			q.pop();
			REP(there,1,N){
				if(!adj[here][there]||level[there]!=-1||cap[here][there]-flow[here][there]<=0) continue;
				level[there]=level[here]+1;
				q.push(there);
			}
		}
		if(level[T]==-1) break;
		while(1){
			if(!dfs(S)) break;
			int minFlow=INF;
			for(int p=T; p!=S; p=parent[p]){
				minFlow=min(minFlow,cap[parent[p]][p]-flow[parent[p]][p]);
			}
			for(int p=T; p!=S; p=parent[p]){
				flow[parent[p]][p]+=minFlow;
				flow[p][parent[p]]-=minFlow;
			}
			ret+=minFlow;
		}
	}
	return ret;
}
int acc;
vii edges;
int main() {
	inp2(N,M);
	FOR(i,M){
		inp3(a,b,c);
		adj[a][b]=adj[b][a]=c;
		cap[a][b]=cap[b][a]=c;
		edges.pb({a,b});
		acc+=c;
	}
	inp2(S,T);
	int ans=-INF;
	for(auto e:edges){
			int i=e.first,j=e.second;
			memset(flow,0,sizeof(flow));
			int bck=cap[i][j];
			cap[i][j]=cap[j][i]=0;
			ans=max(ans,acc-dinic());
			cap[i][j]=cap[j][i]=bck;
	}
	printf("%d",ans);
	return 0;
}
