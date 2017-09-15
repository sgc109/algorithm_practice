#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod = 1e9+7;
const int inf = 0x3c3c3c3c;
const long long infl = 0x3c3c3c3c3c3c3c3c;

int T,N,M;
int a;
vector<int> G[205];
int cap[205][205];
int par[205];
void connect(int a, int b, int c){
	G[a].push_back(b);
	G[b].push_back(a);
	cap[a][b] = c;
}

ll edmonds(int s, int t){
	ll ret = 0;
	while(1){
		memset(par,-1,sizeof(par));
		queue<int> q;
		q.push(s);
		par[s] = s;
		while(!q.empty() && par[t] == -1){
			int here = q.front();
			q.pop();
			for(int there : G[here]){
				if(cap[here][there] == 0 || par[there] != -1) continue;
				par[there] = here;
				q.push(there);
			}
		}
		if(par[t] == -1) break;
		int minFlow = inf;
		for(int p = t ; p != s; p = par[p]) minFlow = min(minFlow, cap[par[p]][p]);
		for(int p = t ; p != s; p = par[p]) cap[par[p]][p] -= minFlow, cap[p][par[p]] += minFlow;
		ret += minFlow;
	}
	return ret;
}
int main() {
	int S = 201, E = 202;
	cin >> T;
	for(int t = 1 ; t <= T; t++){
		memset(cap,0,sizeof(cap));
		for(int i = 0 ; i < 205; i++) G[i].clear();
		cin >> N >> M;
		for(int i = 0 ; i < N; i++){
			 cin >> a;
			 connect(S, i, a);
		}
		for(int i = 0 ; i < N; i++){
			 cin >> a;
			 connect(i, E, a);
		}
		for(int i = 0 ; i < N; i++){
			 cin >> a;
			 if(a == -1) cap[S][i] = inf;
			 else if(a == 1) cap[i][E] = inf;
		}
		for(int i = 0 ; i < M; i++){
			int a, b, c;
			cin >> a >> b >> c;
			a--, b--;
			connect(a, b, c);
			cap[b][a] = c;
		}
		cout << edmonds(S, E) << endl;
	}
	return 0;
}