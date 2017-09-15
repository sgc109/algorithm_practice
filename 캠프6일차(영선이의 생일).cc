// #include <bits/stdc++.h>
// #include <iostream>
#include <unordered_set>
// #include <unordered_map>
#include <vector>
#include <cstdio>
#include <cstring>
#include <queue>
// #include <set>
// #include <map>
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
#define inp5(a,b,c,d,e) scanf("%d%d%d%d%d",&a,&b,&c,&d,&e)
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
const int MOD = 1e9+7;
const int INF = 0x3c3c3c3c;
const long long INFL = 0x3c3c3c3c3c3c3c3c;
const int MAX_N = 5200;

struct Point{int x,y;};
vector<int> sortedX, sortedY;
int newX[10], newY[10];
Point straw[3], cherry[3], candle;
unordered_set<int> usX, usY;
int N,M,S,T;
int dy[]={-1,1,0,0};
int dx[]={0,0,1,-1};
vector<int> G[MAX_N];
int iter[MAX_N],parent[MAX_N],flow[MAX_N][MAX_N],cap[MAX_N][MAX_N],level[MAX_N];
bool isCandle(int i, int j){return i==candle.x&&j==candle.y;}
bool inRange(int i, int j){return 0<=i&&i<N&&0<=j&&j<M;}
int IN(int x){return 2+x;}
int OUT(int x){return 2+N*M+x;}
void connect(int a, int b){
	G[a].push_back(b);
	G[b].push_back(a);
	cap[a][b]=1;
}
int trans(int i, int j){return i*M+j;}
// bool isObj(int i, int j){
// 	FOR(k,3) if(straw[k].x==i&&straw[k].y==j) return true;
// 	FOR(k,3) if(cherry[k].x==i&&cherry[k].y==j) return true;
// 	return candle.x==i&&candle.y==j;
// }
void makeGraph(){
	FOR(i,N){
		FOR(j,M){
			FOR(k,4){
				int ni = i+dy[k], nj = j+dx[k];
				if(!inRange(ni,nj)) continue;

				connect(OUT(trans(i,j)),IN(trans(ni,nj)));
			}
			if(!isCandle(i,j)) connect(IN(trans(i,j)),OUT(trans(i,j)));
		}
	}
}

int dfs(int here){
	if(here==T) return 1;
	for(int& i = iter[here]; i < G[here].size(); ++i){
		int there=G[here][i];
		if(cap[here][there]-flow[here][there]>0 && level[here]+1 == level[there]){
			parent[there]=here;
			if(dfs(there)) return 1;
		}
	}
	return 0;
}

int dinic(){
	int ret=0;
	while(1) {
		memset(level,-1,sizeof(level));
		level[S]=0;
		queue<int> q;
		q.push(S);
		while(!q.empty() && level[T] == -1) {
			int here = q.front();
			q.pop();
			for(auto& there : G[here]){
				if(cap[here][there]-flow[here][there]>0 && level[there] == -1){
					level[there]=level[here]+1;
					q.push(there);
				}
			}
		}
		if(level[T] == -1) break;
		memset(iter,0,sizeof(iter));

		while(1){
			memset(parent,-1,sizeof(parent));
			parent[S]=0;
			if(!dfs(0)) break;
			int minFlow=INF;
			for(int p = 1; p!=parent[p]; p = parent[p]){
				minFlow = min(minFlow, cap[parent[p]][p]-flow[parent[p]][p]);
			}

			for(int p = 1; p!=parent[p]; p = parent[p]){
				flow[parent[p]][p] += minFlow;
				flow[p][parent[p]] -= minFlow;
			}
			ret+=minFlow;
		}
	}
	return ret;
}

int main() {
	scanf("%d%d",&N,&M);
	
	scanf("%d%d",&candle.x,&candle.y);
	candle.x--,candle.y--;
	if(!usX.count(candle.x)) sortedX.push_back(candle.x);
	if(!usY.count(candle.y)) sortedY.push_back(candle.y);

	for(int i = 0; i < 3; i++) {
		scanf("%d%d",&straw[i].x,&straw[i].y);
		straw[i].x--,straw[i].y--;
		if(!usX.count(straw[i].x)) usX.insert(straw[i].x), sortedX.push_back(straw[i].x);
		if(!usY.count(straw[i].y)) usY.insert(straw[i].y), sortedY.push_back(straw[i].y);
	}
	for(int i = 0; i < 3; i++) {
		scanf("%d%d",&cherry[i].x,&cherry[i].y);
		cherry[i].x--,cherry[i].y--;
		if(!usX.count(cherry[i].x)) usX.insert(cherry[i].x), sortedX.push_back(cherry[i].x);
		if(!usY.count(cherry[i].y)) usY.insert(cherry[i].y), sortedY.push_back(cherry[i].y);
	}
	sort(all(sortedX)), sort(all(sortedY));
	
	newX[0] = sortedX[0]>3 ? 3 : sortedX[0];
	for(int i = 0; i < sz(sortedX)-1; i++){
		int diff = sortedX[i+1]-sortedX[i];
		if(diff > 4) diff=4;
		newX[i+1]=newX[i]+diff;
	}
	
	newY[0] = sortedY[0]>3 ? 3 : sortedY[0];
	for(int i = 0; i < sz(sortedY)-1; i++){
		int diff = sortedY[i+1]-sortedY[i];
		if(diff > 4) diff=4;
		newY[i+1]=newY[i]+diff;
	}

	int pos;
	for(int i = 0; i < 3; i++){
		pos = lower_bound(all(sortedX),straw[i].x) - sortedX.begin();
		straw[i].x=newX[pos];
		pos = lower_bound(all(sortedY),straw[i].y) - sortedY.begin();
		straw[i].y=newY[pos];
	}

	for(int i = 0; i < 3; i++){
		pos = lower_bound(all(sortedX),cherry[i].x) - sortedX.begin();
		cherry[i].x=newX[pos];
		pos = lower_bound(all(sortedY),cherry[i].y) - sortedY.begin();
		cherry[i].y=newY[pos];
	}

	pos = lower_bound(all(sortedX),candle.x) - sortedX.begin();
	candle.x=newX[pos];
	pos = lower_bound(all(sortedY),candle.y) - sortedY.begin();
	candle.y=newY[pos];
	

	int diff = N-sortedX.back();
	N = newX[sz(sortedX)-1]+(diff>3?3:diff);
	diff = M-sortedY.back();
	M = newY[sz(sortedY)-1]+(diff>3?3:diff);

	S=0,T=1;
	makeGraph();
	FOR(i,3){
		connect(S,IN(trans(straw[i].x,straw[i].y)));
		connect(OUT(trans(cherry[i].x,cherry[i].y)),T);
	}
	printf("%s", dinic()==3?"Yes":"No");
	return 0;
}
