#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod = 1e9+7;
const int inf = 0x3c3c3c3c;
const long long infl = 0x3c3c3c3c3c3c3c3c;

int N;
ll L;
ll s[100003], e[100003];
int main() {
	scanf("%d%lld",&N,&L);
	for(int i = 0 ; i < N; i++) {
		ll a,b;
		scanf("%lld%lld",&a,&b);
		s[i] = a, e[i] = b;
	}

	ll lo = 0, hi = L+1;
	while(lo<hi){
		ll mid = (lo+hi)>>1;
		ll sum = 0;
		for(int i = 0 ; i < N; i++) {
			if(s[i] <= mid && mid <= e[i]) sum += mid;
			else if(e[i] < mid) sum += e[i];
			else sum += s[i];
		}
		if(L <= sum) hi = mid;
		else lo = mid+1;
	}
	int cnt = 0;
	ll msum = 0;
	ll anshi = -1, anslo = infl;
	for(int i = 0 ; i < N; i++){
		if(e[i] < lo) {
			msum += e[i];
			anslo = min(anslo, e[i]);
		}
		else if(lo < s[i]) {
			msum += s[i];
			anshi = max(anshi, s[i]);
		}
		else cnt++;
	}
	L -= msum;
	if(L%cnt==0) {
		anshi = max(anshi, L/cnt);
		anslo = min(anslo, L/cnt);	
	}
	else {
		anshi = max(anshi, (L+cnt-1)/cnt);
		anslo = min(anslo, L/cnt);
	}
	printf("%lld\n",anshi-anslo);
	return 0;
}
