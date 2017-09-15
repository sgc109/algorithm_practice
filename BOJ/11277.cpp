#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod = 1e9+7;
const int inf = 0x3c3c3c3c;
const long long infl = 0x3c3c3c3c3c3c3c3c;

int T,D,C,V;
string votes[500][2];
vector<int> G[20003];
vector<int> Gr[20003];
stack<int> stck;
int visited[20003];
int sccId[20003];
int isTrue[20003];
int sccCnt;
int N,M;
int NOT(int x){
	return x^1;
}
int TRANS(int x){
	if(x < 0) return 2*(-x-1)+1;
	return 2*(x-1);
}
void connect(int u, int v){
	u*=2, v*=2;
	G[u].push_back(NOT(v));
	Gr[NOT(v)].push_back(u);

	G[v].push_back(NOT(u));
	Gr[NOT(u)].push_back(v);
}

void dfs1(int u){
	if(visited[u]) return;
	visited[u] = 1;
	for(int v : G[u]) dfs1(v);
	stck.push(u);
}

void dfs2(int u){
	if(sccId[u] != -1) return;
	sccId[u] = sccCnt;
	for(int v : Gr[u]) dfs2(v);
}

int main() {
	sccCnt = 0;
	memset(visited,0,sizeof(visited));
	memset(isTrue,-1,sizeof(isTrue));
	memset(sccId,-1,sizeof(sccId));
	for(int i = 0 ; i < 1003; i++) G[i].clear(), Gr[i].clear();

	cin >> N >> M;
	for(int i = 0 ; i < M; i++){
		int a,b;
		cin >> a >> b;
		G[NOT(TRANS(a))].push_back(TRANS(b));
		G[NOT(TRANS(b))].push_back(TRANS(a));
		Gr[TRANS(b)].push_back(NOT(TRANS(a)));
		Gr[TRANS(a)].push_back(NOT(TRANS(b)));

	}
	for(int i = 0 ; i < 2*N; i++) dfs1(i);
	
	while(!stck.empty()) {
		int top = stck.top();
		stck.pop();
		if(sccId[top] != -1) continue;
		dfs2(top);
		sccCnt++;
	}

	for(int i = 0 ; i < 2*N; i+=2){
		if(sccId[i] == sccId[i+1]) return !printf("0");
	}
	printf("1\n");
	vector<pair<int,int> > sorted;
	for(int i = 0 ; i < 2*N; i++) sorted.push_back({sccId[i],i});
	sort(sorted.begin(), sorted.end());
	for(auto p : sorted){
		int sccNum = p.first;
		int num = p.second;
		if(isTrue[num/2] != -1) continue;
		isTrue[num/2] = num&1;
	}
	for(int i = 0 ; i < N; i++) printf("%d ",isTrue[i]);
	return 0;
}
