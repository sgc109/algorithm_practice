#include <bits/stdc++.h>
#define pb push_back
#define sz(v) ((int)(v).siz())
#define all(v) (v).begin(), (v).end()
#define fastio() ios_base::sync_with_stdio(false),cin.tie(NULL)
using namespace std;
typedef long long ll;
const int mod = 1e9 + 7;
const int inf = 0x3c3c3c3c;
const long long infl = 0x3c3c3c3c3c3c3c3c;

int N, M, T;
int enemy[10003];
int par[10003];
int siz[10003];
int check[10003];
int find(int a) {
	return par[a] == a ? a : par[a] = find(par[a]);
}
int merge(int a, int b) {
	if (a > b) swap(a, b);
	if (a == -1 || b == -1) return max(a, b);
	if (a == b) return a;
	par[a] = b;
	siz[b] += siz[a];
	return b;
}
int main() {
	fastio();
	cin >> T;
	for (int t = 0; t < T; t++) {
		memset(check,0,sizeof(check));
		memset(enemy,-1,sizeof(enemy));
		cin >> N >> M;
		for (int i = 0; i < N; i++) par[i] = i, siz[i] = 1;
		int ok = 1;
		int first = inf;
		for(int i = 1 ; i <= M; i++) {
			string a;
			int b, c;
			cin >> a >> b >> c;
			if (!ok) continue;
			b = find(b), c = find(c);
			if (a == "ACK") {
				if (enemy[b] == c) {
					ok = 0;
					first = i;
					continue;
				}
				int bb = enemy[b], cc = enemy[c];
				int bc = merge(b, c);
				int bbcc = merge(bb, cc);
				enemy[bc] = bbcc, enemy[bbcc] = bc;
			}
			else {
				if (b == c) {
					ok = 0;
					first = i;
					continue;
				}
				int bc1 = merge(enemy[b], c);
				int bc2 = merge(enemy[c], b);
				enemy[bc1] = bc2, enemy[bc2] = bc1;
			}
		}
		if (!ok) {
			cout << "CONTRADICTION AT " << first << '\n';
			continue;
		}
		int ans = 0;
		for(int i = 0 ; i < N; i++){
			int num = find(i);
			if(check[num]) continue;
			check[num] = 1;
			if(enemy[num] != -1) check[enemy[num]] = 1;
			ans += max(siz[num], enemy[num] == -1 ? 0 : siz[enemy[num]]);
		}
		cout << "MAX PARTY SIZE IS " << ans << '\n';
	}
	return 0;
}
