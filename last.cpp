#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

struct Man{ll S, L, D;};
int T,N;
Man mans[5];
ll gcd(ll a, ll b){
	return !b ? a : gcd(b, a % b);
}
int main() {
	setbuf(stdout, NULL);
	scanf("%d", &T);
	for(register int t = 1; t <= T; t++){
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

		vector<ll> ggg;
		for(register int i = 0 ; i < N; i++){
			ll g = gcd(mans[i].S, mans[i].L);
			ll tmp = mans[i].L / g;
			ggg.push_back(tmp);
		}
		ll ans = ggg[0];
		for(register int i = 1; i < N; i++){
			ll tmp = gcd(ans, ggg[i]);
			ans = ans * ggg[i] / tmp;
		}
		
		printf("%lld\n",ans);

	}
	return 0;
}