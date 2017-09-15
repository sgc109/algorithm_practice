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
int dp[1 << 12][1 << 12];
string like[13];
int likeB[13], likeG[13];
int go(int boy, int girl){
	// printf("boy : %d, girl : %d\n", boy, girl);
	int cond1 = boy == (1 << N) - 1;
	int cond2 = girl == (1 << M) - 1;
	if(cond1 || cond2) return cond1 && cond2 ? 0 : inf;
	int& cache = dp[boy][girl];
	if(cache != -1) return cache;
	int ret = inf;
	for(int i = 0 ; i < N; i++){
		int mask = likeB[i] & ~girl;
		for(int nxt = mask; nxt ; nxt = (nxt - 1) & mask) {
			ret = min(ret, 1 + go(boy | 1 << i, girl | nxt));	
		}
	}
	for(int i = 0 ; i < N; i++){
		int mask = likeG[i] & ~boy;
		for(int nxt = mask; nxt ; nxt = (nxt - 1) & mask) {
			ret = min(ret, 1 + go(boy | nxt, girl | 1 << i));	
		}
	}
	return cache = ret;
}
int main() {
	fastio();
	memset(dp,-1,sizeof(dp));
	cin >> N >> M;
	for(int i = 0 ; i < N; i++) cin >> like[i];
	for(int i = 0 ; i < N; i++){
		for(int j = 0 ; j < M; j++){
			if(like[i][j] == '1') likeB[i] |= 1 << j;
		}
	}

	for(int i = 0 ; i < M; i++){
		for(int j = 0 ; j < N; j++){
			if(like[j][i] == '1') likeG[i] |= 1 << j;
		}
	}
	int ret = go(0, 0);
	if(ret == inf) ret = -1;
	cout << ret;
	return 0;
}