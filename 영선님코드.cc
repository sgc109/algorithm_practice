#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
int tree[1<<19],n,m,base;
int dep[100005],par[100005][17],sz[100005],dir[100005],pivot,head[100005],cN,chainNo[100005],pos[100005],arr[100005],type,p,v,u,cost;
pair<int,int> edge[100005];
vector<pair<int,int> > adj[100005];
int query(int l, int r){
	int ret=0;
	for(l+=base-1,r+=base-1; l<=r; l>>=1,r>>=1){
		if(l&1) ret=max(ret,tree[l++]);
		if(~r&1) ret=max(ret,tree[r--]);
	}
	return ret;
}
void update(int idx, int value){
	for(tree[idx+=base-1]=value;idx>1;idx>>=1)
		tree[idx>>1]=max(tree[idx],tree[idx^1]);
}
void dfs(int here,int dad,int d){
	dep[here]=d; par[here][0]=dad; sz[here]=1;
	int tmp=0;
	for(int i=0;i<adj[here].size();i++){
		int there=adj[here][i].first;
		if(there==dad)continue;
		dfs(there,here,d+1);
		sz[here]+=sz[there];
		if(sz[there]>tmp){ tmp=sz[there],dir[here]=i; }
	}
}
void hld(int here){
	pivot++;
	chainNo[here]=cN; pos[here]=pivot;
	if(head[cN]==-1)head[cN]=here;
	if(dir[here]==-1){cN++; return;}
	arr[pivot+1]=adj[here][dir[here]].second;
	hld(adj[here][dir[here]].first);
	for(int i=0;i<adj[here].size();i++){
		int there=adj[here][i].first;
		if(chainNo[there]!=-1)continue;
		arr[pivot+1]=adj[here][i].second;
		hld(there);
	}
}
int LCA(int u,int v){
	if(dep[u]>dep[v])swap(u,v);
	int diff=dep[v]-dep[u];
	for(int i=0;i<17;i++){
		if(diff&(1<<i))v=par[v][i];
	}
	if(u==v)return u;
	for(int i=16;i>=0;i--){
		if(par[u][i]!=par[v][i]){
			u=par[u][i];  v=par[v][i];
		}
	}
	return par[u][0];
}
int queryUp(int u,int v){
	if(u==v)return 0;
	int uchain,vchain=chainNo[v];
	int ret=0;
	while(1){
		uchain=chainNo[u];
		if(uchain==vchain){
			if(u==v)break;
			ret=max(ret,query(pos[v]+1,pos[u]));
			break;
		}
		ret=max(ret,query(pos[head[uchain]],pos[u]));
		u=head[uchain];
		u=par[u][0];
	}
	return ret;
}
int main()
{
	ios::sync_with_stdio(false); cin.tie(0);
	pivot=0; cN=1;
	memset(head,-1,sizeof(head));  memset(chainNo,-1,sizeof(chainNo)); memset(dir,-1,sizeof(dir));
	cin>>n;
	for(base=1; base<n; base*=2);
		for(int i=1;i<=n-1;i++){
			cin>>u>>v>>cost;
			edge[i].first=u; edge[i].second=v;
			adj[u].push_back({v,cost});
			adj[v].push_back({u,cost});
		}
		dfs(1,-1,0);
		for(int i=1;i<17;i++){
			for(int j=1;j<=n;j++){
				if(par[j][i-1]==-1){par[j][i]=-1;}
				else par[j][i]=par[par[j][i-1]][i-1];
			}
		}
		hld(1);
		for(int i=1;i<=n;i++)update(i,arr[i]);
			cin>>m;
		for(int i=0;i<m;i++){
			cin>>type>>p>>v;
			if(type==1){
				int uu=edge[p].first,vv=edge[p].second;
				if(dep[uu]>dep[vv])swap(uu,vv);
				update(pos[vv],v);
			}
			else{
				cout<<max(queryUp(p,LCA(p,v)),queryUp(v,LCA(p,v)))<<"\n";
			}
		}
	}