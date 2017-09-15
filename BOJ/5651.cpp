#include <bits/stdc++.h>
#define pb push_back
#define sz(v) ((int)(v).size())
#define all(v) (v).begin(), (v).end()
#define fastio() ios_base::sync_with_stdio(false),cin.tie(NULL)
using namespace std;
typedef long long ll;
const int mod = 1e9+7;
const int inf = 0x3c3c3c3c;
const long long infl = 0x3c3c3c3c3c3c3c3c;

int N, M, K;
int flow[303][303], nflow[303][303];
int cap[303][303], ncap[303][303];
int adj[303][303];
int par[303];
vector<pair<int,int> > edges;
int getMaxFlow(int c[303][303], int f[303][303]){
	int ret = 0;
	while(1){
		memset(par,-1,sizeof(par));
		queue<int> q;
		q.push(1);
		while(!q.empty() && par[N] == -1){
			int cur = q.front();
			q.pop();
			for(int nxt = 1 ; nxt <= N; nxt++){
				if(par[nxt] == -1 && adj[cur][nxt] && c[cur][nxt] - f[cur][nxt] > 0) q.push(nxt), par[nxt] = cur;;
			}
		}
		if(par[N] == -1) break;
		int minFlow = inf;
		for(int p = N; p != 1; p = par[p]) minFlow = min(minFlow, c[par[p]][p] - f[par[p]][p]);
		for(int p = N; p != 1; p = par[p]) f[par[p]][p] += minFlow, f[p][par[p]] -= minFlow;
		ret += minFlow;
	}
	return ret;
}
int main() {
	fastio();
	cin >> K;
	while(K--){
		edges.clear();
		memset(adj,0,sizeof(adj));
		memset(cap,0,sizeof(cap));
		memset(flow,0,sizeof(flow));
		cin >> N >> M;
		for(int i = 0 ; i < M; i++){
			int a, b, c;
			cin >> a >> b >> c;
			cap[a][b] = c;
			adj[a][b] = adj[b][a] = 1;
			edges.pb({a, b});
		}
		int mf = getMaxFlow(cap, flow);
		cout << mf << endl;
	}		
	return 0;
}
