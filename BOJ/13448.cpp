#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod = 1e9+7;
const int inf = 0x3c3c3c3c;
const long long infl = 0x3c3c3c3c3c3c3c3c;

int N,T;
ll M[53],P[53],R[53];
int dp[53][100003];
int calcScore(int t, int id){
	return max(0ll, M[id] - t*P[id]);
}
int main() {
	memset(dp,0xcc,sizeof(dp));
	cin >> N >> T;
	for(int i = 1 ; i <= N; i++) cin >> M[i];
	for(int i = 1 ; i <= N; i++) cin >> P[i];
	for(int i = 1 ; i <= N; i++) cin >> R[i];
	for(int i = 1 ; i <= N; i++){
		for(int j = i+1; j <= N; j++){
			if(M[i] * P[j] > M[j] * P[i]) {
				swap(M[i], M[j]);
				swap(P[i], P[j]);
				swap(R[i], R[j]);
			}
			else if(M[i] * P[j] == M[j] * P[i]){
				if(M[i] < M[j]){
					swap(M[i], M[j]);
					swap(P[i], P[j]);
					swap(R[i], R[j]);		
				}
			}
		}
	}
	dp[0][0] = 0;
	for(int i = 1 ; i <= N; i++){
		for(int j = 0 ; j <= T; j++){
			if(j+R[i] <= T) dp[i][j+R[i]] = max(dp[i][j+R[i]], dp[i-1][j] + calcScore(j+R[i], i));
			dp[i][j] = max(dp[i][j], dp[i-1][j]);
		}
	}
	int ans = -1;
	for(int i = 0 ; i <= T; i++) ans = max(ans, dp[N][i]);
	cout << ans;
	return 0;
}