#include <bits/stdc++.h>
#include <map>
using namespace std;
typedef long long ll;
const int mod = 1e9+7;
const int inf = 0x3c3c3c3c;
const long long infl = 0x3c3c3c3c3c3c3c3c;

int N;
int A[2000];
int dp[2000][2000];
int go(int i, int j){
	if(i == N) return 0;
	int& cache = dp[i][j+1];
	if(cache != -1) return cache;
	return cache = min(go(i+1,j) + (!i ? 0 : abs(A[i] - A[i-1])), go(i+1,i-1) + (j<0 ? 0 : abs(A[i] - A[j])));
}
int main() {
	memset(dp,-1,sizeof(dp));
	cin >> N;
	for(int i = 0 ; i < N; i++) cin >> A[i];
	cout << go(0,-1);
	return 0;
}