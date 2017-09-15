#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod = 1e9+7;
const int inf = 0x3c3c3c3c;
const long long infl = 0x3c3c3c3c3c3c3c3c;

int T,N;
int tOdd[800003], tEven[800003];
int cost[200003];
int size;
vector<int> v;
void update(int pos, int val, int *t){
	pos+=size;
	for(t[pos] = max(t[pos], val); pos > 1; pos/=2){
		t[pos/2] = max(t[pos], t[pos^1]);
	}
}
int query(int l, int r, int *t){
	int ret = 0;
	for(l+=size, r+=size; l <= r; l/=2, r/=2){
		if(l&1) ret = max(ret, t[l++]);
		if(~r&1) ret = max(ret, t[r--]);
	}
	return ret;
}
int main() {
	setbuf(stdout,NULL);
	size = 262144;
	scanf("%d",&T);
	for(register int t = 1; t <= T; t++){
		memset(tOdd,0,sizeof(tOdd));
		memset(tEven,0,sizeof(tEven));
		v.clear();
		scanf("%d",&N);
		for(register int i = 0 ; i < N; i++) scanf("%d",cost+i);
		for(register int i = 0 ; i < N; i++) v.push_back(cost[i]);
		sort(v.begin(), v.end());
		for(register int i = 0 ; i < N; i++) cost[i] = lower_bound(v.begin(), v.end(), cost[i]) - v.begin() + 1;
		int ans = 0;
		for(register int i = 0 ; i < N; i++){
			int buyMax = query(cost[i]+1, N+1, tEven);
			update(cost[i], buyMax+1, tOdd);
			int sellMax = query(0, cost[i]-1, tOdd);
			if(sellMax%2==0) continue;
			update(cost[i], sellMax+1, tEven);
			ans = max(ans, sellMax+1);
		}
		printf("Case #%d\n%d\n",t,ans);
	}	
	return 0;
}