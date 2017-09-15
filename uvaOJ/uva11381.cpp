#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod = 1e9+7;
const int inf = 0x3c3c3c3c;
const long long infl = 0x3c3c3c3c3c3c3c3c;

struct edge{
	int to,cap,cost,rev;
};
vector<edge> G[203];
map<int,int> mp;
int dist[203];
int par[203];
int edgeIdx[203];
int inQ[203];
int trans(string s){
	int ret = 0;
	for(int i = 0 ; i < (int)s.size(); i++){
		ret = ret * 26 + s[i]-'a';
	}
	return ret;
}
int HEAD(int x){
	return 2 + x;
}
int TAIL(int x){
	return 2 + 100 + x;
}
void connect(int from, int to, int cap, int cost){
	G[from].push_back({to, cap, cost, (int)G[to].size()});
	G[to].push_back({from, 0, -cost, (int)G[from].size()-1});
}
pair<int,int> mcmf(int src, int sink){
	int maxFlow = 0, minCost = 0;
	while(1){
		memset(inQ,0,sizeof(inQ));
		memset(dist,0x3c,sizeof(dist));
		queue<int> q;
		q.push(src);
		dist[src] = 0;
		while(!q.empty()){
			int here = q.front();
			q.pop();
			inQ[here] = 0;
			for(int i = 0 ; i < (int)G[here].size(); i++){
				auto& e = G[here][i];
				if(e.cap <= 0) continue;
				if(dist[e.to] > dist[here] + e.cost) {
					par[e.to] = here;
					edgeIdx[e.to] = i;
					dist[e.to] = dist[here] + e.cost;
					if(!inQ[e.to]) inQ[e.to] = 1, q.push(e.to);
				}
			}
		}
		if(dist[sink] == inf) break;
		int minFlow = inf;
		int costSum = 0;
		for(int p = sink; p != src; p = par[p]){
			auto e = G[par[p]][edgeIdx[p]];
			minFlow = min(minFlow, e.cap);
			costSum += e.cost;
		}
		for(int p = sink; p != src; p = par[p]){
			auto& e = G[par[p]][edgeIdx[p]];
			e.cap -= minFlow;
			G[e.to][e.rev].cap += minFlow;
		}
		maxFlow += minFlow;
		minCost += costSum * minFlow;
	}
	return {maxFlow, minCost};
}
int main() {
	int src = 0, sink = 1;
	int X;
	cin >> X;
	while(X--){
		mp.clear();
		for(int i = 0 ; i < 203; i++) G[i].clear();
		string s1, s2;
		cin >> s1 >> s2;
		for(int i = 0 ; i < (int)s1.size() -1; i++){
			string stmp = s1.substr(i, 2);
			int h = trans(stmp);
			if(mp[h] == 0) mp[h] = (i+1)*(i+1);
		}
		for(int i = 0 ; i < (int)s2.size(); i++){
			for(int j = i+1; j < (int)s2.size(); j++){
				string stmp;
				stmp += s2[i];
				stmp += s2[j];
				int h = trans(stmp);
				if(mp[h] != 0) connect(TAIL(i), HEAD(j), 1, mp[h]);
			}
		}
		for(int i = 0; i < (int)s2.size(); i++) connect(src, TAIL(i), 1, 0);
		for(int i = 0; i < (int)s2.size(); i++) connect(HEAD(i), sink, 1, 0);
		pair<int,int> ret = mcmf(src, sink);
		cout << (int)s2.size() - ret.first << " " << ret.second << endl;
	}
	return 0;
}