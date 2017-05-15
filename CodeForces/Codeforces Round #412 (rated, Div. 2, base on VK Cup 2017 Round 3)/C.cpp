#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9+7;
const int INF = 0x3c3c3c3c;
const long long INFL = 0x3c3c3c3c3c3c3c3c;
typedef long long ll;
int t;
ll x,y,p,q;

ll gcd(ll a, ll b){
	return b ? gcd(b, a%b) : a;
}
bool possi(long long pp, long long qq){
	if(x > pp || y > qq) return false;
	ll up = pp - x;
	ll down = qq - y;
	return up <= down;
}
int main() {
	scanf("%d",&t);
	for(int i = 0; i < t; i++){
		scanf("%lld%lld%lld%lld",&x,&y,&p,&q);
		ll g = gcd(x,y);
		if(x/g == p && y/g == q) {
			printf("0\n");
			continue;
		}
		if(p==q || !p) {
			printf("-1\n");
			continue;
		}
		ll lo = 1, hi = 1e9;
		while(lo<hi){
			ll mid = (lo+hi)>>1;
			if(possi(p*mid, q*mid)) hi = mid;
			else lo = mid+1;
		}
		printf("%lld\n",q*lo - y);
	}
	return 0;
}
