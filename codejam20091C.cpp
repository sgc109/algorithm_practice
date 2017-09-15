// #include <bits/stdc++.h>
#include <set>
#include <map>
#include <cmath>
#include <stack>
#include <queue>
#include <cstdio>
#include <vector>
#include <cstring>
#include <utility>
#include <iostream>
#include <algorithm>
#define pb push_back
#define sz(v) ((int)(v).size())
#define all(v) (v).begin(), (v).end()
using namespace std;
typedef long long ll;
const int mod = 1e9+7;
const int inf = 0x3c3c3c3c;
const long long infl = 0x3c3c3c3c3c3c3c3c;
int T, P, Q, N;
int A[103];
int dp[103][103];
int main() {
	scanf("%d", &T);
	for(int t = 1; t <= T; t++){
		memset(dp,0x3c,sizeof(dp));
		scanf("%d %d", &P, &Q);
		for(int i = 0 ; i < Q; i++) scanf("%d", A + i + 1);
		A[0] = 0;
		A[Q + 1] = P + 1;
		N = Q + 2;
		for(int i = 0 ; i < N - 1; i++) dp[i][i + 1] = 0;
		for(int len = 2; len < N; len++){
			for(int i = 0 ; i < N - len; i++) {
				int j = i + len;
				for(int k = i + 1; k < j; k++){
					dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j] + A[j] - A[i] - 2);
				}
			}
		}
		printf("Case #%d: %d\n", t, dp[0][N - 1]);
	}	
	return 0;
}