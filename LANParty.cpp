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

int lo[100003], hi[100003];
vector<int> query[100003];
int grp[100003];
int cnt[100003];
int N, M, Q;
vector<int> G[100003];
pair<int,int> edges[100003];
vector<int> mem[100003];
int vis[100003];
int par[100003];
int find(int u){
	return u == par[u] ? u : par[u] = find(par[u]);
}
void merge(int a, int b){
	a = find(a), b = find(b);
	if(a == b) return;
	par[a] = b;
}
int main() {
	fastio();
	cin >> N >> M >> Q;
	for(int i = 0 ; i < N; i++) {
		cin >> grp[i];
		grp[i]--;
		cnt[grp[i]]++;
		mem[grp[i]].pb(i);
	}
	for(int i = 0 ; i < Q; i++) {
		int a, b;
		cin >> a >> b;
		a--, b--;
		edges[i] = {a, b};
	}
	for(int i = 0 ; i < M; i++) lo[i] = 0, hi[i] = Q;
	while(1){
		int isEnd = 1;
		for(int i = 0 ; i < M; i++){
			if(lo[i] < hi[i]){
				int mid = (lo[i] + hi[i]) / 2;
				query[mid].pb(i);
				isEnd = 0;
			}
		}
		if(isEnd) break;
		for(int i = 0 ; i < N; i++) par[i] = i;
		for(int i = 0 ; i < Q; i++){
			auto e = edges[i];
			merge(e.first, e.second);
			while(sz(query[i])){
				int id = query[i].back();
				query[i].pop_back();
				int grpId = find(mem[id][0]);
				int ok = 1;
				for(int nd : mem[id]){
					if(find(nd) != grpId) {
						ok = 0;
						break;
					}
				}
				if(!ok) lo[id] = i + 1;
				else hi[id] = i;
			}
		}
	}
	for(int i = 0 ; i < M; i++) {
		int ans = 0;
		if(cnt[i] == 1) ans = 0;
		else if(lo[i] == Q) ans = -1;
		else ans = lo[i] + 1;
		cout << ans << '\n';
	}
	return 0;
}