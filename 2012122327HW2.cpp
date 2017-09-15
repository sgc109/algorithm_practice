#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod = 1e9+7;
const int inf = 0x3c3c3c3c;
const long long infl = 0x3c3c3c3c3c3c3c3c;

int N;
map<ll,int> mp;
ll tcnt[4000003], tval[4000003];
int size;
ll A[1000003];

void update(int pos, int v, ll *t){
	t[pos+=size] += v;
	for(;pos>1;pos/=2) t[pos/2] = t[pos] + t[pos^1];
}

ll query(int l, int r, ll *t){
	ll ret = 0;
	for(l+=size, r+=size; l<=r; l/=2, r/=2){
		if(l&1) ret += t[l++];
		if(~r&1) ret += t[r--];
	}
	return ret;
}
map<ll,int> cntmp;

int main() {
	size = 1000001;
	scanf("%d",&N);
	for(int i = 0 ; i < N; i++){
		scanf("%lld",&A[i]);
		mp[A[i]]++;
	}
	for(auto it = mp.begin(); it != mp.end(); it++){
		int cnt = (*it).second;
		update(cnt, 1, tcnt);
		update(cnt, cnt, tval);
	}

	ll ans = 0;
	for(int i = 0 ; i < N; i++){
		cntmp[A[i]]++;
		int cnt = cntmp[A[i]];
		int prev = (mp[A[i]]-cnt);
		update(prev+1, -1, tcnt);
		update(prev+1, -(prev+1), tval);
		update(prev, 1, tcnt);
		update(prev, prev, tval);

		ans += (cnt-1)*query(cnt,1000000,tcnt);
		ans += query(0,cnt-1,tval);
	}

	printf("%lld",ans);

	return 0;
}
