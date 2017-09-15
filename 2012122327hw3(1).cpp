#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod = 1e9+7;
const int inf = 0x3c3c3c3c;
const long long infl = 0x3c3c3c3c3c3c3c3c;

int N,D,K,S,T,a;
vector<int> G[330];
int cap[330][330];
int dishLim[103];
int par[330];
int MAN(int x){return 2+x;}
int DISH(int x){return 2+200+x;}
void connect(int a, int b, int c){
	G[a].push_back(b);
	G[b].push_back(a);
	cap[a][b] = c;
}
int edmonds(){
	int ret = 0;
	while(1){
		memset(par,-1,sizeof(par));
		queue<int> q;
		q.push(S);
		while(!q.empty() && par[T] == -1){
			int here = q.front();
			q.pop();
			for(int there : G[here]){
				if(par[there] != -1 || cap[here][there] <= 0) continue;
				par[there] = here;
				q.push(there);
			}
		}
		if(par[T] == -1) break;
		par[S] = 0;
		int minF = inf;
		for(int p = T ; par[p] != p ; p = par[p]) minF = min(minF, cap[par[p]][p]);
		for(int p = T ; par[p] != p ; p = par[p]) cap[par[p]][p] -= minF, cap[p][par[p]] += minF;
		ret += minF;
	}
	return ret;
}
int main() {
	S = 0, T = 1;
	cin >> N >> K >> D;
	for(int i = 0 ; i < D; i++) {
		cin >> a;
		connect(DISH(i), T, a);
	}
	for(int i = 0 ; i < N; i++) {
		int n;
		cin >> n;
		for(int j = 0 ; j < n; j++){
			cin >> a;
			a--;
			connect(MAN(i), DISH(a), 1);
		}
	}
	for(int i = 0 ; i < N; i++) connect(S, MAN(i), K);
	cout << edmonds();
	return 0;
}