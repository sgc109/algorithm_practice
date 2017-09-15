#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod = 1e9+7;
const int inf = 0x3c3c3c3c;
const long long infl = 0x3c3c3c3c3c3c3c3c;

int N;
long long K;
int G[200003][2];

int main() {
	scanf("%d",&N);
	for(int i = 1 ; i <= N; i++){
		int a,b;
		scanf("%d%d",&a,&b);
		G[i][0] = a, G[i][1] = b;
	}
	scanf("%lld",&K);
	K--;
	int cur = 1, prev = -1;
	while(cur <= N && cur != -1) {
		prev = cur;
		if(!K) {
			if(G[cur][0] == -1) cur = G[cur][1];
			else cur = G[cur][0];
		}
		else if(G[cur][0] == -1 || G[cur][1] == -1) cur = max(G[cur][0], G[cur][1]);
		else cur = (K % 2 ? G[cur][1] : G[cur][0]), K/=2;
	}

	printf("%d",prev);
	return 0;
}
