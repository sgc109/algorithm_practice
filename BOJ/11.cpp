#include <bits/stdc++.h>
#define fastio() ios_base::sync_with_stdio(false),cin.tie(NULL)
using namespace std;
typedef long long ll;
const int mod = 1e9+7;
const int INF = 0x3c3c3c3c;
const long long INFL = 0x3c3c3c3c3c3c3c3c;

int N, M, K, Q, a, start;
int dist[50003][1024];
vector<int> martId;
int inv[50003];
vector<int> G[50003];
int main() {
	start = 0;
	fastio();
	cin >> N >> M >> K >> Q;
	for(int i = 0 ; i < K; i++) {
		cin >> a;
		martId.push_back(a);
	}
	for(int i = 0 ; i < M; i++){
		int a, b;
		cin >> a >> b;
		G[a].push_back(b);
		G[b].push_back(a);
	}

	for(int i = 0 ; i < K; i++) inv[martId[i]] = i;
	
	for()	
	return 0;
}