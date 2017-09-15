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

int N;
ll ans;
int main() {
	cin >> N;
	for(int i = 0 ; i < N; i++){
		int x,K;
		cin >> x >> K;
		ll tmp = 0;
		ll mult = 1;
		for(int j = 0 ; j < 30; j++){
			if(K & (1<<j)) tmp = (tmp + mult) % mod;
			mult = mult * x % mod;
		}
		ans = (ans + tmp) % mod;
	}
	cout << ans;
	return 0;
}