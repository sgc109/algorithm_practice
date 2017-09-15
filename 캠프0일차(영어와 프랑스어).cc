// #include <bits/stdc++.h>
#include <unordered_set>
#include <unordered_map>
// #include <iostream>
#include <vector>
#include <cstdio>
#include <cstring>
#include <queue>
#include <set>
#include <map>
#include <cmath>
#include <algorithm>
#include <utility>
#include <string>
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
const double PI = acos(-1);
const int MOD = 1000000007;
const int INF = 0x3c3c3c3c;
const long long INFL = 0x3c3c3c3c3c3c3c3c;
const int MAX_N = 102;

struct Edge{int u,v,c,f,rev;};
int T,N,W,S,E;
char input[12000];
unordered_set<string> sent[203];
unordered_map<string,int> words;
vector<Edge> G[200003];
int pa[200003],pn[200003];
void connect(int a, int b, int c){
	G[a].push_back(Edge{a,b,c,0,sz(G[b])});
	G[b].push_back(Edge{b,a,c,0,sz(G[a])-1});
}
int edmonds(){
	int ret=0;
	while(1){
		memset(pa,-1,sizeof(pa));
		queue<int> q;
		q.push(S);
		while(!q.empty()){
			int here = q.front();
			q.pop();
			for(int i = 0; i < sz(G[here]); i++){
				auto e = G[here][i];
				if(e.c-e.f<=0 || pa[e.v]!=-1) continue;
				pa[e.v]=here;
				pn[e.v]=i;
				q.push(e.v);
			}
		}
		if(pa[E]==-1) break;
		for(int p=E;p!=S;p=pa[p]){
			auto& e1 = G[pa[p]][pn[p]];
			auto& e2 = G[e1.v][e1.rev];
			e1.f++,e2.f--;
		}
		ret++;
	}
	return ret;
}
int SNT(int x){return 2+x;}
int WRD(int x){return 2+N+x;}
int main() {
	S=0,E=1;
	char spc[]=" ";
	scanf("%d ",&T);
	for(int t = 1; t <= T; t++){
		words.clear();
		for(int i = 0; i < 203; i++) sent[i].clear();
		for(int i = 0; i < 200003; i++) G[i].clear();
		W=0;
		scanf("%d ",&N);
		for(int i = 0; i < N; i++){
			gets(input);
			char *tok = strtok(input,spc);
			while(tok){
				string add = string(tok);
				if(!(sent[i].count(add))) sent[i].insert(add);
				if(!(words.count(add))) words[add]=W++;
				tok = strtok(0,spc);
			}
		}
		for(int i = 0; i < N; i++){
			for(auto it = words.begin(); it != words.end(); it++){
				if(sent[i].count((*it).first)) connect(SNT(i),WRD((*it).second),1);
			}
		}
		
		connect(S,SNT(0),INF);
		connect(SNT(1),E,INF);
		int ans = edmonds();
		printf("Case #%d: %d\n",t,ans);
	}
	return 0;
}
