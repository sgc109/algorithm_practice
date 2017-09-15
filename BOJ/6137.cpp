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
int N;
char c;
string S, T;
int main() {
	fastio();
	cin >> N;
	for(int i = 0 ; i < N; i++) {
		cin >> c;
		S += c;
	}
	while(sz(S)){
		string rev = S;
		reverse(all(rev));
		if(S < rev) {
			T += S[0];
			S = S.substr(1, sz(S) - 1);
		}
		else {
			T += S.back();
			S.pop_back();
		}
	}

	for(int i = 1 ; i <= N; i++){
		cout << T[i-1];
		if(i % 80 == 0) cout << endl;
	}
	return 0;
}