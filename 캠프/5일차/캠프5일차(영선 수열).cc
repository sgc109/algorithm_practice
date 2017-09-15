#include <cstdio>
#include <algorithm>
typedef long long ll;
ll K,A,B;
ll go(ll L){
	ll ans=0;
	for(ll i = 2, k = L; k<=B; i*=2,k*=2){
		ll lo = std::max(A,k);
		ll hi = std::min(k+i-1,B);
		if(lo<=hi) ans+=hi-lo+1;
	}
	return ans;
}
int main() {
	scanf("%lld%lld%lld",&K,&A,&B);
	if(!K) return printf("%lld",B-A+1),0;
	if(K%2) return printf("%lld",go(2*K)+(A<=K&&K<=B)),0;
	printf("%lld",go(K));
	return 0;
}
