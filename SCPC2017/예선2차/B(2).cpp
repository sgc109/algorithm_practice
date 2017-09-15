#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF = 0x3c3c3c3c;
const long long INFL = 0x3c3c3c3c3c3c3c3c;

struct Man{ll S, L, D;};
int T,N;
Man mans[5];
ll TT[5];
bool isOk(ll t){
	for(int i = 0 ; i < N; i++){
		if((mans[i].D + mans[i].S * t) % mans[i].L) return false;
	}
	return true;
}
int main() {
	scanf("%d", &T);
	for(int t = 1; t <= T; t++){
		scanf("%d", &N);
		for(int i = 0 ; i < N; i++){
			scanf("%lld %lld %lld\n", &mans[i].S, &mans[i].L, &mans[i].D);
		}
		ll x;
		for(x = 1; x <= 2000000 && !isOk(x); x++);
		printf("Case #%d\n", t);
		printf("%lld\n", x);
	}
	return 0;
}