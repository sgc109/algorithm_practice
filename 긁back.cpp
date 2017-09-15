#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF = 0x3c3c3c3c;
const long long INFL = 0x3c3c3c3c3c3c3c3c;

struct Man{ll S, L, D;};
int T,N;
Man mans[5];
map<ll,int> mp;
int main() {
	setbuf(stdout, NULL);
	scanf("%d", &T);
	for(register int t = 1; t <= T; t++){
		mp.clear();
		printf("Case #%d\n", t);
		scanf("%d", &N);
		for(register int i = 0 ; i < N; i++) scanf("%lld %lld %lld\n", &mans[i].S, &mans[i].L, &mans[i].D);

		if(N > 3){
			printf("1\n");
			continue;
		}
		ll ans = 0;
		for(register int i = 0 ; i < N; i++){
			if(ans) break;
			vector<ll> pos;
			for(register ll tt = 1; ; tt++){
				if((mans[i].S * tt % mans[i].L) == (mans[i].L - mans[i].D) % mans[i].L) pos.push_back(tt);
				if((int)pos.size() == 2) break;
			}
			ll start = pos[0];
			ll dist = pos[1] - pos[0];
			for(register ll j = 0; j < 500003; j ++) {
				mp[start]++;
				if(mp[start]==N) {
					ans = start;
					break;
				}
				start += dist;
			}
		}
		if(!ans) ans = 1;
		printf("%lld\n",ans);

	}
	return 0;
}