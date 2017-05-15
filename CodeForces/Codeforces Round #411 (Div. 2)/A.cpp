#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9+7;
const int INF = 0x3c3c3c3c;
const long long INFL = 0x3c3c3c3c3c3c3c3c;

map<long long, long long> mp;
long long l,r;
int main() {
	scanf("%lld%lld",&l,&r);
	if(r-l > 1000) return !printf("2");
	for(long long i = l; i <= r; i++){
		for(long long j = 2; j * j <= i; j++){
			if(i%j) continue;
			mp[j]++;
			if(j*j != i) mp[i/j]++;
		}
		mp[i]++;
	}
	long long ans;
	long long ansCnt = -1;
	for(auto it = mp.begin(); it != mp.end(); it++){
		if((*it).second > ansCnt){
			ans = (*it).first;
			ansCnt = (*it).second;
		}
	}
	printf("%lld",ans);
	return 0;
}
