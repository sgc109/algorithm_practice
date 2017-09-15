#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod = 1e9+7;
const int inf = 0x3c3c3c3c;
const long long infl = 0x3c3c3c3c3c3c3c3c;

int N,M;
int G[203][203];
int cntn[203];
int main() {
	scanf("%d%d",&N,&M);
	for(int i = 0 ; i < M; i++){
		int a,b;
		scanf("%d%d",&a,&b);
		G[a][b] = G[b][a] = 1;
	}

	long long ans = 0;
	for(int i = 1; i <= N; i++){
		memset(cntn,0,sizeof(cntn));
		int cnt = 0;
		for(int j = 1 ; j <= N; j++){
			for(int k = j+1; k <= N; k++){
				if(i == k || i == j || j == k) continue;
				if(!G[i][k] || !G[i][j] || !G[j][k]) continue;
				cnt++;
				cntn[j]++;
				cntn[k]++;
			}
		}
		int tmp = cnt*(cnt-1)/2;
		for(int j = 1; j <= N; j++){
			if(j==i) continue;
			tmp -= cntn[j]*(cntn[j]-1)/2;
		}
		ans += tmp;
	}

	printf("%lld",ans);
	return 0;
}
