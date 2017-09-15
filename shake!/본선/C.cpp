// #include <bits/stdc++.h>
#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
#include <vector>
#include <string>
#include <algorithm>
#include <utility>
#include <set>
#include <map>
using namespace std;
typedef long long ll;
const int mod = 1e9+7;
const int inf = 0x3c3c3c3c;
const long long infl = 0x3c3c3c3c3c3c3c3c;

int N,M;
ll X;
ll cost[100003];
ll money[100003];
ll costSum;
ll moneySum;
int isOk(int cnt){
	ll need = 0;
	for(int i = 0 ; i < cnt; i++){
		need += max(0ll, cost[i] - money[N-cnt+i]);
	}
	return need <= X;
}
int main() {
	cin >> N >> M >> X;
	for(int i = 0 ; i < N; i++) cin >> cost[i];
	for(int i = 0 ; i < M; i++) cin >> money[i];
	sort(cost, cost+N);
	sort(money, money+M, std::greater<ll>());
	int back = min(N,M);
	N = M = back;
	sort(money, money+N);
	int lo = 0, hi = N+1;
	while(lo < hi){
		int mid = (lo + hi)/2;
		if(isOk(mid)) lo = mid+1;
		else hi = mid;
	}
	cout << lo-1;
	return 0;
}