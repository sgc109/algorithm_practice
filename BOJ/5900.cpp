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

int bino[5003][13];
int dp[5003][13];
int N, K, L;
string go(int len, int rest, int kth, string ans){
	if(!len) return ans;
	int zero = bino[len - 1][rest];
	if(zero >= kth) return go(len - 1, rest, kth, ans + '0');
	return go(len - 1, rest - 1, kth - zero, ans + '1');
}
int main() {
	fastio();
	cin >> N >> K;
	if(K == 1){
		cout << 1;
		for(int i = 0 ; i < N - 1; i++) cout << 0;
		return 0;
	}
	for(int i = 0; i < 5003; i++) bino[i][0] = 1;
	for(int i = 1 ; i < 5003; i++){
		for(int j = 1 ; j <= min(i, 10); j++){
			bino[i][j] = bino[i - 1][j] + bino[i - 1][j - 1];
		}
	}
	L = 0;
	while(N > bino[K + L][K]) L++;
	L += K;
	cout << go(L, K, N, "");
	
	return 0;
}