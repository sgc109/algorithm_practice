// #include <bits/stdc++.h>
#include <vector>
#include <cstdio>
#include <iostream>
#include <cstring>
#include <queue>
#include <set>
#include <map>
#include <cmath>
#include <algorithm>
#include <utility>
#define REP(i,a,b) for(int i=a;i<=b;++i)
#define FOR(i,n) for(int i=0;i<n;++i)
#define pb push_back
#define all(v) (v).begin(),(v).end()
#define sz(v) ((int)(v).size())
#define inp1(a) scanf("%d",&a)
#define inp2(a,b) scanf("%d%d",&a,&b)
#define inp3(a,b,c) scanf("%d%d%d",&a,&b,&c)
#define inp4(a,b,c,d) scanf("%d%d%d%d",&a,&b,&c,&d)
#define inp5(a,b,c,d,e) scanf("%d%d%d%d%d",&a,&b,&c,&d,&e)z
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
typedef vector<piii> viii;
const double EPSILON = 1e-9;
const double PI = acos(0.0)*2;
const int MOD = 1000000007;
const int INF = 0x3c3c3c3c;
const long long INFL = 0x3c3c3c3c3c3c3c3c;
const int MAX_N = 102;
struct Edge{int u,v,c,f,rev;};
int K,N,S,E,a,b,c,d;
vector<Edge> G[10003];
int pa[10003],pn[10003];
char input[1000000];
vector<int> read(){
	vector<int> ret;
	gets(input);
	int len = strlen(input);
	input[len++]=' ';
	input[len]=0;
	int tmp=0;
	for(int i = 0; i < len; i++){
		if(input[i]==' '){
			ret.push_back(tmp);
			tmp=0;
		}
		else tmp=tmp*10+input[i]-'0';
	}
	return ret;
}
void connect(int a, int b){
	G[a].pb(Edge{a,b,1,0,sz(G[b])});
	G[b].pb(Edge{b,a,0,0,sz(G[a])-1});
}
bool SorE(int x){return x==S||x==E;}
int IN(int x){return x;}
int OUT(int x){return SorE(x)?x:5000+x;}
bool edmonds(){
	for(int k = 0; k < K; k++){
		memset(pa,-1,sizeof(pa));
		queue<int> q;
		q.push(S);
		while(!q.empty()){
			int here = q.front();
			q.pop();
			for(int i = 0; i < sz(G[here]); i++){
				auto e = G[here][i];
				if(e.c-e.f<=0 || pa[e.v] != -1) continue;
				pa[e.v] = here;
				pn[e.v] = i;
				q.push(e.v);
			}
		}
		if(pa[E]==-1) return false;
		for(int p=E;p!=S;p=pa[p]){
			auto& e1 = G[pa[p]][pn[p]];
			auto& e2 = G[e1.v][e1.rev];
			e1.f++,e2.f--;
		}
	}
	return true;
}
void dfs(int here){
	if(here<=5000) printf("%d ",here);
	if(here==E) return;
	for(int i = 0; i < sz(G[here]); i++){
		auto& e = G[here][i];
		if(e.f!=1) continue;
		e.f=0;
		dfs(e.v);
		return;
	}
}
int main() {
	for(int t=1;;t++){
		for(int i = 1; i <= 10002; i++) G[i].clear();
		scanf("%d%d ",&K,&N);
		S=1,E=2;
		if(!K&&!N) break;
		printf("Case %d:\n",t);
		bool SandE=false;
		for(int i = 1; i <= N; i++){
			vector<int> ret = read();
			for(int j = 0; j < sz(ret); j++) {
				if(SorE(i)&&SorE(ret[j])) {
					SandE=true;
					continue;
				}
				connect(OUT(i),IN(ret[j]));
				connect(OUT(ret[j]),IN(i));
			}
		}
		if(SandE) connect(S,E);
		for(int i = 3; i <= N; i++) connect(IN(i),OUT(i));
		if(!edmonds()){
			printf("Impossible\n\n");
			continue;
		}
		for(int k = 0; k < K; k++) {
			dfs(S);
			printf("\n");
		}
		printf("\n");
	}
	return 0;
}
