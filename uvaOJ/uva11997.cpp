#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9+7;
const int INF = 0x3c3c3c3c;
const long long INFL = 0x3c3c3c3c3c3c3c3c;

int T,K;
int A[753][753];
long long knum[753];
int main() {
	while(scanf("%d",&K) != -1){
		memset(knum, 0, sizeof(0));
		for(int i = 0 ; i < K; i++) for(int j = 0 ; j < K; j++) scanf("%d",&A[i][j]);
		for(int i = 0 ; i < K; i++) sort(A[i], A[i]+K);
		for(int i = 0 ; i < K; i++) knum[i] = A[0][i];
		for(int i = 1 ; i < K; i++){
			priority_queue<pair<long long, int> > pq;
			for(int j = 0 ; j < K; j++) pq.push({-(knum[j] + A[i][0]), 0});
			for(int j = 0 ; j < K; j++) {
				auto p = pq.top();
				pq.pop();
				long long sum = -p.first;
				int idx = p.second;
				knum[j] = sum;
				if(idx < K-1) pq.push({-(sum - A[i][idx] + A[i][idx+1]), idx+1});
			}
		}
		for(int i = 0 ; i < K; i++) printf("%lld",knum[i]), printf("%c"," \n"[i==K-1]);
	}
	return 0;
}
