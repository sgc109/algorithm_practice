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

int T, N, M;
int s[3], t[3];
vector<pair<int,int> > G[105];
ll dp[103][103][103];
ll go(int pos1, int pos2, int pos3){
	assert(pos1 != pos2 && pos2 != pos3 && pos3 != pos1);
	if(pos1 == t[0] && pos2 == t[1] && pos3 == t[2]) return 0;
	ll& cache = dp[pos1][pos2][pos3];
	if(cache != -1) return cache;
	ll ret = -infl;
	if((pos2 == t[1] || pos2 > pos1) && (pos3 == t[2] || pos3 > pos1)) {
		for(auto p : G[pos1]){
			int nxt = p.first;
			int cst = p.second;
			if(nxt == pos2 || nxt == pos3) continue;
			ret = max(ret, cst + go(nxt, pos2, pos3));
		}
	}
	if((pos1 == t[0] || pos1 > pos2) && (pos3 == t[2] || pos3 > pos2)) {
		for(auto p : G[pos2]){
			int nxt = p.first;
			int cst = p.second;
			if(nxt == pos1 || nxt == pos3) continue;
			ret = max(ret, cst + go(pos1, nxt, pos3));		
		}
	}
	if((pos1 == t[0] || pos1 > pos3) && (pos2 == t[1] || pos2 > pos3)) {
		for(auto p : G[pos3]){
			int nxt = p.first;
			int cst = p.second;
			if(nxt == pos1 || nxt == pos2) continue;
			ret = max(ret, cst + go(pos1, pos2, nxt));		
		}
	}
	return cache = ret;
}
int main() {
	fastio();
	cin >> T;
	while(T--){
		for(int i = 0 ; i < 103; i++) G[i].clear();
		memset(dp,-1,sizeof(dp));
		cin >> N >> M;
		for(int i = 0 ; i < 3; i++) cin >> s[i];
		for(int i = 0 ; i < 3; i++) cin >> t[i];
		for(int i = 0 ; i < M; i++){
			int a, b, c;
			cin >> a >> b >> c;
			G[a].emplace_back(b, c);
		}
		ll ans = go(s[0], s[1], s[2]);
		if(ans < 0) ans = 0;
		cout << ans << '\n';
	}		
	return 0;
}