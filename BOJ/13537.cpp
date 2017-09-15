#include <bits/stdc++.h>
#define pb push_back
#define sz(v) ((int)(v).size())
#define all(v) (v).begin(), (v).end()
#define fastio() ios_base::sync_with_stdio(false),cin.tie(NULL)
using namespace std;
typedef long long ll;
const int mod = 1e9+7;
const int inf = 0x3c3c3c3c;
const ll infl = 0x3c3c3c3c3c3c3c3c;

int N, M;
int tr[100003];
void update(int x, int val){
	while(x <= N){
		tr[x] += val;
		x += x & -x;
	}
}
int query(int x, int ret = 0){
	while(x > 0){
		ret += tr[x];
		x -= x & -x;
	}
	return ret;
}
vector<pair<int,int> > vals;
vector<pair<pair<int,int> ,pair<int,int> > > qurs;
int ans[100003];
int main() {
	fastio();
	cin >> N;
	for(int i = 0 ; i < N; i++) {
		int a;
		cin >> a;
		vals.pb({-a, i});
	}
	cin >> M;
	for(int i = 0 ; i < M; i++){
		int l, r, k;
		cin >> l >> r >> k;
		l--, r--;
		qurs.pb({{-k, i}, {l, r}});
	}
	sort(all(vals));
	sort(all(qurs));
	int pos1 = 0, pos2 = 0;
	while(pos1 < N && pos2 < M){
		auto p1 = vals[pos1];
		auto p2 = qurs[pos2];
		int v1 = -p1.first;
		int v2 = -p2.first.first;
		if(v1 > v2){
			update(p1.second + 1, 1);
			pos1++;
		}
		else {
			ans[p2.first.second] = query(p2.second.second + 1) - query(p2.second.first);
			pos2++;
		}
	}
	while(pos2 < M) {
		auto p2 = qurs[pos2];
		ans[p2.first.second] = query(p2.second.second + 1) - query(p2.second.first);
		pos2++;
	}

	for(int i = 0 ; i < M; i++) cout << ans[i] << '\n';
	return 0;
}