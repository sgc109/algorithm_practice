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

int R, C;
vector<vector<char> > bgn, cur, nxt;
int tim[103][103];
int vis[103][103];
int cnt[103][103];
bool inRange(int i, int j){
	return 0 <= i && i < R && 0 <= j && j < C;
}
int dfs(int ci, int cj, int t){
	if(vis[ci][cj]) return 0;
	if(cur[ci][cj] == '1') {
		cnt[ci][cj]++;
		if(cnt[ci][cj] >= 2) vis[ci][cj] = 1, nxt[ci][cj] = '0';
		tim[ci][cj] = t;
		return 1;
	}
	vis[ci][cj] = 1;
	int ret = 0;
	for(int k = 0 ; k < 4; k++){
		int ni = ci + "2110"[k] - '1';
		int nj = cj + "1201"[k] - '1';
		if(!inRange(ni, nj)) continue;
		ret += dfs(ni, nj, t);
	}
	return ret;
}
int main() {
	fastio();
	cin >> R >> C;
	bgn = vector<vector<char> >(R, vector<char>(C));
	cur = vector<vector<char> >(R, vector<char>(C));
	nxt = vector<vector<char> >(R, vector<char>(C));
	for(int i = 0 ; i < R; i++) {
		for(int j = 0 ; j < C; j++){
			cin >> bgn[i][j];
		}
	}
	cur = bgn;
	int t;
	for(t = 1; ; t++){
		memset(vis,0,sizeof(vis));
		memset(cnt,0,sizeof(cnt));
		nxt = cur;
		int ret = dfs(0, 0, t);
		if(!ret) break;
		cur = nxt;
	}
	int ans = t - 1;
	cout << ans;
	return 0;
}