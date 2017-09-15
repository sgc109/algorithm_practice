#include <vector>
#include <cstdio>
#include <cstring>
#include <queue>
#include <algorithm>
#define REP(i,a,b) for(int i=a;i<=b;++i)
#define FOR(i,n) for(int i=0;i<n;++i)
#define pb push_back
#define all(v) (v).begin(),(v).end()
#define sz(v) ((int)(v).size())
#define inp1(a) scanf("%d",&a)
#define inp2(a,b) scanf("%d%d",&a,&b)
#define inp3(a,b,c) scanf("%d%d%d",&a,&b,&c)
#define inp4(a,b,c,d) scanf("%d%d%d%d",&a,&b,&c,&d)
#define inp5(a,b,c,d,e) scanf("%d%d%d%d%d",&a,&b,&c,&d,&e)
using namespace std;
const int INF = 0x3c3c3c3c;

int N,S,T,a,b,c,d;
int cap[502][502],f[502][502],level[502],iter[502],visited[502];
vi G[502];
int dfs(int here, int flow){
	if(here==T) return flow;
	for(int& i=iter[here];i<sz(G[here]);i++){
		int there = G[here][i];
		if(level[there]!=level[here]+1 || cap[here][there]-f[here][there]<=0) continue;
		int ret = dfs(there,min(flow,cap[here][there]-f[here][there]));
		if(ret>0){
			f[here][there]+=ret,f[there][here]-=ret;
			return ret;
		}
	}
	return 0;
}
int dinic(){
	int ret=0;
	while(1){
		memset(level,-1,sizeof(level));
		memset(iter,0,sizeof(iter));
		queue<int> q;
		level[S]=0;
		q.push(S);
		while(!q.empty()){
			int here = q.front();
			q.pop();
			for(int there : G[here]){
				if(level[there]!=-1 || cap[here][there]-f[here][there]<=0) continue;
				level[there] = level[here] + 1;
				q.push(there);
			}
		}
		if(level[T]==-1) break;
		while(d=dfs(S,INF),ret+=d,d){}
	}
	return ret;
}
int main() {
	S=500,T=501;
	inp1(N);
	FOR(i,N){
		inp1(a);
		if(a==1) cap[S][i]=INF,G[S].pb(i),G[i].pb(S);
		else if(a==2) cap[i][T]=INF,G[i].pb(T),G[T].pb(i);
	}
	FOR(i,N){
		FOR(j,N){
			inp1(cap[i][j]);
			if(i!=j) G[i].pb(j);
		}
	}
	int ans = dinic();
	printf("%d\n",ans);

	queue<int> q;
	q.push(S);
	visited[S]=1;
	while(!q.empty()){
		int here=q.front();
		q.pop();
		for(int there : G[here]){
			if(visited[there] || cap[here][there]-f[here][there]<=0) continue;
			q.push(there);
			visited[there]=1;
		}
	}
	FOR(i,N) if(visited[i]) printf("%d ",i+1);
	printf("\n");
	FOR(i,N) if(!visited[i]) printf("%d ",i+1);
	printf("\n");
	return 0;
}
