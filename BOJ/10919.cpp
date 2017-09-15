#include <bits/stdc++.h>
#define pb push_back
#define sz(v) ((int)(v).size())
#define all(v) (v).begin(), (v).end()
#define fastio() ios_base::sync_with_stdio(0),cin.tie(0)
using namespace std;
typedef long long ll;
const int MOD = 1e9+7;
const int INF = 0x3c3c3c3c;
const long long INFL = 0x3c3c3c3c3c3c3c3c;
const int MAXN = 1e7;

static char _buffer[131072];
static int _currentChar = 0;
static int _charsNumber = 0;
   
static inline int _read() {
    if (_currentChar == 131072) {
        _charsNumber = fread(_buffer, 1, 131072, stdin);
        _currentChar = 0;
    }
    return _buffer[_currentChar++];
}
   
int c, x;
   
static inline int _readInt() {
	bool minus = false;
    c = _read();
    while (c <= 32) c = _read();
    x = 0;
    while (c > 32) {
    	if(c == '-') minus = true;
        else {
        	x *= 10;
        	x += c - '0';
    	}
        c = _read();
    }
    if(minus) x = -x;
    return x;
}


vector<ll> pos;
ll posL[MAXN], posR[MAXN];
int N, K, L;
int main() {
	N = _readInt();
	K = _readInt();
	L = _readInt();
	pos.resize(N);
	for(int i = 0 ; i < N; i++) pos[i] = _readInt();
	
	auto s = upper_bound(all(pos), 0) - pos.begin();
	auto m = upper_bound(all(pos), L / 2) - pos.begin();
	
	vector<ll> ss = vector<ll>(s, m);
	vector<ll> ee = vector<ll>(m, pos.end());
	
	reverse(all(ee));
	for(int i = 0 ; i < sz(ee); i++) ee[i] = L - ee[i];
	
	for(int i = 0 ; i < sz(ss) && i < K; i++) posL[i] = ss[i] * 2;
	for(int i = 0 ; i < sz(ee) && i < K; i++) posR[i] = ee[i] * 2;
	for(int i = K ; i < sz(ss); i++) posL[i] = posL[i - K] + ss[i] * 2;
	for(int i = K ; i < sz(ee); i++) posR[i] = posR[i - K] + ee[i] * 2;

	ll ans = posL[sz(ss) - 1] + posR[sz(ee) - 1];

	for(int i = 0 ; i <= K; i++) {
		ll l = i >= sz(ss) ? 0 : posL[sz(ss) - 1 - i];
		ll r = K - i >= sz(ee) ? 0 : posR[sz(ee) - 1 - (K - i)];
		ans = min(ans, l + r + L);
	}

	cout << ans;

	return 0;
}