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

struct Seg{
	int l, par, r;
};
int M;
Seg tree[3000003];
string S;
void init(int nl, int nr, int nd){
	if(nl == nr) {
		char c = S[nl];
		tree[nd] = Seg{c == '(', 0, c == ')'};
		return;
	}
	int nm = nl + nr >> 1;
	init(nl, nm, 2 * nd);
	init(nm + 1, nr, 2 * nd + 1);
	auto nodeL = tree[2 * nd];
	auto nodeR = tree[2 * nd + 1];
	int add = min(nodeL.l, nodeR.r);
	tree[nd] = Seg{nodeL.l + nodeR.l - add, nodeL.par + nodeR.par + add, nodeL.r + nodeR.r - add};
}
Seg query(int l, int r, int nl, int nr, int nd){
	if(l <= nl && nr <= r) return tree[nd];
	if(r < nl || nr < l) return Seg{0, 0, 0};
	int nm = nl + nr >> 1;
	auto qL = query(l, r, nl, nm, 2 * nd);
	auto qR = query(l, r, nm + 1, nr, 2 * nd + 1);
	int add = min(qL.l, qR.r);
	return Seg{qL.l + qR.l - add, qL.par + qR.par + add, qL.r + qR.r - add};
}
int main() {
	fastio();
	cin >> S >> M;
	init(0, sz(S) - 1, 1);
	while(M--){
		int l, r;
		cin >> l >> r;
		l--, r--;
		auto ret = query(l, r, 0, sz(S) - 1, 1);
		cout << ret.par * 2 << '\n';
	}
	return 0;
}