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

int T;
string S;
ll poww[40];
int main() {
	fastio();
	cin >> T;
	for(int t = 1 ; t <= T; t++){
		cin >> S;
		int N = sz(S);
		set<char> st;
		for(int i = 0 ; i < N; i++) st.insert(S[i]);
		int base = sz(st);
		if(base == 1) base++;
		poww[0] = 1;
		for(int i = 1 ; i < 40; i++) poww[i] = poww[i - 1] * base;
		ll ans = 0;
		map<char, int> mp;
		mp[S[0]] = 1;
		for(int i = 0 ; i < N; i++) {
			if(mp[S[i]]) continue;
			mp[S[i]] = -1;
			break;
		}
		int cnt = 2;
		for(int i = 0 ; i < N; i++){
			char c = S[i];
			int& cst = mp[c];
			if(!cst) cst = cnt++;
			ans += (cst == -1 ? 0 : cst) * poww[N - 1 - i];
		}
		cout << "Case #" << t << ": ";
		cout << ans << '\n';
	}
	return 0;
}