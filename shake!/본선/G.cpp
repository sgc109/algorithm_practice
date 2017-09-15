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
ll ans;
int go(int l, int r){
	if(l == r) return A[l];
	int maxx = -1;
	int idx = 0;
	for(int i = l ; i <= r; i++) {
		if(maxx < A[i]) maxx = A[i], idx = i;		
	}
	int L = -1,R = -1;
	if(l < idx) L = go(l,idx-1);
	if(idx < r) R = go(idx+1,r);
	if(L == -1) ans += abs(maxx - R);
	else if(R == -1) ans += abs(L - maxx);
	else ans += abs(L - maxx) + abs(maxx - R);
	return maxx;
}
int main() {
	cin >> N;
	for(int i = 0 ; i < N; i++) cin >> A[i];
	go(0,N-1);
	cout << ans;
	return 0;
}