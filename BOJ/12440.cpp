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
int tree[400003];
int typ[100003];
int h[100003];
int l[100003];
int cnt[100003];
ll dp[100003];
void init(){
	for(int i = 0 ; i < N; i++) tree[i + size] = h[i];
	for(int i = size - 1; i >= 1; i--) tree[i] = max(tree[2 * i], tree[2 * i + 1]);
	int lo = 0, hi = 0;
	while(hi < N){
		cnt[typ[hi]]++;
		while(cnt[typ[hi]] > 1) cnt[typ[lo++]]--;
		if(cnt[typ[hi]] == 1) l[hi] = lo;
		l[hi++] = lo;
	}
}
int query(int l, int r){
	int ret = -1;
	for(l += size, r += size; l <= r; l /= 2, r /=2){
		if(l & 1) ret = max(ret, tree[l++]);
		if(~r & 1) ret = max(ret, tree[r--]);
	}
	return ret;
}
ll C(int i, int j){
	return dp[j] + query(j, i);
}
int main() {
	// freopen("output.txt","w",stdout);
	// fastio();
	cin >> T;
	for(int t = 1; t <= T; t++){
		memset(cnt,0,sizeof(cnt));
		memset(dp,0,sizeof(dp));
		memset(tree,0,sizeof(tree));
		cin >> N;
		for(size = 1; size <= N; size *= 2);
		for(int i = 0 ; i < N; i++) cin >> typ[i] >> h[i];
		init();
		deque<int> dq;
		for(int i = 0 ; i < N; i++){
			
		}
		// cout << "Case " << t << ": " << dp[N] << '\n';
	}
	return 0;
}