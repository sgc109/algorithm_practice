#include <bits/stdc++.h>
#define pb push_back
#define sz(v) ((int)(v).size())
#define all(v) (v).begin(), (v).end()
#define fastio() ios::sync_with_stdio(0),cin.tie(0)
using namespace std;
typedef long long ll;
const int mod = 1e9+7;
const int inf = 0x3c3c3c3c;
const ll infl = 0x3c3c3c3c3c3c3c3c;
int T, N, P;
vector<pair<int,int> > G[100003];
ll dist1[100003], dist2[100003];
pair<int,int> par[100003];
ll far[100003];
ll mxD, mx;
ll mnD, mn;
void bfs(int s, ll* d){
	memset(d,0x3c,100003 * sizeof(d));
	d[s] = 0;
	queue<pair<int,int> > q;
	q.push({s, -1});
	while(!q.empty()){
		int cur = q.front().first;
		int dad = q.front().second;
		q.pop();
		if(d[cur] > mxD) mxD = d[cur], mx = cur;
		ll r = max(dist1[cur], d[cur]);
		if(mnD > r) mnD = r, mn = cur;
		for(auto p : G[cur]){
			int nxt = p.first;
			int cst = p.second;
			if(nxt == dad) continue;
			d[nxt] = d[cur] + cst;
			q.push({nxt, cur});
		}
	}
}
int findEnd(int s, ll* d){
	mxD = -1;
	bfs(s, d);
	return mx;
}
int main() {
	fastio();
	cin >> T;
	for(int t = 1; t <= T; t++){
		for(int i = 0; i < 100003; i++) G[i].clear();
		cin >> N;
		for(int i = 0; i < N - 1; i++){
			int a, b, w;
			cin >> a >> b >> w;
			a--, b--;
			G[a].pb({b, w});
			G[b].pb({a, w});
		}
		cin >> P;
		int e1 = findEnd(0, dist1);
		int e2 = findEnd(e1, dist1);
		mnD = infl;
		bfs(e2, dist2);
		int cen = mn;
		vector<int> v;
		queue<pair<int,int> > q;
		q.push({cen, -1});
		while(!q.empty()){
			int cur = q.front().first;
			int dad = q.front().second;
			q.pop();
			v.pb(cur);
			for(auto p : G[cur]){
				int nxt = p.first;
				int cst = p.second;
				if(nxt == dad) continue;
				q.push({nxt, cur});
				par[nxt] = {cur, cst};
			}
		}
		reverse(all(v));
		memset(far,0,sizeof(far));
		for(int cur : v){
			if(cur == cen) continue;
			int dad = par[cur].first;
			int cst = par[cur].second;
			far[cur] += cst;
			far[dad] = max(far[dad], far[cur]);
		}
		far[cen] = 0;
		vector<ll> ds;
		for(int i = 0 ; i < N; i++) ds.pb(far[i]);
		sort(all(ds));
		cout << "Case #" << t << '\n';
		cout << ds[N - P] << '\n';

	}
	return 0;
}