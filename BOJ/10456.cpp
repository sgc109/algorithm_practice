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
int dp[10003][33][33];
int bus[10003], train[10003];
int go(int pos, int restB, int restT){
	if(pos == N) return 0;
	restB = max(0, restB);
	restT = max(0, restT);
	int& cache = dp[pos][restB][restT];
	if(cache != -1) return cache;
	int ret = inf;
	if(!bus[pos] || restB) { // 버스에 돈 쓸 필요 없을 때
		if(restT) ret = min(ret, go(pos + 1, restB - 1, restT - 1)); // 기차에도 돈 쓸 필요 없다면
		else { // 기차에는 돈 쓸 필요 있다면
			ret = min(ret, 2 * train[pos] + go(pos + 1, restB - 1, 0)); // 기차만 낱개로 따로 사던가
			ret = min(ret, 6 + go(pos + 1, restB - 1, 0)); // 하루 여행권 사던가
			ret = min(ret, 36 + go(pos + 1, 6, 6)); // 일주일 여행권 사던가
			ret = min(ret, 90 + go(pos + 1, 29, 29)); // 한달 여행권 사던가
		}
	}
	else { // 버스에 돈 써야 할 때
		if(restT) { // 기차에는 돈 쓸 필요 없다면
			ret = min(ret, bus[pos] + go(pos + 1, 0, restT - 1)); // 버스 이용권만 낱개로 따로 사던가
			ret = min(ret, 3 + go(pos + 1, 0, restT - 1)); // 하루 버스 이용권 사던가
			ret = min(ret, 18 + go(pos + 1, 6, restT - 1)); // 일주일 버스 이용권 사던가
			ret = min(ret, 45 + go(pos + 1, 29, restT - 1)); // 한달 버스 이용권 사던가
		}
		else { // 버스, 기차 둘다 돈 써야 할 때
			ret = min(ret, bus[pos] + 2 * train[pos] + go(pos + 1, 0, 0)); // 버스, 기차 각각 낱개로 따로 사던가
			ret = min(ret, 2 * train[pos] + 3 + go(pos + 1, 0, 0)); // 하루 버스 이용권 사던가
			ret = min(ret, 2 * train[pos] + 18 + go(pos + 1, 6, 0)); // 일주일 버스 이용권 사던가
			ret = min(ret, 2 * train[pos] + 45 + go(pos + 1, 29, 0)); // 한달 버스 이용권 사던가	
			ret = min(ret, 6 + go(pos + 1, 0, 0)); // 하루 여행권 사던가
			ret = min(ret, 36 + go(pos + 1, 6, 6)); // 일주일 여행권 사던가
			ret = min(ret, 90 + go(pos + 1, 29, 29)); // 한달 여행권 사던가
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