#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF = 0x3c3c3c3c;
const long long INFL = 0x3c3c3c3c3c3c3c3c;

vector<ll> getDivs(ll x){
	set<ll> st;
	for(ll i = 2; i * i <= x; i++){
		while(x % i == 0) {
			st.insert(i);
			x /= i;
		}
	}
	if(x != 1) st.insert(x);
	vector<ll> ret(st.begin(), st.end());
	return ret;
}
ll euler(ll n, vector<ll>& divs){
	ll up = n, down = 1;
	for(auto d : divs){
		up *= (d - 1);
		down *= d;
	}
	return up / down;
}

ll fastPow(ll x, ll k, ll mod){
	if(!k) return 1;
	if(k % 2) return x * fastPow(x, k - 1, mod) % mod;
	return fastPow(x * x % mod, k / 2, mod);
}

struct Man{ll S, L, D;};
int T,N;
Man mans[5];
ll TT[5];
ll gcd(ll a, ll b){
	return !b ? a : gcd(b, a % b);
}
int check[10000003];
int main() {
	setbuf(stdout, NULL);
	scanf("%d", &T);
	for(register int t = 1; t <= T; t++){
		printf("Case #%d\n", t);
		scanf("%d", &N);
		for(int i = 0 ; i < N; i++){
			scanf("%lld %lld %lld\n", &mans[i].S, &mans[i].L, &mans[i].D);
			vector<ll> divs = getDivs(mans[i].L);
			ll p = euler(mans[i].L, divs);
			ll tmp = fastPow(mans[i].S, p - 1, mans[i].L);
			TT[i] = ((-mans[i].D + mans[i].L) * tmp) % mans[i].L;
			if(TT[i] == 0) TT[i] = mans[i].L;
		}

		for(register int i = 0 ; i < N; i++){
			for(register int j = 0 ; mans[i].L * j + TT[i] < 10000003; j++){
				check[mans[i].L * j + TT[i]]++;
			}
		}

		int ans = 0;
		for(register int i = 0 ; i < 10000003; i++){
			if(check[i] == N) {
				ans = i;
				break;
			}
		}

		if(!ans){
			ll gg = mans[0].L;
			for(int i = 1; i < N; i++){
				ll tmp1 = gcd(gg, mans[i].L);
				gg = gg * mans[i].L / tmp1;
			}
			printf("%lld\n",gg);
			memset(check,0,sizeof(check));
			continue;
		}

		printf("%d\n", ans);
		memset(check,0,sizeof(check));
	}
	return 0;
}