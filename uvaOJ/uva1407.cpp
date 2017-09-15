#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod = 1e9+7;
const int inf = 0x3c3c3c3c;
const long long infl = 0x3c3c3c3c3c3c3c3c;

int dp1[503][503], dp2[503][503];
int tdp1[503], tdp2[503];
int sz[503];
int n,q;
vector<pair<int,int> > G[503];
int check[503];
int dfs(int here){
	dp1[here][1] = dp2[here][1] = 0;
	sz[here] = 1;
	if(G[here].size() == 0) return sz[here] = 1;
	for(auto p : G[here]) {
		int there = p.first;
		sz[here] += dfs(there);
	}
	int size = 1;
	for(int i = 0 ; i < (int)G[here].size(); i++){
		int there = G[here][i].first;
		int cost = G[here][i].second;
		for(int i = 0 ; i < 503; i++) tdp1[i] = dp1[here][i], tdp2[i] = dp2[here][i];
		for(int k = 1 ; k <= sz[there]; k++){
			tdp1[k] = min(tdp1[k], dp1[there][k-1] + 2 * cost);
			tdp2[k] = min(tdp2[k], dp2[there][k-1] + cost);
			for(int j = 1 ; j <= size; j++){
				tdp1[j+k] = min(tdp1[j+k], dp1[here][j] + dp1[there][k] + 2 * cost);
				tdp2[j+k] = min(tdp2[j+k], dp1[here][j] + dp2[there][k] + cost);
				tdp2[j+k] = min(tdp2[j+k], dp2[here][j] + dp1[there][k] + 2 * cost);
			}
		}
		for(int i = 0 ; i < 503; i++) dp1[here][i] = tdp1[i], dp2[here][i] = tdp2[i];
		size += sz[there];
	}
	
	return sz[here];
}
int main() {
	for(int t = 1; ; t++){
		for(int i = 0 ; i < 503; i++) G[i].clear();
		memset(dp1,0x3c,sizeof(dp1));
		memset(dp2,0x3c,sizeof(dp2));
		memset(check,0,sizeof(check));
		memset(sz,0,sizeof(sz));
		cin >> n;
		if(!n) break;
		for(int i = 0 ; i < n-1; i++){
			int c,p,d;
			cin >> c >> p >> d;
			check[c] = 1;
			G[p].emplace_back(c,d);
		}
		int root = -1;
		for(int i = 0 ; i < n; i++) if(!check[i]) root = i;
		dfs(root);

		cout << "Case " << t << ":" << endl;
		cin >> q;
		for(int i = 0 ; i < q; i++){
			int x;
			cin >> x;
			int pos = upper_bound(dp2[root]+1, dp2[root]+1+sz[root], x) - dp2[root] - 1;
			cout << pos << endl;
		}
	}
	return 0;
}