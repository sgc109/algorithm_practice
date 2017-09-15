#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod = 1e9+7;
const int inf = 0x3c3c3c3c;
const long long infl = 0x3c3c3c3c3c3c3c3c;

int A[5003];
vector<int> nums;
int N;
int S[5003], E[5003];
int imposs[5003];
int jump[5003], add[5003];
int dp[5003];

int go(int pos){
	if(pos == N) return 0;
	int& cache = dp[pos];
	if(cache != -1) return cache;
	if(S[A[pos]] != pos || imposs[A[pos]]) return go(pos+1);
	int ret = 0;
	ret = max(ret, add[A[pos]] + go(jump[A[pos]]));
	ret = max(ret, go(pos+1));

	return cache = ret;
}
int main() {
	memset(dp,-1,sizeof(dp));
	memset(E,-1,sizeof(E));
	memset(S,0x3c,sizeof(S));

	cin >> N;
	for(int i = 0 ; i < N; i++) {
		cin >> A[i];
		if(E[A[i]] == -1) nums.push_back(A[i]);
		S[A[i]] = min(S[A[i]], i);
		E[A[i]] = max(E[A[i]], i);
	}

	for(int num : nums){
		int s = S[num], e = E[num];
		int XOR = 0;
		int end = e;
		for(int i = s ; i <= end; i++){
			if(S[A[i]] < s && s < i && i < end) imposs[num] = 1;
			if(S[A[i]] != i) continue;
			XOR ^= A[i];
			end = max(end, E[A[i]]);
		}
		add[num] = XOR;
		jump[num] = end+1;
	}

	cout << go(0);
	return 0;
}