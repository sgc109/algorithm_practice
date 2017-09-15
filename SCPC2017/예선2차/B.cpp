#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

struct Man{ll S, L, D;};
int T,N;
Man mans[5];
int check[1000003];
int main() {
	setbuf(stdout, NULL);
	scanf("%d", &T);
	for(register int t = 1; t <= T; t++){
		memset(check,0,sizeof(check));
		printf("Case #%d\n", t);
		scanf("%d", &N);
		int ok = 1;
		for(register int i = 0 ; i < N; i++) {
			scanf("%lld %lld %lld\n", &mans[i].S, &mans[i].L, &mans[i].D);
			if(mans[i].D) ok = 0;
		}
		if(N > 3 || !ok){
			printf("1\n");
			continue;
		}
		for(register int i = 0 ; i < N; i++){
			ll start = 0;
			for(register ll tt = 1; ; tt++){
				if((mans[i].S * tt % mans[i].L) == (mans[i].L - mans[i].D) % mans[i].L) {
					start = tt;
					break;
				}
			}
			for(register ll j = start; j <= 1000000; j += mans[i].L) check[j]++;
		}
		ll ans = 1;
		for(register int i = 0 ; i <= 1000000; i++) {
			if(check[i] == N){
				ans = i;
				break;
			}
		}
		printf("%lld\n",ans);

	}
	return 0;
}