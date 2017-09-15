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
int A[503];
int dp[503][503];
int winner[503][503];
int main() {
	memset(dp,0x3c,sizeof(dp));
	cin >> N;
	for(int i = 0 ; i < N; i++) cin >> A[i];
	for(int i = 0 ; i < N; i++){
		winner[i][i] = A[i];
		for(int j = i+1 ; j < N; j++) winner[i][j] = max(winner[i][j-1], A[j]);
	}
	for(int i = 0 ; i < N; i++) dp[i][i] = 0;
	for(int len = 2; len <= N; len++){
		for(int i = 0 ; i < N-len+1; i++){
			int j = i+len-1;
			for(int k = i; k <= j-1; k++){
				dp[i][j] = min(dp[i][j], dp[i][k] + dp[k+1][j] + abs(winner[i][k] - winner[k+1][j]));
			}
		}
	}
	cout << dp[0][N-1];
	return 0;
}