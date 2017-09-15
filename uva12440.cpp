#include <bits/stdc++.h>
#define pb push_back
#define sz(v) ((int)(v).size())
#define all(v) (v).begin(), (v).end()
#define fastio() ios_base::sync_with_stdio(false),cin.tie(NULL)
using namespace std;
typedef long long ll;
const int mod = 1e9+7;
const int inf = 0x3c3c3c3c;
const long long infl = 0x3c3c3c3c3c3c3c3c;

int T, N, size;
ll dp[100003];
ll tr2[400003], tr1[400003];
ll lazy[400003];
int typ[100003], h[100003];
void init(){
	for(int i = 0 ; i < N; i++) tr1[i + size] = h[i];
	for(int i = size - 1; i >= 1; i--) tr1[i] = max(tr1[2 * i], tr1[2 * i + 1]);
	int lo = 0, hi = 0;
	while(hi < N){
		cnt[typ[hi]]++;
		while(cnt[typ[hi]] > 1) cnt[typ[lo++]]--;
		if(cnt[typ[hi]] == 1) l[hi] = lo;
		l[hi++] = lo;
	}
}
int qry(int l, int r){
	int ret = -1;
	for(l += size, r += size; l <= r; l /= 2, r /=2){
		if(l & 1) ret = max(ret, tr1[l++]);
		if(~r & 1) ret = max(ret, tr1[r--]);
	}
	return ret;
}

int query(int l, int r, int nl, int nr, int node){
	if(lazy[node] != -1){
		qry()
	}
}
void update(int l, int r, int nl, int nr, int node, int idx){

}
int main() {
	// freopen("output.txt","w",stdout);
	// fastio();
	cin >> T;
	for(int t = 1; t <= T; t++){
		memset(dp,0,sizeof(dp));
		memset(tr1,0,sizeof(tr1));
		memset(lazy,-1,sizeof(lazy));
		cin >> N;
		for(size = 1; size <= N; size *= 2);
		for(int i = 0 ; i < N; i++) cin >> typ[i] >> h[i];
		init();
		for(int i = 1 ; i < N; i++){
			
		}
		// cout << "Case " << t << ": " << dp[N] << '\n';
	}
	return 0;
}