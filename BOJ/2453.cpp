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

int N, M;
int enemy[10003];
int par[10003];
int size[10003];
int check[10003];
int A[10003];
int dp[2][20003];
int find(int a){
	return par[a] == a ? a : par[a] = find(par[a]);
}
int merge(int a, int b){
	if(a > b) swap(a, b);
	if(a == -1 || b == -1) return max(a, b); 
	if(a == b) return a;
	par[a] = b;
	size[b] += size[a];
	return b;
}
int main() {
	fastio();
	int T = 1;
	for(int t = 0; t < T; t++){
		memset(dp,0,sizeof(dp));
		memset(check,0,sizeof(check));
		cin >> N >> M;
		for(int i = 0 ; i < N; i++) par[i] = i, size[i] = 1, enemy[i] = -1;
		int ok = 1;
		while(M--){
			int a, b, c;
			cin >> a >> b >> c;
			b--, c--;
			b = find(b), c = find(c);
			if(a == 1) {
				if(enemy[b] == c) ok = 0;
				int eb = enemy[b], ec = enemy[c];
				int bc1 = merge(b, c);
				int bc2 = merge(eb, ec);
				enemy[bc1] = bc2, enemy[bc2] = bc1;
			}
			else {
				if(b == c) ok = 0;
				int bc1 = merge(enemy[b], c);
				int bc2 = merge(enemy[c], b);
				enemy[bc1] = bc2, enemy[bc2] = bc1;
			}
		}
		if(!ok) {
			cout << -1 << '\n';
			continue;
		}
		int cnt = 0;
		for(int i = 0 ; i < N; i++){
			int id = find(i);
			if(check[id]) continue;
			check[id] = 1;
			if(enemy[id] != -1) check[enemy[id]] = 1;
			int c = size[id] - (enemy[id] == -1 ? 0 : size[enemy[id]]);
			A[cnt++] = c;
		}
		dp[0][10000] = 1;
		for(int i = 1 ; i <= cnt; i++){
			memset(dp[i & 1],0,sizeof(dp[i & 1]));
			for(int j = 0 ; j <= 20000; j++){
				if(dp[~i & 1][j]) dp[i & 1][j + A[i - 1]] = dp[i & 1][j - A[i - 1]] = 1;
			}
		}
		int ans = inf;
		for(int i = 0; i <= 20000; i++) if(dp[cnt & 1][i]) ans = min(ans, abs(i - 10000));
		cout << ans << '\n';
	}	
	return 0;
}