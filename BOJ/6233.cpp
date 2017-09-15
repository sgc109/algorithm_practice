#include <bits/stdc++.h>
#define pb push_back
#define sz(v) ((int)(v).size())
#define all(v) (v).begin(), (v).end()
using namespace std;
typedef long long ll;
const int mod = 1e9+7;
const int inf = 0x3c3c3c3c;
const long long infl = 0x3c3c3c3c3c3c3c3c;
int C, K, N;
int state[5003], psum[5003];
int main() {
	scanf("%d\n", &N);
	for(int i = 1; i <= N; i++) {
		char c;
		scanf("%c\n", &c);
		state[i] = c == 'F' ? 0 : 1;
	}
	C = inf;
	for(int len = 1; len <= N; len++){
		int cnt = 0, ok = 1;
		memset(psum,0,sizeof(psum));
		for(int i = 1; i + len <= N + 1; i++){
			int s = psum[i - 1] ^ psum[max(0, i - len)];
			int p = state[i] ^ s;
			psum[i] = psum[i - 1];
			if(!p) continue;
			psum[i] ^= 1;
			cnt++;
		}
		for(int i = N - len + 2; i <= N; i++) {
			psum[i] = psum[i - 1];
			int s = psum[i - 1] ^ psum[max(0, i - len)];
			if(state[i] ^ s) ok = 0;
		}
		if(ok){
			if(C > cnt){
				C = cnt;
				K = len;
			}
		}
	}

	printf("%d %d", K, C);
	return 0;
}