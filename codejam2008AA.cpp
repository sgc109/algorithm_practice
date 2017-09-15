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

int T, N;
int A[803], B[803];
int main() {
	scanf("%d", &T);
	for(int t = 1; t <= T; t++){
		scanf("%d", &N);
		for(int i = 0 ; i < N; i++) scanf("%d", A + i);
		for(int i = 0 ; i < N; i++) scanf("%d", B + i);
		sort(A, A + N);
		sort(B, B + N, greater<int>());
		ll ans = 0;
		for(int i = 0 ; i < N; i++) ans += (ll)A[i] * B[i];
		printf("Case #%d: %lld\n", t, ans);
	}
	return 0;
}