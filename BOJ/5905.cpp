#include <bits/stdc++.h>
#define pb push_back
#define sz(v) ((int)(v).size())
#define all(v) (v).begin(), (v).end()
#define fastio() ios::sync_with_stdio(0),cin.tie(0)
using namespace std;
typedef long long ll;
const int mod = 1e9+7;
const int inf = 0x3c3c3c3c;
const ll infl = 0x3c3c3c3c3c3c3c3c;

int N, K;
vector<string> strs;
vector<int> cnts;
vector<string> S;
int check[23], incld[23];
int dp[1003][23];
int cntAinB(string& A, string& B){
	int ret = 0;
	for(int i = 0 ; i <= sz(B) - sz(A); i++) {
		int ok = 1;
		for(int j = 0; j < sz(A); j++){
			if(B[i + j] != A[j]) {
				ok = 0;
				break;
			}
		}
		if(ok) ret++;
	}
	return ret;
}
int over[23][23];
int appr[23][23];
int mxOver(string& A, string& B){
	for(int i = 1; i < sz(A); i++){
		int ok = 1;
		for(int j = 0; i + j < sz(A); j++){
			if(A[i + j] != B[j]) {
				ok = 0;
				break;
			}
		}
		if(ok) return sz(A) - i;
	}
	return 0;
}
int calcApp(int a, int b){
	int ov = over[a][b];
	string s = strs[b];
	s = s.substr(0, ov);
	int ret = 0;
	for(int k = 0 ; k < sz(S); k++){
		string p = S[k];
		if(sz(s) < sz(p)) continue;
		for(int i = 0 ; i <= sz(s) - sz(p); i++){
			int ok = 1;
			for(int j = 0 ; j < sz(p); j++){
				if(s[i + j] != s[j]) {
					ok = 0;
					break;
				}
			}
			if(ok) ret++;
		}
	}
	return ret;
}
int main() {
	// fastio();
	cin >> N >> K;
	for(int i = 0 ; i < N; i++) {
		string s;
		cin >> s;
		S.pb(s);
	}
	for(int i = 0 ; i < N; i++){
		for(int j = 0; j < N; j++){
			if(i == j) continue;
			string a = S[i], b = S[j];
			if(sz(a) > sz(b)) continue;
			int ret = cntAinB(a, b);
			if(ret) check[i] = 1, incld[j] += ret;
		}
	}
	for(int i = 0 ; i < N; i++){
		if(!check[i]) strs.pb(S[i]), cnts.pb(incld[i] + 1);
	}
	N = sz(strs);
	for(int i = 0 ; i < N; i++) {
		printf("strs[%d] : ", i);
		cout << strs[i];
		printf(", cnt[%d] : %d\n", i, cnts[i]);
	}
	for(int i = 0 ; i < N; i++){
		for(int j = 0 ; j < N; j++){
			over[i][j] = mxOver(strs[i], strs[j]);
			printf("over[%d][%d] : %d\n", i, j, over[i][j]);
		}
	}
	for(int i = 0 ; i < N; i++){
		for(int j = 0 ; j < N; j++){
			appr[i][j] = calcApp(i, j);
			printf("appr[%d][%d] : %d\n", i, j, appr[i][j]);
		}
	}
	int ans = 0;
	for(int i = 0; i < N; i++) dp[sz(strs[i])][i] = cnts[i];
	// for(int i = 0 ; i < N; i++) dp[0][i] = 1;
	for(int i = 1; i <= K; i++){
		for(int j = 0; j < N; j++){
			for(int k = 0; k < N; k++){
				if(i >= sz(strs[j])) dp[i][j] = max(dp[i][j], dp[i - sz(strs[j]) + over[k][j]][k] + cnts[j] - appr[k][j]);
				ans = max(ans, dp[i][j]);
				printf("dp[%d][%d] : %d\n", i, j, dp[i][j]);
			}
		}
	}

	cout << ans;
	return 0;
}