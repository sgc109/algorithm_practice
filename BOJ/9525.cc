// #include <bits/stdc++.h>
#include <vector>
#include <cstdio>
#include <iostream>
#include <cstring>
#include <queue>
#include <set>
// #include <map>
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

int selX[103][103],selY[103][103],matchedX[10003],matchedY[10003];
int N;
char map[103][103];
vector<int> G[10003];
bool inRange(int i, int j){
	return 0<=i&&i<N&&0<=j&&j<N;
}
void numbering(int ni, int nj, int num, int garo){
	if(garo){
		int l; for(l=nj;l>=0&&map[ni][l]!='X';l--){}
		for(int j=l+1;j<N&&map[ni][j]!='X';j++){
			selX[ni][j]=num;
			if(selY[ni][j]!=-1) G[num].pb(selY[ni][j]);
		}
		return;
	}
	int l; for(l=ni;l>=0&&map[l][nj]!='X';l--){}
	for(int i=l+1;i<N&&map[i][nj]!='X';i++){
		selY[i][nj]=num;
		if(selX[i][nj]!=-1) G[selX[i][nj]].pb(num);
	}
}
int cntX,cntY;
int visited[10003];
bool dfs(int here){
	if(visited[here]) return false;
	visited[here]=1;
	for(int there : G[here]){
		if(matchedY[there]==-1 || dfs(matchedY[there])){
			matchedY[there] = here;
			matchedX[here] = there;
			return true;
		}
	}
	return false;
}
int bipartite(){
	memset(matchedX,-1,sizeof(matchedX));
	memset(matchedY,-1,sizeof(matchedY));
	int ret=0;
	FOR(i,cntX){
		memset(visited,0,sizeof(visited));
		if(dfs(i)) ret++;
	}
	return ret;
}
int main() {
	memset(selX,-1,sizeof(selX));
	memset(selY,-1,sizeof(selY));
	inp1(N);
	FOR(i,N) scanf("%s",map[i]);
	FOR(i,N){
		FOR(j,N){
			if(map[i][j]=='X') continue;
			if(selX[i][j]==-1) numbering(i,j,cntX++,1);
			if(selY[i][j]==-1) numbering(i,j,cntY++,0);
		}
	}
	int cnt = bipartite();
	printf("%d",cnt);
	return 0;
}
