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
typedef pair<int,int> pii;
typedef vector<pii> vii;
typedef vector<pll> vll;
typedef vector<vector<int> > vvi;
typedef pair<int,pair<int,int> > piii;
const double EPSILON = 1e-9;
const double PI = acos(0.0)*2;
const int MOD = 1000000007;
const int INF = 0x3c3c3c3c;
const long long INFL = 0x3c3c3c3c3c3c3c3c;
const int MAX_N = 102;

int p[100003][18],depth[100003];
int w[100003],segIdx[100003];
int t[300003],z[300003],d[100003],e[100003];
int hldId[100003];
vvi group;
vector<piii> G[100003];
int N,M,root,o,a,b,u,v,c,id;
int lca(int a, int b){
	if(a==b) return a;
	if(depth[a]>depth[b]) swap(a,b);
	int diff=depth[b]-depth[a];
	for(int i=0;diff;diff>>=1,i++) if(diff&1) b=p[b][i];
	if(a==b) return a;
	for(int i=17;i>=0;i--) if(p[a][i]!=p[b][i]) a=p[a][i],b=p[b][i];
	if(a==b) return a;
	return p[a][0];
}
int dfs(int here, int dad){
	int ret=1;
	for(int i=1;i<18;i++) p[here][i]=p[p[here][i-1]][i-1];
	for(auto it:G[here]){
		int there=it.first;
		if(there==dad) continue;
		p[there][0]=here;
		depth[there]=depth[here]+1;
		d[there]=it.second.first;
		e[it.second.second]=there;
		ret+=dfs(there,here);
	}
	return w[here]=ret;
}
void tBuild(){
	N=id;
	for(auto g:group){
		for(int i=sz(g)-1;i>=0;i--){
			t[N+segIdx[g[i]]]=d[g[i]];
		}
	}
	for(int i=N-1;i>=1;i--) t[i]=max(t[i<<1],t[i<<1|1]);
}
int tQuery(int l, int r){
	int ret=0;
	for(l+=N,r+=N;l<=r;l>>=1,r>>=1){
		if(l&1) ret=max(ret,t[l++]);
		if(!(r&1)) ret=max(ret,t[r--]);
	}
	return ret;
}
void tUpdate(int pos, int v){
	for(t[pos+=N]=v;pos>1;pos>>=1) t[pos>>1]=max(t[pos],t[pos^1]);
}
int visited[100003];
void grouping(){
	queue<int> q;
	q.push(root);
	visited[root]=1;
	while(!q.empty()){
		int here = q.front();
		q.pop();
		for(auto it:G[here]){
			int there=it.first;
			if(visited[there]) continue;
			q.push(there);
			visited[there]=1;
		}
		int parent=p[here][0];
		if(here==root) continue;
		if(w[here]*2>=w[parent]&&parent!=root){
			hldId[here]=hldId[parent];
			group[hldId[here]].pb(here);
		}
		else {
			hldId[here]=group.size();
			group.pb(vi(1));
			group.back()[0]=here;
		}
	}
}
int hldQuery(int u, int v){
	int ret=0;
	int l=lca(u,v);
	while(u!=l){
		if(hldId[u]!=hldId[l]){
			ret=max(ret,tQuery(segIdx[u],segIdx[group[hldId[u]][0]]));
			u=p[group[hldId[u]][0]][0];
		}
		else{
			int base=depth[group[hldId[u]].back()]-depth[u];
			int next=depth[u]-depth[l]-1;
			int r=segIdx[group[hldId[u]][group[hldId[u]].size()-1-base-next]];
			ret=max(ret,tQuery(segIdx[u],r));
			break;
		}
	}
	while(v!=l){
		if(hldId[v]!=hldId[l]){
			ret=max(ret,tQuery(segIdx[v],segIdx[group[hldId[v]][0]]));
			v=p[group[hldId[v]][0]][0];
		}
		else{
			int base=depth[group[hldId[v]].back()]-depth[v];
			int next=depth[v]-depth[l]-1;
			int r=segIdx[group[hldId[v]][group[hldId[v]].size()-1-base-next]];
			ret=max(ret,tQuery(segIdx[v],r));
			break;
		}
	}
	
	return ret;
}
void hldUpdate(int pos, int v){
	tUpdate(segIdx[e[pos]],v);
}

int main() {
	root=1;
	inp1(N);
	FOR(i,N-1){
		inp3(u,v,c);
		G[u].pb({v,{c,i+1}});
		G[v].pb({u,{c,i+1}});
	}
	dfs(root,0);
	hldId[root]=-1;
	grouping();
	for(auto g:group){
		for(int i=sz(g)-1;i>=0;i--){
			segIdx[g[i]]=id++;
		}
	}
	tBuild();
	inp1(M);
	FOR(i,M){
		inp3(a,b,c);
		if(a-1) printf("%d\n",hldQuery(b,c));
		else hldUpdate(b,c);
	}
	return 0;
}
