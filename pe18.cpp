#include <bits/stdc++.h>
#define pb push_back
#define sz(v) ((int)(v).size())
#define all(v) (v).begin(), (v).end()
using namespace std;
typedef long long ll;
const int mod = 1e9+7;
const int inf = 0x3c3c3c3c;
const long long infl = 0x3c3c3c3c3c3c3c3c;

string s;
vector<int> pane[100];
int N;
int stoi(string& s){
	int ret = 0;
	for(int i = 0 ; i < sz(s); i++) ret = 10 * ret + s[i] - '0';
	return ret;
}

ll dp[100][100];
int main() {
	for(int i = 0; getline(cin, s); i++){
		stringstream ss(s);
		string s2;
		while(getline(ss, s2, ' ')){
			pane[i].pb(stoi(s2));
		}
		N = i;
	}
	N++;
	dp[0][0] = pane[0][0];
	for(int i = 1; i < N; i++){
		for(int j = 0 ; j < sz(pane[i]); j++){
			dp[i][j] = max(j ? dp[i - 1][j - 1] : 0, i != j ? dp[i - 1][j] : 0) + pane[i][j];
		}
	}

	ll ans = 0;
	for(int i = 0 ; i < sz(pane[N - 1]); i++) ans = max(ans, dp[N - 1][i]);
	cout << ans;
	return 0;
}