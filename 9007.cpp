#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9+7;
const int INF = 0x3c3c3c3c;
const long long INFL = 0x3c3c3c3c3c3c3c3c;

int N, T;
vector<long long> g[2];
long long K;
long long A[4][1003];
int main() {
	scanf("%d",&T);
	while(T--){
		g[0].clear();
		g[1].clear();

		scanf("%lld%d", &K, &N);
		for(int i = 0 ; i < 4; i++){
			for(int j = 0 ; j < N; j++){
				scanf("%lld",&A[i][j]);
			}
		}
		for(int k = 0 ; k < 2; k++){
			for(int i = 0 ; i < N; i++){
				for(int j = 0; j < N; j++){
					long long sum = A[2*k][i] + A[2*k + 1][j];
					g[k].push_back(sum);
				}
			}
		}

		for(int i = 0 ; i < 2; i++) sort(g[i].begin(), g[i].end());

		long long ans = INFL;
		for(long long u1 : g[0]){
			auto it2 = lower_bound(g[1].begin(), g[1].end(), K - u1);
			if(it2 != g[1].end()) {
				long long sum = u1 + (*it2);
				if(abs(ans - K) > abs(sum - K)) ans = sum;
				if(abs(ans - K) == abs(sum - K) && ans > sum) ans = sum;
			}
			if(it2 != g[1].begin()) {
				it2--;
				long long sum = u1 + (*it2);
				if(abs(ans - K) > abs(sum - K)) ans = sum;
				if(abs(ans - K) == abs(sum - K) && ans > sum) ans = sum;
			}
		}
		printf("%lld\n", ans);
	}

	return 0;
}
