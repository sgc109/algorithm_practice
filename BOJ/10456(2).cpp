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

int T, N;
ll dp[10003][33][33][2];
int bus[10003], train[10003];
ll go(int pos, int restB, int restT, int now){
	if(pos == N) return 0;
	restB = max(0, restB);
	restT = max(0, restT);
	ll& cache = dp[pos][restB][restT][now];
	if(cache != -1) return cache;
	ll ret = infl;
	if(!now){
		if(!bus[pos] || restB) ret = min(ret, go(pos, restB, restT, now ^ 1));
		else {
			ret = min(ret, bus[pos] + go(pos, 0, restT, now ^ 1));
			ret = min(ret, 3 + go(pos, 0, restT, now ^ 1));
			ret = min(ret, 18 + go(pos, 6, restT, now ^ 1));
			ret = min(ret, 45 + go(pos, 29, restT, now ^ 1));
		}
	}
	else {
		if(!train[pos] || restT) ret = min(ret, go(pos + 1, restB - 1, restT - 1, now ^ 1));
		else {
			ret = min(ret, 2 * train[pos] + )
		}
	}
	return cache = ret;
}
int main() {
	fastio();
	cin >> T;
	while(T--){
		memset(dp,-1,sizeof(dp));
		cin >> N;
		for(int i = 0 ; i < N ; i++){
			cin >> bus[i] >> train[i];
		}
		cout << go(0, 0, 0) << '\n';
	}
	return 0;
}