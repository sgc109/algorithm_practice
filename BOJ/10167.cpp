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
int N;
vector<int> vY;
struct Mine{
	int x, y, w;
};
ll tsum[9003], tlmax[9003], trmax[9003], tmax[9003];
void update(int nl, int nr, int nd, int pos, int v){
	if(nr < pos || pos < nl) return;
	if(nl == nr && nl == pos){
		tsum[nd] += v;
		tmax[nd] = max(0ll, tsum[nd]);
		trmax[nd] = max(0ll, tsum[nd]);
		tlmax[nd] = max(0ll, tsum[nd]);
		return;
	}
	int nm = (nl + nr) / 2;
	update(nl, nm, 2 * nd, pos, v);
	update(nm + 1, nr, 2 * nd + 1, pos, v);
	tsum[nd] = tsum[2 * nd] + tsum[2 * nd + 1];
	tlmax[nd] = max(tlmax[2 * nd], tsum[2 * nd] + tlmax[2 * nd + 1]);
	trmax[nd] = max(trmax[2 * nd + 1], trmax[2 * nd] + tsum[2 * nd + 1]);
	tmax[nd] = max(tmax[2 * nd], tmax[2 * nd + 1]);
	tmax[nd] = max(tmax[nd], trmax[2 * nd] + tlmax[2 * nd + 1]);
}
bool cmp(Mine& a, Mine& b){
	return a.x < b.x;
}
Mine mines[3003];
int main() {
	fastio();
	cin >> N;
	for(int i = 0 ; i < N; i++){
		int x, y, w;
		cin >> x >> y >> w;
		mines[i] = Mine{x, y, w};
		vY.pb(y);
	}
	sort(all(vY));
	vY.erase(unique(all(vY)), vY.end());
	for(int i = 0 ; i < N; i++){
		mines[i].y = lower_bound(all(vY), mines[i].y) - vY.begin();
	}
	sort(mines, mines + N, cmp);
	ll ans = 0;
	for(int i = 0 ; i < N; i++){
		if(i && mines[i - 1].x == mines[i].x) continue;
		memset(tsum,0,sizeof(tsum));
		memset(tmax,0,sizeof(tmax));
		memset(tlmax,0,sizeof(tlmax));
		memset(trmax,0,sizeof(trmax));
		for(int j = i ; j < N; j++){
			update(0, N - 1, 1, mines[j].y, mines[j].w);
			if(j == N - 1 || mines[j].x != mines[j + 1].x) {
				ans = max(ans, tmax[1]);
			}
		}
	}

	cout << ans;
	return 0;
}