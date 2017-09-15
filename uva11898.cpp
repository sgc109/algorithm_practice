#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9+7;
const int INF = 0x3c3c3c3c;
const long long INFL = 0x3c3c3c3c3c3c3c3c;

int A[200003];
int N, Q, T;
int ans;
int main() {
	scanf("%d", &T);
	while(T--){
		scanf("%d",&N);
		for(int i = 0 ; i < N; i++) scanf("%d",&A[i]);
		scanf("%d",&Q);
		for(int i = 0 ; i < Q; i++) {
			int s, e;
			scanf("%d%d",&s, &e);
			s--,e--;
			if(e-s > 10000){
				printf("0\n");
				continue;
			}
			ans = INF;
			vector<int> sorted;
			for(int i = s ; i <= e; i++) sorted.push_back(A[i]);
			sort(sorted.begin(), sorted.end());
			for(int i = 0 ; i < sorted.size()-1; i++) ans = min(ans, abs(sorted[i]-sorted[i+1]));
			printf("%d\n",ans);
		}
	}
	return 0;
}
