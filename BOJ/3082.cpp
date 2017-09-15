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

int R, C, P;
int pane[1003][1003];
int vis[1003][1003];
int tim;
ll h;
bool inRange(int i, int j){
	return 0 <= i && i < R && 0 <= j && j < C;
}
void dfs(int curI, int curJ){
	for(int k = 0 ; k < 4; k++){
		int ni = curI + "2110"[k] - '1';
		int nj = curJ + "1201"[k] - '1';
		if(!inRange(ni, nj) || vis[ni][nj] || pane[ni][nj] <= tim) continue;
		vis[ni][nj] = 1;
		h = 4 * h + k;
		dfs(ni, nj);
	}
}
int main() {
	fastio();
	cin >> R >> C;
	for(int i = 0; i < R; i++) {
		for(int j = 0 ; j < C; j++){
			cin >> pane[i][j];
		}
	}
	cin >> P;
	for(int k = 0 ; k < P; k++){
		memset(vis,0,sizeof(vis));
		cin >> tim;
		vector<ll> hs;
		for(int i = 0 ; i < R; i++){
			for(int j = 0 ; j < C; j++){
				if(vis[i][j] || pane[i][j] <= tim) continue;
				h = 0;
				dfs(i, j);
				hs.pb(h);
			}
		}
		sort(all(hs));
		ll ans = 0;
		int cnt = 1;
		ll prv = hs[0];
		for(int i = 1 ; i < sz(hs); i++) {
			if(prv != hs[i]){
				ans += cnt * (cnt - 1) / 2;
				prv = hs[i];
				cnt = 1;
			}
			else cnt++;
		}
		ans += cnt * (cnt - 1) / 2;
		cout << ans << '\n';
	}
	return 0;
}