#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod = 1e9+7;
const int inf = 0x3c3c3c3c;
const long long infl = 0x3c3c3c3c3c3c3c3c;

int N;
ll L;
ll lo[100003], hi[100003];
vector<pair<ll, ll> > v;
int main() {
	ll anshi=-infl, anslo=infl;
	scanf("%d%lld",&N,&L);
	for(int i = 0 ; i < N; i++){
		scanf("%lld%lld",&lo[i],&hi[i]);
		v.push_back({lo[i],1});
		v.push_back({hi[i],-1});
		L -= lo[i];
		anshi = max(anshi, lo[i]);
	}
	sort(v.begin(), v.end());
	ll cnt=0;
	ll prev = -1;
	for(int i = 0 ; i < v.size(); i++){
		ll pos = v[i].first;
		ll adder = v[i].second;
		if(prev != -1) {
			if(L <= (pos - prev) * cnt) {
				assert(cnt!=0);
				ll maxx = (L+cnt-1) / cnt;
				anshi = max(anshi, prev+maxx);
				anslo = min(anslo, prev+L/cnt);
				break;
			}
			else L -= (pos - prev) * cnt;
		}
		cnt += adder;
		prev = v[i].first;
		if(adder == -1) anslo = min(anslo, pos);
	}
	printf("%lld",anshi-anslo);
	return 0;
}
