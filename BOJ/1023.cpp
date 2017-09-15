#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod = 1e9+7;
const int inf = 0x3c3c3c3c;
const long long infl = 0x3c3c3c3c3c3c3c3c;

ll dp[53][103][2];
int N;
ll K;
ll go(int pos, int cnt, int wrong){
	ll&cache = dp[pos][cnt+N][wrong];
	if(pos==N) return cache = wrong || cnt!=0;
	if(cache != -1) return cache;
	cache = 0;
	cache += go(pos+1, cnt+1, wrong);
	cache += go(pos+1, cnt-1, wrong || cnt <= 0);

	return cache;
}
void go2(int pos, int cnt, int wrong, ll k){
	if(pos == N) return;
	if(dp[pos+1][cnt+1+N][wrong] >= k) {
		if(pos==N-1&&k==2) printf(")");
		else printf("(");
		go2(pos+1, cnt+1, wrong, k);
	}
	else {
		printf(")");
		go2(pos+1, cnt-1, wrong || cnt <= 0, k - dp[pos+1][cnt+1+N][wrong]);
	}
}
int main() {
	memset(dp,-1,sizeof(dp));
	scanf("%d%lld",&N,&K);
	go(0,0,0);
	if(K+1 > dp[0][N][0]) return !printf("-1");
	go2(0,0,0,K+1);
	return 0;
}
