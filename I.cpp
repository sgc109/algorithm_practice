#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF = 0x3c3c3c3c;
const long long INFL = 0x3c3c3c3c3c3c3c3c;

int N;
string S;
int dp[1503][1503][3];
int go(int l, int r, int stat){
	if(l > r) return 0;
	int& cache = dp[l][r][stat];
	if(cache != -1) return cache;
	int ret = 0;
	if(stat == 0){
		if(S[l] == 'B') ret = max(ret, 1 + go(l + 1, r, 1));
		if(S[r] == 'B') ret = max(ret, 1 + go(l, r - 1, 1));
	}
	else if(stat == 1){
		if(S[l] == 'L') ret = max(ret, 1 + go(l + 1, r, 2));
		if(S[r] == 'L') ret = max(ret, 1 + go(l, r - 1, 2));
	}
	else if(stat == 2){
		if(S[l] == 'D') ret = max(ret, 1 + go(l + 1, r, 0));
		if(S[r] == 'D') ret = max(ret, 1 + go(l, r - 1, 0));
	}
	return cache = ret;
}
int main(){
	cin.sync_with_stdio(0), cin.tie(0);
	memset(dp,-1,sizeof(dp));
	cin >> N >> S;
	int ret = go(0, (int)S.size() - 1, 0);
	cout << ret;
	return 0;	
}