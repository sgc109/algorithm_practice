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

int tree[300003];
int tot;
vector<int> idxs[300003];
int last, cnt, minu;
int N, Q;
void update(int x, int v){
	while(x <= 300000){
		tree[x] += v;
		x += x & -x;
	}
}
int query(int x, int ret = 0){
	while(x > 0){
		ret += tree[x];
		x -= x & -x;
	}
	return ret;
}
int main() {
	fastio();
	cin >> N >> Q;
	while(Q--){
		int typ, id, t;
		cin >> typ;
		if(typ == 1){
			cin >> id;
			update(++cnt, 1);
			idxs[id].pb(cnt);
			tot++;
		}
		else if(typ == 2){
			cin >> id;
			for(int idx : idxs[id]) if(last < idx) update(idx, -1), tot--;
			idxs[id].clear();
		}
		else {
			cin >> t;
			if(last < t) {
				minu += (query(t) - query(last));
				last = t;
			}
		}
		cout << tot - minu << '\n';
	}
	return 0;
}