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

int N, T, C;
int h[40];
int next(int pos, int dir){
	int ret = pos + dir;
	if(ret == N) return 0;
	if(ret == -1) return N - 1;
	return ret;
}
int main() {
	fastio();
	cin >> T;
	while(T--){
		cin >> N >> C;
		for(int i = 0 ; i < N; i++) cin >> h[i];
		int dir = 1;
		int pos = 0;
		int cnt = 0;
		int last = 0;
		while(cnt < N + 5){
			h[pos] = max(h[pos] - C, 0);
			cnt++;
			last = pos;
			if(!h[pos]) dir = -dir;
			int done = 1;
			for(int i = 0 ; i < N; i++) if(h[i]) done = 0;
			if(done) break;
			while(1) {
				pos = next(pos, dir);
				if(h[pos]) break;
			}
		}
		cout << last + 1 << '\n';
	}
	return 0;
}