#include <bits/stdc++.h>
#define pb push_back
#define sz(v) ((int)(v).size())
#define all(v) (v).begin(), (v).end()
#define fastio() ios_base::sync_with_stdio(false),cin.tie(NULL)
using namespace std;
typedef long long ll;
const int mod = 1e3;
const int inf = 0x3c3c3c3c;
const long long infl = 0x3c3c3c3c3c3c3c3c;

struct node{
	int pos, jmp, good;
};
int N;
int dp[503][503];
node nodes[503];
int main() {
	fastio();
	cin >> N;
	for(int i = 0 ; i < N; i++){
		int a, b, c;
		cin >> a >> b >> c;
		nodes[i] = node{a, b, c};
	}
	dp[0][0] = 1;
	for(int i = 0; i < N; i++){
		for(int j = 0 ; j < N && nodes[i].pos + nodes[i].jmp >= nodes[j].pos; j++){
			if(i == j || !nodes[j].good) continue;
			for(int k = 0; j < i && k < i; k++){
				if(k && k == j) continue;
				if(nodes[k].pos + nodes[k].jmp >= nodes[i].pos) dp[i][j] = (dp[i][j] + dp[k][j]) % mod;
			}
			for(int k = 0 ; i < j && k < j; k++){
				if(k && k == i) continue;
				if(nodes[j].pos - nodes[j].jmp <= nodes[k].pos) dp[i][j] = (dp[i][j] + dp[i][k]) % mod;
			}
		}		
	}
	int ans = 0;
	for(int i = 0 ; i < N - 1; i++){
		for(int j = 0 ; j < N - 1; j++){
			if(nodes[i].pos + nodes[i].jmp >= nodes[N - 1].pos && nodes[N - 1].pos - nodes[N - 1].jmp <= nodes[j].pos) ans = (ans + dp[i][j]) % mod;
		}
	}
	cout << ans;
	return 0;
}