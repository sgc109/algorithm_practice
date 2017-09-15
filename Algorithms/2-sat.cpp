#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod = 1e9+7;
const int inf = 0x3c3c3c3c;
const long long infl = 0x3c3c3c3c3c3c3c3c;

int T,D,C,V;
string votes[500][2];
vector<int> G[1003];
vector<int> Gr[1003];
stack<int> stck;
int visited[1003];
int sccId[1003];
int isTrue[1003];
int sccCnt;
int NOT(int x){
	return x^1;
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
	freopen("output.txt","w",stdout);
	cin >> T;
	while(T--){
		sccCnt = 0;
		memset(visited,0,sizeof(visited));
		memset(isTrue,-1,sizeof(isTrue));
		memset(sccId,-1,sizeof(sccId));
		for(int i = 0 ; i < 1003; i++) G[i].clear(), Gr[i].clear();

		cin >> C >> D >> V;
		for(int i = 0 ; i < V; i++) cin >> votes[i][0] >> votes[i][1];
		for(int i = 0 ; i < V; i++){
			for(int j = i+1; j < V; j++){
				if(votes[i][0] == votes[j][1] || votes[i][1] == votes[j][0]){ // 서로 모순되면
					connect(i,j);
				} 
			}
		}

		for(int i = 0 ; i < 2*V; i++) dfs1(i);
		
		while(!stck.empty()) {
			int top = stck.top();
			stck.pop();
			if(sccId[top] != -1) continue;
			dfs2(top);
			sccCnt++;
		}

		vector<pair<int,int> > sorted;
		for(int i = 0 ; i < 2*V; i++) sorted.push_back({sccId[i],i});
		sort(sorted.begin(), sorted.end());
		for(auto p : sorted){
			int num = p.second;
			if(isTrue[num/2] != -1) continue;
			isTrue[num/2] = num&1;
		}
		int cnt = 0;
		for(int i = 0 ; i < V; i++) cnt += isTrue[i];
		cout << cnt << endl;
	}	
	return 0;
}
