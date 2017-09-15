#include <bits/stdc++.h>
#define fastio() ios_base::sync_with_stdio(0),cin.tie(0)
using namespace std;
typedef long long ll;
const int mod = 1e9+7;
const int INF = 0x3c3c3c3c;
const long long INFL = 0x3c3c3c3c3c3c3c3c;

int M, K;
int moves[23];
int dp[1100003];
ll h1, h2;
int main() {
	fastio();
	cin >> M >> K;
	for(int i = 0 ; i < K; i++) cin >> moves[i];
	for(int i = 0 ; i < min(M, 1000000); i++) if(!dp[i]) for(int j = 0 ; j < K; j++) dp[i + moves[j]] = 1;
	if(M < 1000000) return !printf("%d")
	
	return 0;
}