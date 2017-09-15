#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod = 1e9+7;
const int inf = 0x3c3c3c3c;
const long long infl = 0x3c3c3c3c3c3c3c3c;

int N;
ll L;
int s[100003], e[100003];
int mlow,Mlow;
int mhigh,Mhigh;
int low,high;
int main() {
	mlow = Mlow = inf;
	mhigh = Mhigh = -1;
	scanf("%d%lld",&N,&L);
	for(int i = 0 ; i < N; i++){
		int a,b;
		scanf("%d%d",&a,&b);
		s[i] = a;
		e[i] = b;
		mlow = min(mlow, s[i]);
		Mlow = min(Mlow, e[i]);
		mhigh = max(mhigh, s[i]);
		Mhigh = max(Mhigh, e[i]);
	}

	int lo = mlow, hi = Mlow+1;
	while(lo<hi){
		int mid = (lo+hi)>>1;
		ll sum = 0;
		for(int i = 0 ; i < N; i++) sum += max(mid, s[i]);
		if(L < sum) hi = mid;
		else lo = mid+1;
	}
	lo--;
	low = lo;

	lo = mhigh, hi = Mhigh+1;
	while(lo<hi){
		int mid = (lo+hi)>>1;
		ll sum = 0;
		for(int i = 0 ; i < N; i++) sum += min(mid,e[i]);
		if(L > sum) lo = mid+1;
		else hi = mid;
	}
	high = hi;
	printf("%d",high-low);

	return 0;
}
