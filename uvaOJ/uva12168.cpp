#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod = 1e9+7;
const int inf = 0x3c3c3c3c;
const long long infl = 0x3c3c3c3c3c3c3c3c;

int T,D,C,V;
string votes[500][2];
vector<int> G[1003];
int visited[1003];
int matched[1003];

int dfs(int a){
	if(visited[a]) return 0;
	visited[a] = 1;
	for(int b : G[a]){
		if(matched[b] == -1 || dfs(matched[b])){
			matched[b] = a;
			matched[a] = b;
			return 1;
		}
	}
	return 0;
}
int main() {
	cin >> T;
	while(T--){
		for(int i = 0 ; i < 1003; i++) G[i].clear();

		cin >> C >> D >> V;
		for(int i = 0 ; i < V; i++) cin >> votes[i][0] >> votes[i][1];
		for(int i = 0 ; i < V; i++){
			for(int j = i+1; j < V; j++){
				if(votes[i][0] == votes[j][1] || votes[i][1] == votes[j][0]){ // 서로 모순되면
					G[i].push_back(j);
					G[j].push_back(i);
				} 
			}
		}

		int cnt = 0;
		memset(matched,-1,sizeof(matched));
		for(int i = 0 ; i < V; i++){
			memset(visited,0,sizeof(visited));
			if(matched[i] == -1 && dfs(i)) cnt++;
		}
		cout << V - cnt << endl;
	}	
	return 0;
}
