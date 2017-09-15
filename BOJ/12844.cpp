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

int N, M;
int t[1500003];
int lazy[1500003];
int A[500003];
void init(){
	for(int i = N - 1; i > 0; i--){
		t[i] = t[2 * i] ^ t[2 * i + 1];
	}
}
void update(int s, int e, int nl, int nr, int nd, int val){
	if(lazy[nd]){
		if(~(nr - nl) & 1) t[nd] ^= lazy[nd];
		if(nl != nr) lazy[2 * nd] ^= lazy[nd], lazy[2 * nd + 1] ^= lazy[nd];
		lazy[nd] = 0;
	}
	if(s <= nl && nr <= e){
		if(~(nr - nl) & 1) t[nd] ^= val;
		if(nl != nr) lazy[2 * nd] ^= val, lazy[2 * nd + 1] ^= val;
		return;
	}
	if(e < nl || nr < s) return;
	int nm = (nl + nr) / 2;
	update(s, e, nl, nm, 2 * nd, val);
	update(s, e, nm + 1, nr, 2 * nd + 1, val);
	t[nd] = t[2 * nd] ^ t[2 * nd + 1];
}
int query(int s, int e, int nl, int nr, int nd){
	if(lazy[nd]){
		if(~(nr - nl) & 1) t[nd] ^= lazy[nd];
		if(nl != nr) lazy[2 * nd] ^= lazy[nd], lazy[2 * nd + 1] ^= lazy[nd];
		lazy[nd] = 0;
	}
	if(s <= nl && nr <= e) return t[nd];
	if(nr < s || e < nl) return 0;
	int nm = (nl + nr) / 2;
	return query(s, e, nl, nm, 2 * nd) ^ query(s, e, nm + 1, nr, 2 * nd + 1);
}
int main() {
	fastio();
	cin >> N;
	for(int i = 0 ; i < N; i++) cin >> A[i];
	int size;
	for(size = 1; size <= N; size *= 2);
	for(int i = 0 ; i < N; i++) t[size + i] = A[i];
	N = size;
	init();
	cin >> M;
	for(int i = 0 ; i < M; i++){
		int o, a, b, c;
		cin >> o;
		if(o == 1){
			cin >> a >> b >> c;
			if(a > b) swap(a, b);
			update(a, b, 0, N - 1, 1, c);
		}
		else {
			cin >> a >> b;
			if(a > b) swap(a, b);
			cout << query(a, b, 0, N - 1, 1) << '\n';
		}
	}
	return 0;
}