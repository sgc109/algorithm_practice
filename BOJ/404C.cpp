#include <bits/stdc++.h>
#define pb push_back
#define sz(v) ((int)(v).size())
#define all(v) (v).begin(), (v).end()
#define fastio() ios::sync_with_stdio(0),cin.tie(0)
using namespace std;
typedef long long ll;
const int mod = 1e9+7;
const int inf = 0x3c3c3c3c;
const ll infl = 0x3c3c3c3c3c3c3c3c;

int N;
ll K;
vector<int> nodes[100003];
vector<int> G[100003];
int pos[100003];
int main() {
	fastio();
	cin >> N >> K;
	for(int i = 1 ; i <= N; i++) {
		int a;
		cin >> a;
		nodes[a].pb(i);
	}
	if(sz(nodes[0]) != 1) return !printf("-1");
	for(int i = 0; i < N - 1; i++){
		if(!i) {
			if(sz(nodes[i]) * K < sz(nodes[i + 1])) return !printf("-1");
		}
		else if(sz(nodes[i]) * (K - 1) < sz(nodes[i + 1])) return !printf("-1");
	}
	for(int i = 1; i < N; i++){
		while(sz(nodes[i])){
			int siz = sz(G[nodes[i - 1][pos[i - 1]]]);
			if(i == 1) {
				if(siz == K) pos[i - 1]++;
			}
			else if(siz == K - 1) pos[i - 1]++;
			int u = nodes[i - 1][pos[i - 1]];
			int v = nodes[i].back();
			G[u].pb(v);
			nodes[i].pop_back();
		}
	}
	cout << N - 1 << '\n';
	for(int u = 1; u <= N; u++){
		for(int v : G[u]){
			cout << u << ' ' << v << '\n';
		}
	}
	return 0;
}