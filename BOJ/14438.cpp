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

int N, M, size;
int t[300003];
void update(int pos, int v){
	for(t[pos += size] = v; pos > 1; pos /= 2){
		t[pos / 2] = min(t[pos], t[pos ^ 1]);
	}
}
int query(int l, int r, int ret = inf){
	for(l += size, r += size; l <= r; l /= 2, r /= 2){
		if(l & 1) ret = min(ret, t[l++]);
		if(~r & 1) ret = min(ret, t[r--]);
	}
	return ret;
}
int main() {
	fastio();
	memset(t,0x3c,sizeof(t));
	cin >> N;
	for(size = 1; size <= N; size *= 2);
	for(int i = 0 ; i < N; i++){
		cin >> t[size + i];
	}
	for(int i = size - 1; i > 0; i--) {
		t[i] = min(t[2 * i], t[2 * i + 1]);
	}
	cin >> M;
	while(M--){
		int a, b, c;
		cin >> a >> b >> c;
		if(a == 1) update(b - 1, c);
		else cout << query(b - 1, c - 1) << '\n';
	}
	return 0;
}