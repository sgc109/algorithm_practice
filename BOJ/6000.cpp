#include <bits/stdc++.h>
#define fastio() ios_base::sync_with_stdio(0),cin.tie(0)
using namespace std;
typedef long long ll;
const int mod = 1e9+7;
const int INF = 0x3c3c3c3c;
const long long INFL = 0x3c3c3c3c3c3c3c3c;

int N;
int A[2003];
int acc[2003];
int dp[2003][2003];
int go(int coinCnt, int prev){
	if(!coinCnt) return 0;
	int& cache = dp[coinCnt][prev];
	if(cache != INF) return cache;
	int ret = -INF;
	for(int i = 1; i <= min(2 * prev, coinCnt); i++){
		int g = go(coinCnt - i, i);
		int add = acc[coinCnt] - acc[coinCnt - i];
		ret = max(ret, -g + add);
	}
	return cache = ret;
}
int main() {
	memset(dp,0x3c,sizeof(dp));
	fastio();
	cin >> N;
	for(int i = 0 ; i < N; i++) cin >> A[i];
	for(int i = 1; i <= N; i++) acc[i] = acc[i - 1] + A[i - 1];
	int ret = go(N, 1);
	cout << (acc[N] + ret) / 2;
	return 0;
}