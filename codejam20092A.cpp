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

vector<int> v;
int T, N;
int main() {
	scanf("%d", &T);
	for(int t = 1; t <= T; t++){
		scanf("%d", &N);
		for(int i = 0 ; i < N; i++) {
			string s;
			cin >> s;
			int pos;
			for(pos = N - 1; pos >= 0 && s[pos] != '1'; pos--);
			v.pb(pos);
		}
		int ans = 0;
		for(int i = 0 ; i < N; i++){
			int pos;
			for(pos = 0 ; pos < N - i && v[pos] > i; pos++);
			ans += pos;
			v.erase(v.begin() + pos);
		}

		printf("Case #%d: %d\n", t, ans);
	}
	return 0;
}