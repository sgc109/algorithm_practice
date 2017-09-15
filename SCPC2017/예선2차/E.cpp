#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod = 1e9+7;
const int INF = 0x3c3c3c3c;
const long long INFL = 0x3c3c3c3c3c3c3c3c;
const int MAXN = 5000;
struct Stick{int l,r,w;};
int T,N;
Stick sticks[MAXN+3];
vector<int> G[MAXN+3];
int sel[MAXN+3];
ll dp[MAXN+3][MAXN+3];
bool cmp(Stick& a, Stick& b){
	if(a.l == b.l) return a.r < b.r;
	return a.l < b.l;
}
ll go(int pos, int last){
	if(pos == N) return 0;
	ll& cache = dp[pos][last];
	if(sticks[pos].l <= last) return cache = go(pos + 1, last);
	return cache = go(pos + 1, sticks[pos].r) + sticks[pos].w;
}
set<int> st;
int main() {
	setbuf(stdout, NULL);
	scanf("%d", &T);
	for(register int t = 1; t <= T; t++){
		st.clear();
		for(int i = 0 ; i < MAXN+3; i++) G[i].clear();
		scanf("%d", &N);
		for(register int i = 0 ; i < N; i++) {
			int a,b,c;
			scanf("%d%d%d",&a,&b,&c);
			sticks[i] = Stick{a,b,c};
			st.insert(a);
			st.insert(b);
		}

		vector<int> sorted(st.begin(), st.end());
		for(int i = 0 ; i < N; i++){
			sticks[i].l = lower_bound(sorted.begin(), sorted.end(), sticks[i].l) - sorted.begin();
			sticks[i].r = lower_bound(sorted.begin(), sorted.end(), sticks[i].r) - sorted.begin();
		}
		
		sort(sticks, sticks + N, cmp);
		ll ans = go(0, -1);
		printf("Case #%d\n", t);
		printf("%lld\n", ans);
	}
	return 0;
}